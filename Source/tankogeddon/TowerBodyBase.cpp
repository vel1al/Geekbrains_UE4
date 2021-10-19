#include "TowerBodyBase.h"
#include "TurretBase.h"

#include "Components/StaticMeshComponent.h"
#include <Components/BoxComponent.h>
#include "Components/ArrowComponent.h"

#include <DrawDebugHelpers.h>

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include <Particles/ParticleSystemComponent.h>


ATowerBodyBase::ATowerBodyBase(){
	USceneComponent* sceeneCpm = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = sceeneCpm;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerBody"));
	BodyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	TurretSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("TurretSetupPoint"));
	TurretSetupPoint->AttachToComponent(BodyMesh, FAttachmentTransformRules::KeepRelativeTransform);

    TurretTargetingSpeed = 1.f / (360.f / TurretTargetingSpeedDegrees);
}

void ATowerBodyBase::BeginPlay(){
	Super::BeginPlay();


	SetUpTurret(DefaultTurretClass);
    PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

    check(BaseTurret && PlayerPawn);
}

void ATowerBodyBase::EndPlay(EEndPlayReason::Type Reason){
    Super::EndPlay(Reason);


    InvalidateTurret();
}

void ATowerBodyBase::RotateTurretYAxis(const FVector TargetPoint){
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(BaseTurret->GetActorLocation(), TargetPoint);
	FRotator CurrentRotation = BaseTurret->GetTurretMeshRotation();

	TargetRotation.Pitch = CurrentRotation.Pitch;
	TargetRotation.Roll = CurrentRotation.Roll;

	BaseTurret->SetTurretMeshRotation(FMath::Lerp(CurrentRotation, TargetRotation, TurretTargetingSpeed));
}

bool ATowerBodyBase::CheckRange(){
	if(PlayerPawn)
    	return FVector::Distance(PlayerPawn->GetActorLocation(), GetActorLocation()) <= TurretTargetingRange;

	return false;
}

void ATowerBodyBase::Fire(){
	if(BaseTurret)
		BaseTurret->FireMain();
}

FVector ATowerBodyBase::GetTurretDirection() const {
	return BaseTurret->GetTurretMeshDirection();
}

float ATowerBodyBase::GetAngleFromTo(const FVector FromDirection, const FVector ToDirection) {
    FVector TargetDirectionCopy = ToDirection;
	FVector CurrentDirectionCopy = FromDirection;

	CurrentDirectionCopy.Normalize();
    TargetDirectionCopy.Normalize();

	return FMath::RadiansToDegrees(acosf(FVector::DotProduct(CurrentDirectionCopy, TargetDirectionCopy)));
}

void ATowerBodyBase::SetUpTurret(TSubclassOf<class ATurretBase> NewTurretClass){
	if(BaseTurret)
		InvalidateTurret();

	FActorSpawnParameters Settings;
    Settings.Owner = this;
	Settings.Instigator = this;

    BaseTurret = GetWorld()->SpawnActor<ATurretBase>(NewTurretClass, Settings);
	BaseTurret->AttachToComponent(TurretSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void ATowerBodyBase::InvalidateTurret(){
	if(BaseTurret){
		BaseTurret->Destroy();
		BaseTurret = nullptr;
	}
}

void ATowerBodyBase::CastTurretToClass(){
    return;
}