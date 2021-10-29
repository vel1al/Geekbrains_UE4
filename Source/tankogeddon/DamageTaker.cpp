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

	//CurrentHealth = MaxHealth;
    CurrentStats = DefaultStats;
}

void ADamageTaker::BeginPlay(){
    if(HPBarWidget)
        HPBarWidget->SetHP(1);
}

bool ADamageTaker::CauseDamage(FDamageData DamageData){
    if(IsDestroyed())
        return false;
    
    float RecivedDamageValue = DamageData.DamageValue * (CurrentStats.Armor / (CurrentStats.Armor + 30.f));
    bool bWasDestroyed = false;

	CurrentStats.Health -= RecivedDamageValue;
    CurrentStats.Armor -= DamageData.DamageValue;
    if (CurrentStats.Health <= 0){
        bWasDestroyed = true;
        
        if(HPBarWidget)
            HPBarWidget->SetHP(0);
    }
    else if(HPBarWidget)
        HPBarWidget->SetHP(CurrentStats.Health/DefaultStats.Health);

	bIsDestroyed = bWasDestroyed;
	if(bIsDestroyed)
		OnDieEvent();

    return bWasDestroyed;
}

bool ADamageTaker::IsDestroyed() const {
	return bIsDestroyed;
}

void ADamageTaker::ModifyStats(const FVehicleStats& AdditionalValue) {
    CurrentStats.Health += AdditionalValue.Health;
    CurrentStats.Armor += AdditionalValue.Armor;
    CurrentStats.SelfPower += AdditionalValue.SelfPower;
    CurrentStats.EquipmentWeight += AdditionalValue.EquipmentWeight;
}

void ADamageTaker::SetStats(const FVehicleStats& SetValue) {
    CurrentStats = SetValue;
}

FVehicleStats ADamageTaker::GetStats() const {
    return CurrentStats;
}

// float ADamageTaker::GetHealth() const{
//     return CurrentHealth;
// }
//
// float ADamageTaker::GetHealthState() const{
//     return CurrentHealth / MaxHealth;
// }
//
// void ADamageTaker::AddHealth(const float AddiditionalHealthValue){
//     CurrentHealth += AddiditionalHealthValue;
//
//     if (CurrentHealth > MaxHealth)
//         CurrentHealth = MaxHealth;
//     if(HPBarWidget)
//         HPBarWidget->SetHP(CurrentHealth/MaxHealth);    
// }

void ADamageTaker::OnDieEvent() {
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestroyedEffect, GetActorTransform());
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), DestroyedAudioEffect, GetActorLocation());
}