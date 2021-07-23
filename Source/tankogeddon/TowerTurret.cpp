#include "TowerTurret.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Canon.h"


ATowerTurret::ATowerTurret(){
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComp;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(SceneComp);

	CannonSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("CannonSetupPoint"));
	CannonSetupPoint->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

void ATowerTurret::SetUpCannon(TSubclassOf<class ACanon> NewCannonClass){
	if(Cannon)
		InvalidateCannon();
	if(NewCannonClass){
		FActorSpawnParameters Params;
		Params.Instigator = GetInstigator();
		Params.Owner = this;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		Cannon = GetWorld()->SpawnActor<ACanon>(NewCannonClass, Params);
		Cannon->AttachToComponent(CannonSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void ATowerTurret::BeginPlay(){
	Super::BeginPlay();

	SetUpCannon(DefaultCannonClass);
}

void ATowerTurret::EndPlay(EEndPlayReason::Type Reason){
	InvalidateCannon();

	Super::EndPlay(Reason);
}

FRotator ATowerTurret::GetTurretMeshRotation() const {
	return TurretMesh->GetComponentRotation();
}

FVector ATowerTurret::GetTurretMeshDirection() const {
	return TurretMesh->GetForwardVector();
}

void ATowerTurret::SetTurretMeshRotation(const FRotator value){
	TurretMesh->SetWorldRotation(value);
}

void ATowerTurret::FireMain(){
	if(Cannon)
		Cannon->FireMain();
}

void ATowerTurret::FireSecond(){
	if(Cannon)
		Cannon->FireSecond();
}

void ATowerTurret::RestoreAmmo(){
	if(Cannon)
		Cannon->RestoreAmmo();
}

void ATowerTurret::InvalidateCannon(){
	if(Cannon){
		Cannon->Destroy();
		Cannon = nullptr;
	}
}