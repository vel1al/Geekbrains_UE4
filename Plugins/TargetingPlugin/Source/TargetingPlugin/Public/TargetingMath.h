#pragma once

#include "CoreMinimal.h"


class TARGETINGPLUGIN_API TargetingMath {
	public:
		static float GetAngleBetweenDirections(const FVector& Direction1, const FVector& Direction2);
		static float GetSignedAngleBetweenDirections(const FVector& Direction1, const FVector& Direction2);
		static float GetRotateTurretTorque(const FVector& Direction, const FVector& TurretDirection, const float AngleSensitivity);
		static bool CheckVisibility(const FVector& Point, const AActor* TargetActor, UWorld* World, AActor* IgnoredActor = nullptr);
		static bool CheckDistance(const FVector& Point, const FVector& Point2, const float MaxDistance);
};