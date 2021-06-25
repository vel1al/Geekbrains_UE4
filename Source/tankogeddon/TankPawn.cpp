// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TankPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ArrowComponent.h"
#include "Canon.h"
#include "DrawDebugHelpers.h"
#include "TankPlayerController.h"

// Sets default values
ATankPawn::ATankPawn(){
	//bShowMouseCursor = true;
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	RootComponent = BodyMesh;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BodyMesh);

	CannonSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("CannonSetupPoint"));
	CannonSetupPoint->AttachToComponent(TurretMesh, FAttachmentTransformRules::KeepRelativeTransform);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BodyMesh);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ATankPawn::InvalidateCannon(){
	if (Cannon){
		Cannon->Destroy();
		Cannon = nullptr;
	}
}

void ATankPawn::SetUpCannon(){
	InvalidateCannon();

	if (CannonClass){
		FActorSpawnParameters Settings;

		Settings.Instigator = this;
		Settings.Owner = this;
		Cannon = GetWorld()->SpawnActor<ACanon>(CannonClass, Settings);
		Cannon->AttachToComponent(CannonSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay(){
	Super::BeginPlay();

	TankController = Cast<ATankPlayerController>(GetController());

	SetUpCannon();
}

void ATankPawn::EndPlay(EEndPlayReason::Type Reason){
	InvalidateCannon();

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
	if(TankController){
		FVector ChachedMousePosition = TankController->GetMousePos();
		FRotator TargetTurretRotation = UKismetMathLibrary::FindLookAtRotation(TurretMesh->GetComponentLocation(), ChachedMousePosition);
		FRotator CurrentTurretRotation = TurretMesh->GetComponentRotation();
		TargetTurretRotation.Pitch = CurrentTurretRotation.Pitch;
		TargetTurretRotation.Roll = CurrentTurretRotation.Roll;

		TurretMesh->SetWorldRotation(FMath::Lerp(CurrentTurretRotation, TargetTurretRotation, TurretRotationSensitivity));
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
	if(Cannon && TankController)
		Cannon->FireMain();
}
void ATankPawn::FireSecond(){
	if(Cannon && TankController)
		Cannon->FireSecond();
}