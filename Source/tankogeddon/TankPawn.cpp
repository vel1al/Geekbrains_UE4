#include "TankPawn.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include <Components/AudioComponent.h>
#include <Components/BoxComponent.h>
#include <Particles/ParticleSystemComponent.h>
#include "InventoryComponent.h"
#include "PlayerInventoryInteraction.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "DrawDebugHelpers.h"

#include "TurretBase.h"
#include "Gamestructs.h"


ATankPawn::ATankPawn(){
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

	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->SetupAttachment(RootComponent);

	TurretSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("TurretSetupPoint"));
	TurretSetupPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	PlayerHitAudioEffect = CreateDefaultSubobject<UAudioComponent>("PlayerHitAudioEffect");
	PlayerHitAudioEffect->SetupAttachment(RootComponent);

	PlayerInventoryInteractionComponent = CreateDefaultSubobject<UPlayerInventoryInteraction>(TEXT("PlayerInteractionComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPawn::InvalidateTurret(int RequiredSlot){
	if(TurretSlots.IsValidIndex(RequiredSlot))
		if (TurretSlots[RequiredSlot]){
			TurretSlots[RequiredSlot]->Destroy();
			TurretSlots[RequiredSlot] = nullptr;
		}
}

void ATankPawn::SetUpCannon(TSubclassOf<ACanonBase> NewCannonClass){
	if(TurretSlots[CurrentTurretSlot])
		TurretSlots[CurrentTurretSlot]->SetUpCannon(NewCannonClass);
}

void ATankPawn::SetUpTurret(TSubclassOf<ATurretBase> NewTurretClass){
	FActorSpawnParameters Params;
    Params.Instigator = this;
    Params.Owner = this;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if(AllocatedTurretSlotsCount != TurretSlotsCount){
		TurretSlots[AllocatedTurretSlotsCount] = GetWorld()->SpawnActor<ATurretBase>(NewTurretClass, Params);
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

		TurretSlots[CurrentTurretSlot] = GetWorld()->SpawnActor<ATurretBase>(NewTurretClass, Params);
		TurretSlots[CurrentTurretSlot]->AttachToComponent(TurretSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
		TurretSlots[CurrentTurretSlot]->SetActive(true);
	}
}
 
void ATankPawn::ChangeTurret(){
	ATurretBase* CurrentActiveTurret = GetCurrentActiveTurret();
	
	if(!(TurretSlots.IsValidIndex(++CurrentTurretSlot)))
		CurrentTurretSlot = 0;
	
	if(TurretSlots[CurrentTurretSlot]){
		if(CurrentActiveTurret)
			CurrentActiveTurret->SetActive(false);
		if(TurretSlots[CurrentTurretSlot])
			TurretSlots[CurrentTurretSlot]->SetActive(true);
	}
}

ATurretBase* ATankPawn::GetCurrentActiveTurret(){
	if(TurretSlots[CurrentTurretSlot])
		return TurretSlots[CurrentTurretSlot];

	return nullptr;
}

void ATankPawn::BeginPlay(){
	Super::BeginPlay();
	
	//TurretSlots.SetNumZeroed(TurretSlotsCount);

	//SetUpTurret(DefaultTurretClass);
	//TurretSlots[CurrentTurretSlot]->SetActive(true);

	//PlayerInventoryInteractionComponent->Init(InventoryComponent, TankName);
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

			if(!(FMath::IsNearlyZero(CurrentRotation.Yaw))){
				if(FMath::Abs(CurrentRotation.Yaw) > (TurretRotationZAxisSpeed * DeltaTime))
					CurrentTurretRotationZAxis = FMath::Lerp(CurrentTurretRotationZAxis, 1.f, TurretRotationSensitivity);
				else
					CurrentTurretRotationZAxis = FMath::Lerp(CurrentTurretRotationZAxis, 0.f, TurretRotationSensitivity);

				float RotationZAxisOffset = TurretRotationZAxisSpeed * CurrentTurretRotationZAxis * DeltaTime;
				float YawRotation = CurrentRotation.Yaw - RotationZAxisOffset;
						
				TurretSlots[CurrentTurretSlot]->SetTurretMeshRotation(FRotator(0.f, YawRotation, 0.f));
			}
		}
	}
}

void ATankPawn::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);

	//MoveTankXAxis(DeltaTime);
	//RotateTankZAxis(DeltaTime);

	//RotateTurretZAxis(DeltaTime);
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
		TurretSlots[CurrentTurretSlot]->FireMain(0);
}
void ATankPawn::FireSecond(){
	if(TurretSlots[CurrentTurretSlot])
		TurretSlots[CurrentTurretSlot]->FireSecond(0);
}