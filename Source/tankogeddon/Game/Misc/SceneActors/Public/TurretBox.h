#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretBox.generated.h"

class USpotLightComponent;
class UPrimitiveComponent;
class UFloatingMesh;
class ATurretBase;


UCLASS()
class TANKOGEDDON_API ATurretBox : public AActor{
		GENERATED_BODY()
		
	public:	
		ATurretBox();

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UFloatingMesh* Mesh;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		USpotLightComponent* Light;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box|Turret")
		TSubclassOf<ATurretBase> TurretClass;


	protected:
		UFUNCTION()
		void OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
