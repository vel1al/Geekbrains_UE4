#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStructs.h"
#include "DamageTaker.generated.h"


UCLASS()
class TANKOGEDDON_API UDamageTaker : virtual public UObject{
		GENERATED_BODY()

	public:
		UDamageTaker();

		DECLARE_EVENT(UHealthComponent, FOnDie)
		DECLARE_EVENT_OneParam(UHealthComponent, FOnHealthChanged, float)

		FOnDie OnDie;
		FOnHealthChanged OnTookDamage;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;

		bool TakeDamage(FDamageData DamageData);
		bool IsDestroyed() const;

		float GetHealth() const;
		float GetHealthState() const;

		void AddHealth(float AddiditionalHealthValue);

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthValues")
		float MaxHealth = 10;

		float CurrentHealth;

		bool bIsDestroyed;
};
