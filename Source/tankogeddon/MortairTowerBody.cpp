#include "MortairTowerBody.h"

#include "TurretBase.h"
#include "CannonBase.h"
#include "MortairTurret.h"
#include "MortairCannon.h"

#include "Components/StaticMeshComponent.h"
#include <Components/BoxComponent.h>
#include "Components/ArrowComponent.h"
#include <Components/AudioComponent.h>
#include <Particles/ParticleSystemComponent.h>

#include "HealthComponent.h"
#include <DrawDebugHelpers.h>

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"



void AMortairTowerBody::CastTurretToClass() {
	AMortairTurret* SpawnedTurret = Cast<AMortairTurret>(BaseTurret);
	if(SpawnedTurret) 
    	Turret = SpawnedTurret;
}

void AMortairTowerBody::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);

	if(!PlayerPawn || !Turret)
		return;

	if(!CheckRange())
		return;

	FVector PlayerLocation = PlayerPawn->GetActorLocation();
	FVector BalisticPoint = GetBalisticPoint(PlayerLocation);

	float CurrentTurretAngle = GetAngleFromTo(BaseTurret->GetTurretMeshDirection(), PlayerLocation - GetActorLocation());
	float CurrentCannonAngle = GetAngleFromTo(BaseTurret->GetCannon()->GetActorForwardVector(), BalisticPoint - BaseTurret->GetCannon()->GetActorLocation());
	
	DrawDebugLine(GetWorld(), GetActorLocation() + BaseTurret->GetCannon()->GetActorForwardVector(),  GetActorLocation() + BaseTurret->GetCannon()->GetActorForwardVector() * 1000.f, FColor::Emerald, true, -1, 1, 10);
	DrawDebugLine(GetWorld(), GetActorLocation() + BaseTurret->GetCannon()->GetActorForwardVector(), BalisticPoint, FColor::Yellow, true, -1, 1, 10);

	if ((CurrentTurretAngle < TurretTargetingAccurency) && CurrentCannonAngle < CannonVisualAccurency) {
		FVector2D Target(PlayerLocation);
		FVector2D CurrentLocation(GetActorLocation());
		FVector2D DirectionToTarget(Target - CurrentLocation);
		DirectionToTarget.Normalize();

		Target = Target + DirectionToTarget * 150.f;

		Turret->GetMortairCannon()->SetTarget(Target);
		Turret->GetMortairCannon()->SetSupportPoint(BalisticPoint);

		Fire();
	}
	else{
		RotateTurretYAxis(BalisticPoint);
		RotateCannonXAxis(BalisticPoint);
	}
}

void AMortairTowerBody::BeginPlay(){
	Super::BeginPlay();


	SetUpTurret(DefaultTurretClass);
	CastTurretToClass();

    PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

    check(Turret && PlayerPawn);
}

void AMortairTowerBody::RotateCannonXAxis(const FVector TargetPoint){
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(Turret->GetCannon()->GetActorLocation(), TargetPoint);
	FRotator CurrentCannonRotation = Turret->GetCannon()->GetActorRotation();

	TargetRotation.Roll = CurrentCannonRotation.Roll;
	TargetRotation.Yaw = CurrentCannonRotation.Yaw;

	Turret->SetCannonRotation(FMath::Lerp(CurrentCannonRotation, TargetRotation, TurretTargetingSpeed));
}

FVector AMortairTowerBody::GetBalisticPoint(const FVector TargetPoint){
	FVector2D CurrentPoint(GetActorLocation());
	FVector2D BalisticPoint(TargetPoint);
	
	FVector2D DirectionToPoint = BalisticPoint - CurrentPoint;
	DirectionToPoint.Normalize();

	BalisticPoint = BalisticPoint - (DirectionToPoint * FVector::Dist2D(TargetPoint, GetActorLocation()) * PositionAdjuster);

	// if(CurrentPoint.X < TargetPoint.X) BalisticPoint.X = BalisticPoint.X + FVector::Distance(TargetPoint, CurrentPoint) * PositionAdjuster;
	// else 							   BalisticPoint.X = BalisticPoint.X - FVector::Distance(TargetPoint, CurrentPoint) * PositionAdjuster;
	// if(CurrentPoint.X < TargetPoint.X) BalisticPoint.Y = BalisticPoint.Y + FVector::Distance(TargetPoint, CurrentPoint) * PositionAdjuster;
	// else 							   BalisticPoint.Y = BalisticPoint.Y - FVector::Distance(TargetPoint, CurrentPoint) * PositionAdjuster;
	// BalisticPoint.Z = BalisticPoint.Z - FVector::Distance(TargetPoint, CurrentPoint) * HeightAdjuster;
	
	// float TargetX;
	// if(CurrentPoint.X < TargetPoint.X) TargetX = CurrentPoint.X + FVector::Distance(TargetPoint, CurrentPoint) * PositionAdjuster;
    // else                               TargetX = CurrentPoint.X - FVector::Distance(TargetPoint, CurrentPoint) * PositionAdjuster;
	
	// float 							   TargetZ = CurrentPoint.Z + FVector::Distance(TargetPoint, CurrentPoint) * HeightAdjuster;

	return FVector(BalisticPoint, (TargetPoint.Z + FVector::Dist2D(TargetPoint, GetActorLocation()) * HeightAdjuster));
}