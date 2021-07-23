#include "TankFactory.h"
#include "ILevelChanger.h"
#include <Components/StaticMeshComponent.h>
#include <Components/ArrowComponent.h>
#include <Components/BoxComponent.h>
#include <Components/AudioComponent.h>
#include <Camera/CameraShake.h>
#include <Particles/ParticleSystemComponent.h>
#include "GameFramework/ForceFeedbackEffect.h"
#include "HealthComponent.h"
#include "TankPawn.h"


ATankFactory::ATankFactory(){
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* sceeneCpm = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = sceeneCpm;

    DefaultMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DefaultMesh"));
    DefaultMesh->SetupAttachment(RootComponent);

    ColapsedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ColpasedMesh"));
    ColapsedMesh->SetupAttachment(RootComponent);

    TankSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("TankSpawnPoint"));
    TankSpawnPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

    HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
    HitBox->SetupAttachment(RootComponent);

    HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
    HealthComponent->OnDie.AddUObject(this, &ATankFactory::Die);

    ColapseEffect = CreateDefaultSubobject<UParticleSystemComponent>("ColapseEffect");
	ColapseEffect->SetupAttachment(ColapsedMesh);

    ColapseAudioEffect = CreateDefaultSubobject<UAudioComponent>("ColapseAudioEffect");
	ColapseAudioEffect->SetupAttachment(ColapsedMesh);
    
    OnNewTankSpawnEffect = CreateDefaultSubobject<UParticleSystemComponent>("OnNewTankEffect");
	OnNewTankEffect->SetupAttachment(DefaultdMesh);

    OnNewTankAudioEffect = CreateDefaultSubobject<UAudioComponent>("OnNewTankAudioEffect");
	OnNewTankAudioEffect->SetupAttachment(DefaultMesh);

    bIsColapsed = false;
}

bool ATankFactory::CauseDamage(FDamageData DamageData){
    return HealthComponent->TakeDamage(DamageData);
}

void ATankFactory::Die(){
    if(IsDestroyed())
        return;


    IILevelChanger* ILevelChanger = Cast<IILevelChanger>(LevelChanger);
	if(ILevelChanger)
        ILevelChanger->SetActive(true);
    

    ChangeMeshState(false);


    GetWorld()->GetTimerManager().ClearTimer(TankSpawningDelayTimerHandle);

    ColapseEffect->ActivateSystem();
	ColapseAudioEffect->Play();

    if(ColapseForceEffect){
		FForceFeedbackParameters ColapseForceEffectParams;

		ColapseForceEffectParams.bLooping = false;
		ColapseForceEffectParams.Tag = "ColapseForceEffectParams";
		
        GetWorld()->GetFirstPlayerController()->ClientPlayForceFeedback(ColapseForceEffect,ColapseForceEffectParams);
	}

	if(ColapseShake)
        GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(ColapseShake);

    bIsColapsed = true;		
}

int ATankFactory::GetScoreValue() const {
    if(IsDestroyed())
        return 0;

	return ElminatedScoreValue;
}

void ATankFactory::Destroyed(){
    GetWorld()->GetTimerManager().ClearTimer(TankSpawningDelayTimerHandle);
}

void ATankFactory::BeginPlay(){
	Super::BeginPlay();
	

    ChangeMeshState(true);


	IILevelChanger* ILevelChanger = Cast<IILevelChanger>(LevelChanger);
	if(ILevelChanger)
        ILevelChanger->SetActive(false);
    

    GetWorld()->GetTimerManager().SetTimer(TankSpawningDelayTimerHandle, this, &ATankFactory::SpawnNewTank, SpawnRate, true, SpawnRate);
}

void ATankFactory::ChangeMeshState(const bool bState){
	DefaultMesh->SetVisibility(bState);
    ColapsedMesh->SetVisibility(!bState);
}

void ATankFactory::SpawnNewTank(){
    FTransform SpawnTransform(TankSpawnPoint->GetComponentRotation(), TankSpawnPoint->GetComponentLocation(), FVector(1));

    ATankPawn* NewTank = GetWorld()->SpawnActorDeferred<ATankPawn>(DefaultTankClass, SpawnTransform, this, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	NewTank->LocalPatrollingPoints = PatrollingWays;
	NewTank->FinishSpawning(SpawnTransform);

    OnNewTankEffect->ActivateSystem();
	OnNewTankAudioEffect->Play();
}

bool ATankFactory::IsDestroyed() const {
    return bIsColapsed;
}