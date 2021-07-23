#include "HealthComponent.h"
#include "IScoreCounter.h"


UHealthComponent::UHealthComponent(){
	PrimaryComponentTick.bCanEverTick = false;
	CurrentHealth = MaxHealth;
}

bool UHealthComponent::TakeDamage(FDamageData DamageData){
    float TakenDamageValue = DamageData.DamageValue;
    bool bWasDestroyed = false;

	CurrentHealth -= TakenDamageValue;
    if (CurrentHealth <= 0){  
        if (OnDie.IsBound())
            OnDie.Broadcast();
        
        bWasDestroyed = true;
    }
    else if (OnTookDamage.IsBound())
         OnTookDamage.Broadcast(TakenDamageValue);
        

    return bWasDestroyed;
}

float UHealthComponent::GetHealth() const{
    return CurrentHealth;
}

float UHealthComponent::GetHealthState() const{
    return CurrentHealth / MaxHealth;
}

void UHealthComponent::AddHealth(const float AddiditionalHealthValue){
    CurrentHealth += AddiditionalHealthValue;

    if (CurrentHealth > MaxHealth)
        CurrentHealth = MaxHealth;
    
}