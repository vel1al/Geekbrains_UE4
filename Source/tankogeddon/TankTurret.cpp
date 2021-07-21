#include "TankTurret.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Canon.h"
#include "IScoreCounter.h"

ATankTurret::ATankTurret(){
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComp;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(SceneComp);

	CannonSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("CannonSetupPoint"));
	CannonSetupPoint->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

void ATankTurret::IncrementScore(const int value){
	IIScoreCounter* TankBody = Cast<IIScoreCounter>(GetInstigator());

	if(TankBody)
		TankBody->IncrementScore(value);
}

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
		Params.Instigator = GetInstigator();
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Cannon = GetWorld()->SpawnActor<ACanon>(NewCannonClass, Params);
		Cannon->AttachToComponent(CannonSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

FRotator ATankTurret::GetTurretMeshRotation() const {
	return TurretMesh->GetRelativeRotation();
}

FVector ATankTurret::GetTurretMeshDirection() const {
	return TurretMesh->GetForwardVector();
}

FVector ATankTurret::GetTurretMeshLocation() const {
	return TurretMesh->GetComponentLocation();
}

void ATankTurret::SetTurretMeshRotation(const FRotator value){
	TurretMesh->SetRelativeRotation(value);
}

void ATankTurret::SetActive(bool bIsActive){
	TurretMesh->SetVisibility(bIsActive);
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