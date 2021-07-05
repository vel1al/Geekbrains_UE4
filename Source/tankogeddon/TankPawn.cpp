// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TankPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ArrowComponent.h"
#include "DrawDebugHelpers.h"
#include "TankPlayerController.h"
#include "TankTurret.h"

// Sets default values
ATankPawn::ATankPawn(){
	//bShowMouseCursor = true;
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	RootComponent = BodyMesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BodyMesh);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ATankPawn::InvalidateTurret(int RequiredSlot){
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
		TurretSlots[AllocatedTurretSlotsCount]->AttachToComponent(BodyMesh, FAttachmentTransformRules::SnapToTargetIncludingScale);
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
		TurretSlots[CurrentTurretSlot]->AttachToComponent(BodyMesh, FAttachmentTransformRules::SnapToTargetIncludingScale);
		TurretSlots[CurrentTurretSlot]->SetActive(true);
	}
}

void ATankPawn::ChangeTurret(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Changed %d"), CurrentTurretSlot));

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

	TankController = Cast<ATankPlayerController>(GetController());
	
	TurretSlots.SetNumZeroed(TurretSlotsCount);

	SetUpTurret(DefaultTurretClass);
	TurretSlots[CurrentTurretSlot]->SetActive(true);
}

void ATankPawn::EndPlay(EEndPlayReason::Type Reason){
	for(int i = 0; i < TurretSlotsCount; ++i)
		InvalidateTurret(i);

	Super::EndPlay(Reason);
}

void ATankPawn::MoveTankXAxis(const float DeltaTime){
	FVector CurrentLocation = GetActorLocation();
	FVector MoveXAxisOffset = GetActorForwardVector() * TankMoveXAxisSpeed * CurrentTankMoveTorqueXAxis * DeltaTime;

	SetActorLocation(CurrentLocation + MoveXAxisOffset);
}

void ATankPawn::RotateTankYAxis(const float DeltaTime){
	FRotator CurrentRotation = GetActorRotation();
	CurrentTankRotationYAxis = FMath::Lerp(CurrentTankRotationYAxis, CurrentTankRotationTorqueYAxis, TankRotationYAxisSensivity);
	float RotationYAxisOffset = TankRotationYAxisSpeed * CurrentTankRotationYAxis * DeltaTime;

	float YawRotation = CurrentRotation.Yaw + RotationYAxisOffset;
	SetActorRotation(FRotator(0.f, YawRotation, 0.f));
}

void ATankPawn:: RotateTurretYAxis(){
	if(TankController && TurretSlots[CurrentTurretSlot]){
		FVector ChachedMousePosition = TankController->GetMousePos();
		FRotator TargetTurretRotation = UKismetMathLibrary::FindLookAtRotation(TurretSlots[CurrentTurretSlot]->GetActorLocation(), ChachedMousePosition);
		FRotator CurrentTurretRotation = TurretSlots[CurrentTurretSlot]->GetActorRotation();
		TargetTurretRotation.Pitch = CurrentTurretRotation.Pitch;
		TargetTurretRotation.Roll = CurrentTurretRotation.Roll;

		TurretSlots[CurrentTurretSlot]->SetActorRotation(FMath::Lerp(CurrentTurretRotation, TargetTurretRotation, TurretRotationSensitivity));
	}
}

// Called every frame
void ATankPawn::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);

	MoveTankXAxis(DeltaTime);
	RotateTankYAxis(DeltaTime);
	RotateTurretYAxis();
}

void ATankPawn::SetMoveTorqueXAxis(const float InAxisValue){
	CurrentTankMoveTorqueXAxis = InAxisValue;
}

void ATankPawn::SetRotateTorqueYAxis(const float InAxisValue){
	CurrentTankRotationTorqueYAxis = InAxisValue;
}

void ATankPawn::FireMain(){
	if(TurretSlots[CurrentTurretSlot] && TankController)
		TurretSlots[CurrentTurretSlot]->FireMain();
}
void ATankPawn::FireSecond(){
	if(TurretSlots[CurrentTurretSlot] && TankController)
		TurretSlots[CurrentTurretSlot]->FireSecond();
}