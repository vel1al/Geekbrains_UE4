// Fill out your copyright notice in the Description page of Project Settings.


#include "Canon.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
//#include "ProjectilePoolManager.h"
#include "Projectile.h"

// Sets default values
ACanon::ACanon(){
	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComp;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>("SpawnPoint");
	ProjectileSpawnPoint->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ACanon::BeginPlay(){
	Super::BeginPlay();
	
	CurrentAmmoCount = AmmoCount;
	CurrentAmmunitionCount = AmmunitionCount;
	bIsReadyToFire = true;

	//ProjectilePoolManager = NewObject<UProjectilePoolManager>(this);
}

void ACanon::EndPlay(EEndPlayReason::Type Reason){
	ReloadTimerHandle.Invalidate();
	CooldownTimerHandle.Invalidate();
	QueueIntervalTimerHandle.Invalidate();

	Super::EndPlay(Reason);
}

void ACanon::Reload(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Fire: Reloaded"));

	if(CurrentAmmunitionCount > AmmoCount)
		CurrentAmmunitionCount = AmmoCount;
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

void ACanon::QueueShot(){
	GEngine->AddOnScreenDebugMessage(-1, 0.5, FColor::Green, TEXT("Fire: Queue shot"));

	--CurrentQueueShot;

	if(CurrentQueueShot > 0){
		Fire();
		GetWorld()->GetTimerManager().SetTimer(QueueIntervalTimerHandle, this, &ACanon::QueueShot, QueueIntervalTime, false);
	} else
		return;
}

bool ACanon::IsReadyToFire() const {
	return bIsReadyToFire;
}

void ACanon::Fire(){
	if (Type == ECannonType::FireProjectile){
		GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Green, TEXT("Fire: type = projectile"));

		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
		if (Projectile){
			Projectile->MoveRange = FireRange;
			Projectile->Start(ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
		}
	}
	else if (Type == ECannonType::FireRay){
		GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Green, TEXT("Fire: type = trace"));

		FHitResult HitResult;
		FVector StartPoint = ProjectileSpawnPoint->GetComponentLocation();
		FVector EndPoint = StartPoint + ProjectileSpawnPoint->GetForwardVector() * FireRange;

		FCollisionQueryParams TraceSettings = FCollisionQueryParams(FName("FireTrace"), true, this);
		TraceSettings.bTraceComplex = true;
		TraceSettings.bReturnPhysicalMaterial = false;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility, TraceSettings)){
			DrawDebugLine(GetWorld(), StartPoint, HitResult.Location, FColor::Red, false, 5.f, 0, 5);
			
			if (HitResult.Actor.IsValid()){
				HitResult.Actor->Destroy();
			}
		} else
			DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Green, false, 5.f, 0, 5);
	}
}

void ACanon::FireMain(){
	if(!bIsReadyToFire){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fire: itterapted"));
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

		CurrentQueueShot = QueueShotsCount;
		GetWorld()->GetTimerManager().SetTimer(QueueIntervalTimerHandle, this, &ACanon::QueueShot, QueueIntervalTime, false);
		
		GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &ACanon::Cooldown, SecondFireCooldownTime, false);
	}
}

void ACanon::RestoreAmmo(){
	CurrentAmmunitionCount = AmmunitionCount;
	CurrentAmmoCount = AmmoCount;
}