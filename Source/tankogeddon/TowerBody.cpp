// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBody.h"
//#include "TankPawn.h"
#include "TowerTurret.h"
#include "Components/StaticMeshComponent.h"
#include <Components/BoxComponent.h>
#include "Components/ArrowComponent.h"
#include "HealthComponent.h"
#include "Kismet/KismetMathLibrary.h"


ATowerBody::ATowerBody(){
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret body"));
    RootComponent = BodyMesh;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
    HealthComponent->OnDie.AddUObject(this, &ATowerBody::Die);
    HealthComponent->OnTookDamage.AddUObject(this, &ATowerBody::DamageTook);

	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->SetupAttachment(RootComponent);

	TurretSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("TurretSetupPoint"));
	TurretSetupPoint->AttachToComponent(BodyMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

bool ATowerBody::CauseDamage(FDamageData DamageData){
    return HealthComponent->TakeDamage(DamageData);
}

void ATowerBody::Die(){
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Red, TEXT("Tower: was destroyed"));

	InvalidateTurret();
	Destroy();
}

void ATowerBody::DamageTook(float DamageValue){
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Orange, TEXT("Tower took damage"));
}

void ATowerBody::SetUpTurret(TSubclassOf<class ATowerTurret> NewTurretClass){
	if(Turret)
		InvalidateTurret();

	FActorSpawnParameters Params;
    Params.Owner = this;
	Params.Instigator = this;

    Turret = GetWorld()->SpawnActor<ATowerTurret>(NewTurretClass, Params);
    Turret->AttachToComponent(TurretSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void ATowerBody::InvalidateTurret(){
	if(Turret){
		Turret->Destroy();
		Turret = nullptr;
	}
}

void ATowerBody::BeginPlay(){
	Super::BeginPlay();

	SetUpTurret(DefaultTurretClass);
    PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	AngleToPlayer = GetAngleToPlayer();

	TargetingSpeed = 1.f / (360.f / TargetingSpeedDegrees);
}

void ATowerBody::EndPlay(EEndPlayReason::Type Reason){
    Super::EndPlay(Reason);


    InvalidateTurret();
}

void ATowerBody::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);


	if(CheckRange())
		RotateTurretYAxis();

	AngleToPlayer = GetAngleToPlayer();

    if(AngleToPlayer < Accurency)
        FireMain();
}

void ATowerBody::RotateTurretYAxis(){
//	FVector TargetLocation = PlayerPawn->GetActorLocation() + PlayerPawn->GetActorForwardVector() * PlayerPawn->GetMoveTorqueXAxis() *
//	                         PlayerPawn->GetMoveSpeedXAxis() * (AngleToPlayer/ TargetingSpeed);

	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(Turret->GetActorLocation(), PlayerPawn->GetActorLocation());
	FRotator CurrentRotation = Turret->GetTurretMeshRotation();

	TargetRotation.Pitch = CurrentRotation.Pitch;
	TargetRotation.Roll = CurrentRotation.Roll;

	Turret->SetTurretMeshRotation(FMath::Lerp(CurrentRotation, TargetRotation, TargetingSpeed));
}

bool ATowerBody::CheckRange(){
    return FVector::Distance(PlayerPawn->GetActorLocation(), GetActorLocation()) <= TargetingRange;
}

void ATowerBody::FireMain(){
	if(Turret)
		Turret->FireMain();
}

void ATowerBody::FireSecond(){
	if(Turret)
		Turret->FireSecond();
}

int ATowerBody::GetScoreValue() const{
	return ScoreValue;
}

float ATowerBody::GetAngleToPlayer() {
	FVector TargetingDirection = Turret->GetTurretMeshForwardVector();
    FVector DirectionToPlayer = PlayerPawn->GetActorLocation() - Turret->GetActorLocation();

    DirectionToPlayer.Normalize();

	return FMath::RadiansToDegrees(acosf(FVector::DotProduct(TargetingDirection, DirectionToPlayer)));
}