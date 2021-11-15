#include "TargetingMath.h"


float TargetingMath::GetRotateTurretTorque(const FVector& Direction, const FVector& TurretDirection, const float AngleSensitivity) {
	float TurretRotationTorque = 0;
	float SignedAngle = TargetingMath::GetSignedAngleBetweenDirections(Direction, TurretDirection);
	
	if(FMath::Abs(SignedAngle) > AngleSensitivity){
		if(SignedAngle > 0) TurretRotationTorque = 1;
		else				TurretRotationTorque = -1;
	}

	return TurretRotationTorque;
}

bool TargetingMath::CheckVisibility(const FVector& Point, const AActor* TargetActor, UWorld* World, AActor* IgnoredActor) {
	if(!World)
		return false;

	FCollisionQueryParams Settings(FName(TEXT("VeiewCheck")), true, IgnoredActor);
	FHitResult HitResult;

	Settings.AddIgnoredActor(IgnoredActor);
	Settings.bReturnPhysicalMaterial = false;

	if (World->LineTraceSingleByChannel(HitResult, Point, TargetActor->GetActorLocation(), ECC_Visibility, Settings))
		if (HitResult.Actor.IsValid())
			return HitResult.Actor.Get() == TargetActor;

	
	return false;
}

bool TargetingMath::CheckDistance(const FVector& Point, const FVector& Point2, const float MaxDistance) {
	return FVector2D::DistSquared(FVector2D(Point), FVector2D(Point2)) > MaxDistance * MaxDistance;
}

float TargetingMath::GetAngleBetweenDirections(const FVector& Direction1, const FVector& Direction2) {
	FVector Direction1Copy = Direction1;
	FVector Direction2Copy = Direction2;

	Direction1Copy.Normalize();
	Direction2Copy.Normalize();

	return FMath::RadiansToDegrees(acosf(FVector::DotProduct(Direction1Copy, Direction2Copy)));
}

float TargetingMath::GetSignedAngleBetweenDirections(const FVector& Direction1, const FVector& Direction2) {
	FVector Direction1Copy = Direction1;
	FVector Direction2Copy = Direction2;

	Direction1Copy.Normalize();
	Direction2Copy.Normalize();

	float AngleOfReferenceTurret = FMath::RadiansToDegrees(FMath::Atan2(Direction1Copy.Y, Direction1Copy.X));
	float AngleOfReferenceTarget = FMath::RadiansToDegrees(FMath::Atan2(Direction2Copy.Y, Direction2Copy.X));

	float SignedAngle = AngleOfReferenceTarget - AngleOfReferenceTurret;

	if (SignedAngle > 180)		SignedAngle -= 360;
	if (SignedAngle <= -180)	SignedAngle += 360;

	
	return SignedAngle;
}