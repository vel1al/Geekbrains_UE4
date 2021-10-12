#pragma once


#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "GameStructs.generated.h"


UENUM(BlueprintType)
enum class ECannonType : uint8{
    FireProjectile = 0 UMETA(DisplayName = "Projectile"),
    FireRay = 1 UMETA(DisplayName = "Raycast")
};

UENUM()
enum class EWidget : uint8 {
	None,
    MainMenu,
    Pause,
    HUD,
	GameOver
};

UENUM()
enum class ETheme : uint8 {
    None,
    Bright,
    Dark
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

USTRUCT(BlueprintType)
struct FFigure{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Meta = (MakeEditWidget = true))
	TArray<FVector2D> Points;
};

USTRUCT(BlueprintType)
struct FObstacle{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Meta = (MakeEditWidget = true))
	TArray<FVector2D> Points;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<FLinearColor> Color;
};