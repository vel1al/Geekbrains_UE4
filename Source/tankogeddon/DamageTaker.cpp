#include "DamageTaker.h"

#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"

#include "Kismet/GameplayStatics.h"
#include "Components/WidgetComponent.h"
#include "HPBarWidget.h"


ADamageTaker::ADamageTaker(){
	PrimaryActorTick.bCanEverTick = true;
    
    HPBar = CreateDefaultSubobject<UWidgetComponent>("HPBar");
    HPBar->SetWidgetClass(UHPBarWidget::StaticClass());

    HPBarWidget = Cast<UHPBarWidget>(HPBar->GetUserWidgetObject());
    HPBarWidget->SetHP(MaxHealth/MaxHealth);

	CurrentHealth = MaxHealth;
}

bool ADamageTaker::CauseDamage(FDamageData DamageData){
    if(IsDestroyed())
        return false;
    
    float TakenDamageValue = DamageData.DamageValue;
    bool bWasDestroyed = false;

	CurrentHealth -= TakenDamageValue;
    if (CurrentHealth <= 0){
        bWasDestroyed = true;
        HPBarWidget->SetHP(0);
    }
    else
        HPBarWidget->SetHP(CurrentHealth/MaxHealth);

	bIsDestroyed = bWasDestroyed;
	if(bIsDestroyed)
		OnDieEvent();

    return bWasDestroyed;
}

bool ADamageTaker::IsDestroyed() const {
	return bIsDestroyed;
}

float ADamageTaker::GetHealth() const{
    return CurrentHealth;
}

float ADamageTaker::GetHealthState() const{
    return CurrentHealth / MaxHealth;
}

void ADamageTaker::AddHealth(const float AddiditionalHealthValue){
    CurrentHealth += AddiditionalHealthValue;

    if (CurrentHealth > MaxHealth)
        CurrentHealth = MaxHealth;

    HPBarWidget->SetHP(CurrentHealth/MaxHealth);    
}

void ADamageTaker::OnDieEvent() {
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestroyedEffect, GetActorTransform());
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), DestroyedAudioEffect, GetActorLocation());
}