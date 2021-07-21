// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include <Components/AudioComponent.h>
#include <Components/BoxComponent.h>
#include "HealthComponent.h"
#include "ScoreComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "TankTurret.h"
#include "Gamestructs.h"

// Sets default values
ATankPawn::ATankPawn(){
	//bShowMouseCursor = true;
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* sceeneCpm = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = sceeneCpm;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
    HealthComponent->OnDie.AddUObject(this, &ATankPawn::Die);
    HealthComponent->OnTookDamage.AddUObject(this, &ATankPawn::DamageTook);

	ScoreComponent = CreateDefaultSubobject<UScoreComponent>(TEXT("Score component"));

	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->SetupAttachment(RootComponent);

	TurretSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("TurretSetupPoint"));
	TurretSetupPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	PlayerHitAudioEffect = CreateDefaultSubobject<UAudioComponent>("PlayerHitAudioEffect");
	PlayerHitAudioEffect->SetupAttachment(RootComponent);
}

bool ATankPawn::CauseDamage(FDamageData DamageData){
	return HealthComponent->TakeDamage(DamageData);
}

void ATankPawn::Die(){
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Red, TEXT("Tank: died"));

	Destroy();
}

void ATankPawn::DamageTook(float DamageValue){
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Orange, FString::Printf(TEXT("Tank: took damage %f"), DamageValue));

	PlayerHitAudioEffect->Play();
}

void ATankPawn::IncrementScore(const int value){
	UE_LOG(LogTemp, Display, TEXT("Tank: took score %d"), value);

	ScoreComponent->IncrementScore(value);
}

void ATankPawn::InvalidateTurret(int RequiredSlot){
	if(TurretSlots.IsValidIndex(RequiredSlot))
		if (TurretSlots[RequiredSlot]){
			TurretSlots[RequiredSlot]->Destroy();
			TurretSlots[RequiredSlot] = nullptr;
		}
}

void ATankPawn::SetUpCannon(TSubclassOf<ACanon> NewCannonClass){
	if(TurretSlots[CurrentTurretSlot])
		TurretSlots[CurrentTurretSlot]->SetUpCannon(NewCannonClass);
}

void ATankPawn::SetUpTurret(TSubclassOf<ATankTurret> NewTurretClass){
	FActorSpawnParameters Params;
    Params.Instigator = this;
    Params.Owner = this;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if(AllocatedTurretSlotsCount != TurretSlotsCount){
		TurretSlots[AllocatedTurretSlotsCount] = GetWorld()->SpawnActor<ATankTurret>(NewTurretClass, Params);
		TurretSlots[AllocatedTurretSlotsCount]->AttachToComponent(TurretSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
		TurretSlots[AllocatedTurretSlotsCount]->SetActive(false);

		++AllocatedTurretSlotsCount;
	}
	else if(TurretSlots[CurrentTurretSlot]){
		if(NewTurretClass == TurretSlots[CurrentTurretSlot]->GetClass()){
			TurretSlots[CurrentTurretSlot]->RestoreAmmo();
			return;
		}

		InvalidateTurret(CurrentTurretSlot);

		TurretSlots[CurrentTurretSlot] = GetWorld()->SpawnActor<ATankTurret>(NewTurretClass, Params);
		TurretSlots[CurrentTurretSlot]->AttachToComponent(TurretSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
		TurretSlots[CurrentTurretSlot]->SetActive(true);
	}
}
 
void ATankPawn::ChangeTurret(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Tank: changed turret slot to %d"), CurrentTurretSlot));

	ATankTurret* CurrentActiveTurret = GetCurrentActiveTurret();
	
	if(!(TurretSlots.IsValidIndex(++CurrentTurretSlot)))
		CurrentTurretSlot = 0;
	
	if(TurretSlots[CurrentTurretSlot]){
		if(CurrentActiveTurret)
			CurrentActiveTurret->SetActive(false);
		if(TurretSlots[CurrentTurretSlot])
			TurretSlots[CurrentTurretSlot]->SetActive(true);
	}
}

ATankTurret* ATankPawn::GetCurrentActiveTurret(){
	if(TurretSlots[CurrentTurretSlot])
		return TurretSlots[CurrentTurretSlot];

	return nullptr;
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay(){
	Super::BeginPlay();
	
	TurretSlots.SetNumZeroed(TurretSlotsCount);

	SetUpTurret(DefaultTurretClass);
	TurretSlots[CurrentTurretSlot]->SetActive(true);
}

void ATankPawn::EndPlay(EEndPlayReason::Type Reason){
	for(int i = 0; i < TurretSlotsCount; ++i)
		InvalidateTurret(i);

	Super::EndPlay(Reason);
}

void ATankPawn::Destroyed(){
	Super::Destroyed();

	for(int i = 0; i < TurretSlotsCount; ++i)
		InvalidateTurret(i);
}

void ATankPawn::MoveTankXAxis(const float DeltaTime){
	FVector CurrentLocation = GetActorLocation();
	FVector MoveXAxisOffset = GetActorForwardVector() * TankMoveXAxisSpeed * CurrentTankMoveTorqueXAxis * DeltaTime;

	SetActorLocation(CurrentLocation + MoveXAxisOffset);
}

void ATankPawn::RotateTankZAxis(const float DeltaTime){
	FRotator CurrentRotation = GetActorRotation();
	CurrentTankRotationZAxis = FMath::Lerp(CurrentTankRotationZAxis, CurrentTankRotationTorqueZAxis, TankRotationZAxisSensivity);

	float RotationZAxisOffset = TankRotationZAxisSpeed * CurrentTankRotationZAxis * DeltaTime;
	float YawRotation = CurrentRotation.Yaw + RotationZAxisOffset;

	SetActorRotation(FRotator(0.f, YawRotation, 0.f));
}

void ATankPawn::RotateTurretZAxis(const float DeltaTime){
	if(TurretSlots[CurrentTurretSlot]){
		if(!(bIsRequringRotateToStart)){
			FRotator CurrentRotation = TurretSlots[CurrentTurretSlot]->GetTurretMeshRotation();
			CurrentTurretRotationZAxis = FMath::Lerp(CurrentTurretRotationZAxis, CurrentTurretRotationTorqueZAxis, TurretRotationSensitivity);

			float RotationZAxisOffset = TurretRotationZAxisSpeed * CurrentTurretRotationZAxis * DeltaTime;
			float YawRotation = CurrentRotation.Yaw + RotationZAxisOffset;

			TurretSlots[CurrentTurretSlot]->SetTurretMeshRotation(FRotator(0.f, YawRotation, 0.f));
		}

		else{
			FRotator CurrentRotation = TurretSlots[CurrentTurretSlot]->GetTurretMeshRotation();

			UE_LOG(LogTemp, Display, TEXT("curr rot %f"), CurrentRotation.Yaw);

			if(!(FMath::IsNearlyZero(CurrentRotation.Yaw))){
				if(FMath::Abs(CurrentRotation.Yaw) > (TurretRotationZAxisSpeed * DeltaTime))
					CurrentTurretRotationZAxis = FMath::Lerp(CurrentTurretRotationZAxis, 1.f, TurretRotationSensitivity);
				else
					CurrentTurretRotationZAxis = FMath::Lerp(CurrentTurretRotationZAxis, 0.f, TurretRotationSensitivity);

				float RotationZAxisOffset = TurretRotationZAxisSpeed * CurrentTurretRotationZAxis * DeltaTime;
				float YawRotation = CurrentRotation.Yaw - RotationZAxisOffset;
						
				TurretSlots[CurrentTurretSlot]->SetTurretMeshRotation(FRotator(0.f, YawRotation, 0.f));

				UE_LOG(LogTemp, Display, TEXT("rotating turret to the start %f"), YawRotation);
			}
		}
	}
}

// Called every frame
void ATankPawn::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);

	MoveTankXAxis(DeltaTime);
	RotateTankZAxis(DeltaTime);

	RotateTurretZAxis(DeltaTime);
}

float ATankPawn::GetMoveTorqueXAxis() const{
	return CurrentTankMoveTorqueXAxis;
}

float ATankPawn::GetMoveSpeedXAxis() const{
	return TankMoveXAxisSpeed;
}

void ATankPawn::SetRotateTurretTorqueZAxis(const float InAxisValue){
	CurrentTurretRotationTorqueZAxis = InAxisValue;

	bIsRequringRotateToStart = false;
}

void ATankPawn::SetRotateTorqueZAxis(const float InAxisValue){
	CurrentTankRotationTorqueZAxis = InAxisValue;
}

void ATankPawn::SetMoveTorqueXAxis(const float InAxisValue){
	CurrentTankMoveTorqueXAxis = InAxisValue;
}

FVector ATankPawn::GetTurretDirection() const {
	if(TurretSlots[CurrentTurretSlot])
		return TurretSlots[CurrentTurretSlot]->GetTurretMeshDirection();

	return FVector(0.f);
}

FVector ATankPawn::GetLookFromPosition() const {
	if(TurretSlots[CurrentTurretSlot])
		return TurretSlots[CurrentTurretSlot]->GetActorLocation();
	
	return FVector(0.f);
}

void ATankPawn::RotateTurretToStart(){
	bIsRequringRotateToStart = true;

	CurrentTurretRotationTorqueZAxis = 0;
}

void ATankPawn::FireMain(){
	if(TurretSlots[CurrentTurretSlot])
		TurretSlots[CurrentTurretSlot]->FireMain();
}
void ATankPawn::FireSecond(){
	if(TurretSlots[CurrentTurretSlot])
		TurretSlots[CurrentTurretSlot]->FireSecond();
}