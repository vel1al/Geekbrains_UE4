// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Canon.h"

// Sets default values
ATankTurret::ATankTurret(){
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComp;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(SceneComp);

	CannonSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("CannonSetupPoint"));
	CannonSetupPoint->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATankTurret::BeginPlay(){
	Super::BeginPlay();

	SetUpCannon(DefaultCannonClass);
}

void ATankTurret::EndPlay(EEndPlayReason::Type Reason){
	InvalidateCannon();

	Super::EndPlay(Reason);
}

void ATankTurret::SetUpCannon(TSubclassOf<class ACanon> NewCannonClass){
	if(Cannon)
		InvalidateCannon();
	if(NewCannonClass){
		FActorSpawnParameters Params;
		Params.Owner = this;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Cannon = GetWorld()->SpawnActor<ACanon>(NewCannonClass, Params);
		Cannon->AttachToComponent(CannonSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void ATankTurret::SetActive(bool bIsActive){
	if(bIsActive)
		TurretMesh->SetVisibility(true);
	else
		TurretMesh->SetVisibility(false);
}

void ATankTurret::FireMain(){
	if(Cannon)
		Cannon->FireMain();
}

void ATankTurret::FireSecond(){
	if(Cannon)
		Cannon->FireSecond();
}

void ATankTurret::RestoreAmmo(){
	if(Cannon)
		Cannon->RestoreAmmo();
}

void ATankTurret::InvalidateCannon(){
	if(Cannon){
		Cannon->Destroy();
		Cannon = nullptr;
	}
}