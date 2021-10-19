#pragma once


#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
//#include "EquipmentStats.h"
#include "Engine/DataTable.h"
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
struct FObstacle{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Meta = (MakeEditWidget = true))
	TArray<FVector2D> Points;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<FLinearColor> Color;
};

// USTRUCT(BlueprintType)
// struct FHelpersEquipmentStats{
//     GENERATED_BODY()

//     UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
//     float ShootingSpeed;
//     UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
//     float ShootingRatio;
//     UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
//     float ShootingDamage;

//     UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
//     float MaxHealth;
//     UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
//     float MaxArrmor;
//     UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
//     float MoivingSpeed;
// };

USTRUCT(BlueprintType)
struct FTurretInformation : public FTableRowBase{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText MainDescription;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FSlateBrush Thumbnail;

    // UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	// FHelpersEquipmentStats EquipmentStats;
};