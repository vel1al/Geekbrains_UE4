#include "TurretBase.h"

#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

#include "CannonBase.h"


ATurretBase::ATurretBase(){
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneComp;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(SceneComp);

	CannonSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("CannonSetupPoint"));
	CannonSetupPoint->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

void ATurretBase::SetUpCannon(TSubclassOf<class ACanonBase> NewCannonClass){
	if(BaseCannon)
		InvalidateCannon();

	if(NewCannonClass){
		FActorSpawnParameters Settings;
		Settings.Instigator = GetInstigator();
		Settings.Owner = this;
		Settings.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		BaseCannon = GetWorld()->SpawnActor<ACanonBase>(NewCannonClass, Settings);
		BaseCannon->AttachToComponent(CannonSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

void ATurretBase::BeginPlay(){
	Super::BeginPlay();

	SetUpCannon(DefaultCannonClass);

    check(BaseCannon);
}

void ATurretBase::EndPlay(EEndPlayReason::Type Reason){
	InvalidateCannon();

	Super::EndPlay(Reason);
}

FRotator ATurretBase::GetTurretMeshRotation() const {
	return TurretMesh->GetComponentRotation();
}

FVector ATurretBase::GetTurretMeshDirection() const {
	return TurretMesh->GetForwardVector();
}

void ATurretBase::SetTurretMeshRotation(const FRotator value){
	TurretMesh->SetWorldRotation(value);
}

ACanonBase* ATurretBase::GetCannon() const {
	if(BaseCannon)
		return BaseCannon;

	return nullptr;
}

void ATurretBase::SetCannonRotation(const FRotator value){
	if(BaseCannon)
		BaseCannon->SetActorRotation(value);
}

void ATurretBase::FireMain(const float AdditionDamage){
	if(BaseCannon)
		BaseCannon->FireMain(AdditionDamage);
}

void ATurretBase::FireSecond(const float AdditionDamage){
	if(BaseCannon)
		BaseCannon->FireSecond(AdditionDamage);
}

void ATurretBase::RestoreAmmo(){
	if(BaseCannon)
		BaseCannon->RestoreAmmo();
}

void ATurretBase::InvalidateCannon(){
	if(BaseCannon){
		BaseCannon->Destroy();
		BaseCannon = nullptr;
	}
}

void ATurretBase::CastCannonToClass(){
    return;
}