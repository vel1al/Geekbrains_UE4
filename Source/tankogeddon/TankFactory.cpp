#include "TankFactory.h"
#include "ILevelChanger.h"
#include "TankPawn.h"

#include <Components/StaticMeshComponent.h>
#include <Components/ArrowComponent.h>
#include <Components/BoxComponent.h>
#include <Components/AudioComponent.h>
#include <Camera/CameraShake.h>
#include <Particles/ParticleSystemComponent.h>
#include "GameFramework/ForceFeedbackEffect.h"

#include "Kismet/GameplayStatics.h"


ATankFactory::ATankFactory(){
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
    
    OnNewTankSpawnEffect = CreateDefaultSubobject<UParticleSystemComponent>("OnNewTankEffect");
	OnNewTankSpawnEffect->SetupAttachment(DefaultMesh);

    OnNewTankSpawnAudioEffect = CreateDefaultSubobject<UAudioComponent>("OnNewTankAudioEffect");
	OnNewTankSpawnAudioEffect->SetupAttachment(DefaultMesh);
}

void ATankFactory::OnDieEvent(){
    IILevelChanger* ILevelChanger = Cast<IILevelChanger>(LevelChanger);
	if(ILevelChanger)
        ILevelChanger->SetActive(true);
    
    ChangeMeshState(false);

    GetWorld()->GetTimerManager().ClearTimer(TankSpawningDelayTimerHandle);

    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestroyedEffect, GetActorTransform());
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), DestroyedAudioEffect, GetActorLocation());

    if(ColapseForceEffect){
		FForceFeedbackParameters ColapseForceEffectParams;

		ColapseForceEffectParams.bLooping = false;
		ColapseForceEffectParams.Tag = "ColapseForceEffectParams";
		
        GetWorld()->GetFirstPlayerController()->ClientPlayForceFeedback(ColapseForceEffect,ColapseForceEffectParams);
	}

	if(ColapseShake)
        GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(ColapseShake);	
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

    OnNewTankSpawnEffect->ActivateSystem();
	OnNewTankSpawnAudioEffect->Play();
}