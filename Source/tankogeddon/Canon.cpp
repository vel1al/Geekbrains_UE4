// Fill out your copyright notice in the Description page of Project Settings.


#include "Canon.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"

DECLARE_LOG_CATEGORY_EXTERN(TankLog, Log, All);
DEFINE_LOG_CATEGORY(TankLog);

// Sets default values
ACanon::ACanon()
{
	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComp;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>("SpawnPoint");
	ProjectileSpawnPoint->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ACanon::BeginPlay()
{
	Super::BeginPlay();
	
	Reload();
}

void ACanon::EndPlay(EEndPlayReason::Type Reason){
	ReloadTimerHandle.Invalidate();
	CooldownTimerHandle.Invalidate();
	QueueIntervalTimerHandle.Invalidate();

	Super::EndPlay(Reason);
}

void ACanon::Reload(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Reloaded"));

	bIsReadyToFire = true;
	CurrentAmmoCount = AmmoCount;
}

void ACanon::Cooldown(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Cooldowned"));

	bIsReadyToFire = true;
}

void ACanon::MainShot(){
	return;
}

void ACanon::QueueShot(){
	return;
}

bool ACanon::IsReadyToFire() const {
	return bIsReadyToFire;
}

void ACanon::FireMain(){
	if(!bIsReadyToFire)
		return;
	else if(CurrentAmmoCount == 0){
		bIsReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &ACanon::Reload, FireReloadTime, false);
	}
	else{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Single shot"));

		bIsReadyToFire = false;
		--CurrentAmmoCount;

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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Queue shot"));

		bIsReadyToFire = false;
		--CurrentAmmoCount;

		for(int CurrentQueueShot = QueueShotsCount; CurrentQueueShot > 0; --CurrentQueueShot){
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Current queue shot: %d"),CurrentQueueShot));
			GetWorld()->GetTimerManager().SetTimer(QueueIntervalTimerHandle, this, &ACanon::QueueShot, QueueIntervalTime, false);
		}
		GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &ACanon::Cooldown, SecondFireCooldownTime, false);
	}
}