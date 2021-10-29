#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameStructs.h"
#include "DamageTaker.generated.h"

class UWidgetComponent;
class UHPBarWidget;


UCLASS()
class TANKOGEDDON_API ADamageTaker : public APawn{
		GENERATED_BODY()

	public:
		ADamageTaker();
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthValue");
		UWidgetComponent* HPBar;

		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
    	class USoundBase* DestroyedAudioEffect;
		UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Effects")
		class UParticleSystem* DestroyedEffect;

		// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthValues")
		// float MaxHealth = 10;
		// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthValues")
		// float MaxArmor = 10;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleStats")
		FVehicleStats DefaultStats;
	
		bool CauseDamage(FDamageData DamageData);
		bool IsDestroyed() const;

		// float GetHealth() const;
		// float GetArmor() const;
		//
		// float GetHealthState() const;

		// void AddHealth(float AdditionalHealthValue);
		// void AddArmor(const float AdditionalArmorValue);

		void ModifyStats(const FVehicleStats& AdditionalValue);
		void SetStats(const FVehicleStats& SetValue);
	
		FVehicleStats GetStats() const;
	
	protected:
		UHPBarWidget* HPBarWidget;

		virtual void BeginPlay() override;
		virtual void OnDieEvent();

		// float CurrentHealth;
		// float CurrentArmor;

		FVehicleStats CurrentStats;
	
		bool bIsDestroyed;
};
