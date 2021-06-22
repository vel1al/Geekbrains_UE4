// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATankPawn::ATankPawn(){
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	RootComponent = BodyMesh;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BodyMesh);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BodyMesh);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay(){
	Super::BeginPlay();
}

// Called every frame
void ATankPawn::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector XAxisOffset = GetActorForwardVector() * MoveXAxisSpeed * CurrentTorqueXAxis * DeltaTime;
	FVector YAxisOffset = GetActorRightVector() * StrafeYAxisSpeed * CurrentTorqueYAxis * DeltaTime;

	FVector NewLocation = CurrentLocation + XAxisOffset + YAxisOffset;

	SetActorLocation(NewLocation);
}

void ATankPawn::MoveXAxis(const float InAxisValue){
	CurrentTorqueXAxis = InAxisValue;
}

void ATankPawn::MoveYAxis(const float InAxisValue){
	CurrentTorqueYAxis = InAxisValue;
}