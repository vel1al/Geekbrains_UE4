// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "IScoreCounter.h"
#include "IEmeny.h"
#include "IDamakeTaker.h"


AProjectile::AProjectile(){
    PrimaryActorTick.bCanEverTick = false;
    USceneComponent* sceeneCpm = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = sceeneCpm;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
	Mesh->SetVisibility(false);

    Mesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnMeshOverlapBegin);
    Mesh->SetCollisionObjectType(ECC_GameTraceChannel1);
}

void AProjectile::SetMoveRange(const float value){
    MoveRange = value;
}

void AProjectile::BeginPlay(){
	Super::BeginPlay();

	
	World = GetWorld();
}

void AProjectile::EndPlay(EEndPlayReason::Type Reason){
	MovementTimerHandle.Invalidate();
    World = nullptr;

	Super::EndPlay(Reason);
}

void AProjectile::Start(FProjectilePreStartData StartData){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Projectile: start"));

	bIsUsing = true;
	Mesh->SetVisibility(true);

	SetActorRotation(StartData.Rotation);

    SetInstigator(StartData.Instigator);

    ShotDamage = ProjectileDamage + StartData.CanonDamage;
	PassedWay = 0.f;

    SetActorLocation(StartData.Location);
    GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &AProjectile::Move, MoveRate, true, MoveRate);
}

void AProjectile::End(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Projectile: end"));

	bIsUsing = false;
	Mesh->SetVisibility(false);

	SetActorLocation(FVector(0.f));

	GetWorld()->GetTimerManager().ClearTimer(MovementTimerHandle);
}

void AProjectile::Move(){
	FVector MoveOffset = GetActorForwardVector() * MoveSpeed * MoveRate;
    FVector TargetPosition = GetActorLocation() + MoveOffset;

	PassedWay += MoveOffset.Size2D();

	if(PassedWay >= MoveRange)
		End();
	else	
    	SetActorLocation(TargetPosition);
}

void AProjectile::OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    
	if (OtherActor != GetInstigator() && !OtherActor->GetClass()->IsChildOf(StaticClass())){
        bool bIsDestroyed = false;
        UE_LOG(LogTemp, Display, TEXT("Projectile %s, other actor %s, instigator %s"), *GetName(), *OtherActor->GetName(), *GetInstigator()->GetName());


        IIDamakeTaker* DamagedActor = Cast<IIDamakeTaker>(OtherActor);
        if (DamagedActor){
            FDamageData DamageData;
            DamageData.DamageValue = ShotDamage;
            DamageData.Instigator = GetInstigator();
            DamageData.DamageMaker = this;

            bIsDestroyed = DamagedActor->CauseDamage(DamageData);
        }

        if (bIsDestroyed && GetInstigator()){
            IIScoreCounter* ScoredActor = Cast<IIScoreCounter>(GetInstigator());
            IIEmeny* EmenyActor = Cast<IIEmeny>(OtherActor);

            if(ScoredActor && EmenyActor)
                ScoredActor->IncrementScore(EmenyActor->GetScoreValue());

            if (OnElminated.IsBound())
                OnElminated.Broadcast();
        }

        End();
    }
}

bool AProjectile::IsUsing() const{
	return bIsUsing;
}