#pragma once


#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "GameStructs.generated.h"


UENUM(BlueprintType)
enum class ECannonType : uint8{
    FireProjectile = 0 UMETA(DisplayName = "Projectile"),
    FireRay = 1 UMETA(DisplayName = "Raycast")
};

USTRUCT(BlueprintType)
struct FDamageData{
    GENERATED_BODY()

    UPROPERTY()
    float DamageValue;
    
    UPROPERTY()
    AActor* Instigator;
    
    UPROPERTY()
    AActor* DamageMaker;
};

USTRUCT(BlueprintType)
struct FProjectilePreStartData{
    GENERATED_BODY()

    UPROPERTY()
    FVector Location;

    UPROPERTY()
    FRotator Rotation;

    UPROPERTY()
    APawn* Instigator;

    UPROPERTY()
    float CanonDamage;
};

USTRUCT(BlueprintType)
struct FPhysicsProjectilePreStartData{
    GENERATED_BODY()

    UPROPERTY()
    FVector Location;

    UPROPERTY()
    FVector SupportPoint;

    UPROPERTY()
    FVector DestinitionPoint;

    UPROPERTY()
    APawn* Instigator;

    UPROPERTY()
    float CanonDamage;
};