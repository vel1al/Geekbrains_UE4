#include "DamageTaker.h"


UDamageTaker::UDamageTaker() {
    CurrentHealth = MaxHealth;
}

bool UDamageTaker::CauseDamage(FDamageData DamageData) {
    float TakenDamageValue = DamageData.DamageValue;
    bool bWasDestroyed = false;

    CurrentHealth -= TakenDamageValue;
    if (CurrentHealth <= 0) {
        if (OnDie.IsBound())
            OnDie.Broadcast();

        bWasDestroyed = true;
    }
    else if (OnTookDamage.IsBound())
        OnTookDamage.Broadcast(TakenDamageValue);

    bIsDestroyed = bWasDestroyed;

    return bWasDestroyed;
}

bool UDamageTaker::IsDestroyed() const{
    return bIsDestroyed;
}

float UDamageTaker::GetHealth() const {
    return CurrentHealth;
}

float UDamageTaker::GetHealthState() const {
    return CurrentHealth / MaxHealth;
}

void UDamageTaker::AddHealth(const float AddiditionalHealthValue) {
    CurrentHealth += AddiditionalHealthValue;

    if (CurrentHealth > MaxHealth)
        CurrentHealth = MaxHealth;
}