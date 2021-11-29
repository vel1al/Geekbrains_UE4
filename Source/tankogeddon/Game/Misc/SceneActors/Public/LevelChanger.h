// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ILevelChanger.h"
#include "LevelChanger.generated.h"

UCLASS()
class TANKOGEDDON_API ALevelChanger : public AActor, public IILevelChanger{
		GENERATED_BODY()
		
	public:	
		// Sets default values for this actor's properties
		ALevelChanger();

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* Mesh;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UBoxComponent* TriggerBox;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UPointLightComponent* Light;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
    	class UAudioComponent* ActivatedAudioEffect;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelChanger|General")
		FName LoadLevelName;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelChanger|General")
		bool bIsActivated = false;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelChanger|Light")
		FLinearColor DeactiveState;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelChanger|Light")
		FLinearColor ActiveState;

		UFUNCTION(BlueprintCallable, Category = "LevelChanger")
		void SetActive(bool bState) override;

	protected:
		virtual void BeginPlay() override;

	private:
		bool bIsActive = false;

		void ChangeLightState(bool bState);
		void OnActivated();

		UFUNCTION()
		void OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
								UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};