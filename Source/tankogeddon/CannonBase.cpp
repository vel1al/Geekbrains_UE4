#include "CannonBase.h"

#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include <Particles/ParticleSystemComponent.h>
#include <Components/AudioComponent.h>
#include <Camera/CameraShake.h>
#include "GameFramework/ForceFeedbackEffect.h"

#include "DrawDebugHelpers.h"

#include "ProjectilePoolManager.h"
#include "Projectile.h"
#include "ProjectilePoolManagerSubSystem.h"

#include "DamageTaker.h"
#include "PlayerVechicle.h"
#include "TankPlayerState.h"


ACanonBase::ACanonBase(){
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

void ACanonBase::BeginPlay(){
	Super::BeginPlay();
	
	CurrentAmmoCount = AmmoCount;
	CurrentAmmunitionCount = AmmunitionCount;
	bIsReadyToFire = true;
}

void ACanonBase::EndPlay(EEndPlayReason::Type Reason){
	ReloadTimerHandle.Invalidate();
	CooldownTimerHandle.Invalidate();
	SecondIntervalTimerHandle.Invalidate();

	Super::EndPlay(Reason);
}

void ACanonBase::Reload(){
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

void ACanonBase::Cooldown(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: Cooldowned"));

	bIsReadyToFire = true;
}

void ACanonBase::MainShot(){
	bIsReadyToFire = false;
	--CurrentAmmoCount;

	Fire();
}

void ACanonBase::SecondShot(){
	GEngine->AddOnScreenDebugMessage(-1, 0.5, FColor::Green, TEXT("Fire: Second shot"));

	--CurrentSecondShot;

	if(CurrentSecondShot > 0){
		Fire();

		GetWorld()->GetTimerManager().SetTimer(SecondIntervalTimerHandle, this, &ACanonBase::SecondShot, SecondIntervalTime, false);
	} else
		return;
}

bool ACanonBase::IsReadyToFire() const {
	return bIsReadyToFire;
}

void ACanonBase::Fire(){
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
			ProjectileData.CanonDamage = FireDamage + AdditionDamage;

			Projectile->SetMoveRange(FireRange);
			Projectile->SetPrestartData(ProjectileData);
			
			Projectile->Start();
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
				ADamageTaker* DamagedActor = Cast<ADamageTaker>(HitResult.Actor);
				bool bIsDestroyed = false;

				if(DamagedActor){
					FDamageData DamageData;

					DamageData.DamageValue = FireDamage + AdditionDamage;
					DamageData.Instigator = GetInstigator();
					DamageData.DamageMaker = this;

					bIsDestroyed = DamagedActor->CauseDamage(DamageData);
					
					if (bIsDestroyed){
						APlayerVechicle* ScoredActor = Cast<APlayerVechicle>(GetInstigator());
						if(ScoredActor){
							ATankPlayerState* PlayerState = Cast<ATankPlayerState>(ScoredActor->GetPlayerState());
							if(PlayerState)
								PlayerState->IncrementScore();
						}
						else{
							APlayerVechicle* Player = Cast<APlayerVechicle>(HitResult.GetActor());
							if(Player){
								ATankPlayerState* PlayerState = Cast<ATankPlayerState>(Player->GetPlayerState());
								if(PlayerState)
									PlayerState->PlayerDie();
							}
						}
					}
				}	
			}
		} 
		
		else
			DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Green, false, 5.f, 0, 5);
	}
}

void ACanonBase::FireMain(const float AdditionValue){
	AdditionDamage = AdditionValue;

	if(!bIsReadyToFire){
		return;
	}
	else if(CurrentAmmoCount == 0){
		bIsReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &ACanonBase::Reload, FireReloadTime, false);
	}
	else{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: Single shot"));

		MainShot();

		GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &ACanonBase::Cooldown, MainFireCooldownTime, false);
	}
}

void ACanonBase::FireSecond(const float AdditionValue){
	AdditionDamage = AdditionValue;

	if(!bIsReadyToFire)
		return;
	else if(CurrentAmmoCount == 0){
		bIsReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &ACanonBase::Reload, FireReloadTime, false);
	}
	else{
		bIsReadyToFire = false;
		--CurrentAmmoCount;

		CurrentSecondShot = SecondShotsCount;

		GetWorld()->GetTimerManager().SetTimer(SecondIntervalTimerHandle, this, &ACanonBase::SecondShot, SecondIntervalTime, false);
		
		GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &ACanonBase::Cooldown, SecondFireCooldownTime, false);
	}
}

void ACanonBase::AddAmmo(const int AdditionalAmmoValue){
	if(AdditionalAmmoValue > AmmunitionCount)
		CurrentAmmunitionCount = AmmunitionCount;
	else
		CurrentAmmunitionCount += AdditionalAmmoValue;
}

void ACanonBase::RestoreAmmo(){
	CurrentAmmunitionCount = AmmunitionCount;
	CurrentAmmoCount = AmmoCount;
}