// Fill out your copyright notice in the Description page of Project Settings.

#include "Canon.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "ProjectilePoolManager.h"
#include "Projectile.h"
#include "ProjectilePoolManagerSubSystem.h"
#include "IDamakeTaker.h"
#include "IScoreCounter.h"
#include <Particles/ParticleSystemComponent.h>
#include <Components/AudioComponent.h>
#include <Camera/CameraShake.h>


ACanon::ACanon(){
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComp;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>("SpawnPoint");
	ProjectileSpawnPoint->SetupAttachment(Mesh);

	ShootEffect = CreateDefaultSubobject<UParticleSystemComponent>("ShootEffect");
	ShootEffect->SetupAttachment(ProjectileSpawnPoint);

    ShootAudioEffect = CreateDefaultSubobject<UAudioComponent>("ShootAudioEffect");
	ShootAudioEffect->SetupAttachment(ProjectileSpawnPoint);

	ElminatedAudioEffect = CreateDefaultSubobject<UAudioComponent>("ElminatedAudioEffect");
	ElminatedAudioEffect->SetupAttachment(ProjectileSpawnPoint);
}

void ACanon::BeginPlay(){
	Super::BeginPlay();
	
	CurrentAmmoCount = AmmoCount;
	CurrentAmmunitionCount = AmmunitionCount;
	bIsReadyToFire = true;
}

void ACanon::EndPlay(EEndPlayReason::Type Reason){
	ReloadTimerHandle.Invalidate();
	CooldownTimerHandle.Invalidate();
	SecondIntervalTimerHandle.Invalidate();

	Super::EndPlay(Reason);
}

void ACanon::Reload(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: Reloaded"));

	if(CurrentAmmunitionCount > AmmoCount)
		CurrentAmmunitionCount -= AmmoCount;
	else if(CurrentAmmunitionCount > 0 && CurrentAmmunitionCount < AmmoCount)
		CurrentAmmunitionCount = AmmoCount - (AmmoCount % CurrentAmmunitionCount);
	else{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Ammo is off"));
		return;
	}

	bIsReadyToFire = true;
	CurrentAmmoCount = AmmoCount;
}

void ACanon::Cooldown(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: Cooldowned"));

	bIsReadyToFire = true;
}

void ACanon::MainShot(){
	bIsReadyToFire = false;
	--CurrentAmmoCount;

	Fire();
}

void ACanon::SecondShot(){
	GEngine->AddOnScreenDebugMessage(-1, 0.5, FColor::Green, TEXT("Fire: Second shot"));

	--CurrentSecondShot;

	if(CurrentSecondShot > 0){
		Fire();

		GetWorld()->GetTimerManager().SetTimer(SecondIntervalTimerHandle, this, &ACanon::SecondShot, SecondIntervalTime, false);
	} else
		return;
}

bool ACanon::IsReadyToFire() const {
	return bIsReadyToFire;
}

void ACanon::OnEmenyElminated(){
	ElminatedAudioEffect->Play();
}

void ACanon::Fire(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Fire: ammunition %d, ammo %d"), CurrentAmmunitionCount, CurrentAmmoCount));

	ShootEffect->ActivateSystem();
	ShootAudioEffect->Play();

	if (GetOwner() && GetOwner() == GetWorld()->GetFirstPlayerController()->GetPawn()){
        if (ShootForceEffect){
            FForceFeedbackParameters ShootForceEffectParams;

            ShootForceEffectParams.bLooping = false;
            ShootForceEffectParams.Tag = "ShootForceEffectParams";

            GetWorld()->GetFirstPlayerController()->ClientPlayForceFeedback(ShootForceEffect, ShootForceEffectParams);
        }

        if (ShootShake)
            GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(ShootShake);
    }

	if (Type == ECannonType::FireProjectile){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: type = projectile"));

		AProjectile* Projectile = GetGameInstance()->GetSubsystem<UProjectilePoolManagerSubSystem>()->GetProjectilePoolManager(ProjectileClass)->GetProjectile();
		if (Projectile){	
			FProjectilePreStartData ProjectileData;

			ProjectileData.Location = ProjectileSpawnPoint->GetComponentLocation();
			ProjectileData.Rotation = ProjectileSpawnPoint->GetComponentRotation();
			ProjectileData.Instigator = GetInstigator();
			ProjectileData.CanonDamage = FireDamage;

			Projectile->OnElminated.AddUObject(this, &ACanon::OnEmenyElminated);

			Projectile->SetMoveRange(FireRange);
			Projectile->Start(ProjectileData);
		}
	}
	else if (Type == ECannonType::FireRay){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: type = trace"));

		FHitResult HitResult;
		FVector StartPoint = ProjectileSpawnPoint->GetComponentLocation();
		FVector EndPoint = StartPoint + ProjectileSpawnPoint->GetForwardVector() * FireRange;

		FCollisionQueryParams TraceSettings = FCollisionQueryParams(FName("FireTrace"), true, this);
		TraceSettings.bTraceComplex = true;
		TraceSettings.bReturnPhysicalMaterial = false;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility, TraceSettings)){
			DrawDebugLine(GetWorld(), StartPoint, HitResult.Location, FColor::Red, false, 5.f, 0, 5);
			
			if (HitResult.Actor.IsValid()){
				IIDamakeTaker* DamagedActor = Cast<IIDamakeTaker>(HitResult.Actor);
				bool bIsDestroyed = false;

				if(DamagedActor){
					FDamageData DamageData;

					DamageData.DamageValue = FireDamage;
					DamageData.Instigator = GetInstigator();
					DamageData.DamageMaker = this;

					bIsDestroyed = DamagedActor->CauseDamage(DamageData);
				}	

				if(bIsDestroyed){
					IIScoreCounter* ScoredActor = Cast<IIScoreCounter>(GetInstigator());

					if(ScoredActor)
						ScoredActor->IncrementScore(1);

					OnEmenyElminated();
				}
			}
		} 
		
		else
			DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Green, false, 5.f, 0, 5);
	}
}

void ACanon::FireMain(){
	if(!bIsReadyToFire){
		return;
	}
	else if(CurrentAmmoCount == 0){
		bIsReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &ACanon::Reload, FireReloadTime, false);
	}
	else{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: Single shot"));

		MainShot();

		GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &ACanon::Cooldown, MainFireCooldownTime, false);
	}
}

void ACanon::FireSecond(){
	if(!bIsReadyToFire)
		return;
	else if(CurrentAmmoCount == 0){
		bIsReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &ACanon::Reload, FireReloadTime, false);
	}
	else{
		bIsReadyToFire = false;
		--CurrentAmmoCount;

		CurrentSecondShot = SecondShotsCount;
		GetWorld()->GetTimerManager().SetTimer(SecondIntervalTimerHandle, this, &ACanon::SecondShot, SecondIntervalTime, false);
		
		GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &ACanon::Cooldown, SecondFireCooldownTime, false);
	}
}

void ACanon::AddAmmo(const int AdditionalAmmoValue){
	if(AdditionalAmmoValue > AmmunitionCount)
		CurrentAmmunitionCount = AmmunitionCount;
	else
		CurrentAmmunitionCount += AdditionalAmmoValue;
}

void ACanon::RestoreAmmo(){
	CurrentAmmunitionCount = AmmunitionCount;
	CurrentAmmoCount = AmmoCount;
}