#pragma once


#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "GameStructs.generated.h"


UENUM(BlueprintType)
enum class ECannonType : uint8{
    FireProjectile = 0 UMETA(DisplayName = "Projectile"),
    FireRay = 1 UMETA(DisplayName = "Raycast")
};