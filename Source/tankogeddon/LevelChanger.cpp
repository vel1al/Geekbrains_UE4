#include "LevelChanger.h"
#include <Components/StaticMeshComponent.h>
#include <Components/PointLightComponent.h>
#include <Components/BoxComponent.h>
#include <Kismet/GameplayStatics.h>
#include <Components/AudioComponent.h>


ALevelChanger::ALevelChanger(){
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* sceeneCpm = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = sceeneCpm;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);

    Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
    Light->SetupAttachment(RootComponent);

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
    TriggerBox->SetupAttachment(RootComponent);
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelChanger::OnTriggerOverlapBegin);

    ActivatedAudioEffect = CreateDefaultSubobject<UAudioComponent>("ActivatedAudioEffect");
	ActivatedAudioEffect->SetupAttachment(RootComponent);
}

void ALevelChanger::SetActive(bool bState){
    bIsActive = bState;

    ChangeLightState(bState);
    if(bState)
        OnActivated();
}

void ALevelChanger::BeginPlay(){
	Super::BeginPlay();


    ChangeLightState(false);
}

void ALevelChanger::ChangeLightState(bool bState){
    switch (bState){
        case true:
            Light->SetLightColor(ActiveState, true);
            break;
        
        case false:
            Light->SetLightColor(DeactiveState, true);
            break;
    }
}

void ALevelChanger::OnActivated() {
    ActivatedAudioEffect->Play();
}

void ALevelChanger::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (!bIsActive)
        return;

    APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (OtherActor == PlayerTank)
        UGameplayStatics::OpenLevel(GetWorld(), LoadLevelName);
}