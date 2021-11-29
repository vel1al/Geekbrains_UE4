#include "tankogeddon/Game/Misc/Components/Public/Projectile.h"

#include "Components/StaticMeshComponent.h"

#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

#include "tankogeddon/Game/Vehicles/Player/Public/PlayerVehicle.h"
#include "tankogeddon/Game/Vehicles/Player/Public/TankPlayerState.h"
#include "tankogeddon/Game/Vehicles/HealthComponent.h"
#include "tankogeddon/Game/Misc/Destructible.h"


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

void AProjectile::EndPlay(EEndPlayReason::Type Reason){
	MovementTimerHandle.Invalidate();

	Super::EndPlay(Reason);
}

void AProjectile::SetPrestartData(FProjectilePreStartData PrestartData){
	SetActorRotation(PrestartData.Rotation);
    SetInstigator(PrestartData.Instigator);

    ShotDamage = ProjectileDamage + PrestartData.CanonDamage;

    SetActorLocation(PrestartData.Location);
}

void AProjectile::Start(){
	UE_LOG(LogTemp, Display, TEXT("Projectile %s is start"), *GetName());

	bIsUsing = true;
    Mesh->SetVisibility(true);
    PassedWay = 0.f;
    
    GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &AProjectile::Move, MoveRate, true, MoveRate);
}

void AProjectile::End(){
	UE_LOG(LogTemp, Display, TEXT("Projectile %s is end"), *GetName());

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

void AProjectile::DoExplodeHit() {
    FVector CurrentLocation = GetActorLocation();

    TArray<FHitResult> OnExplodeHits;
    FCollisionShape ColisionShape = FCollisionShape::MakeSphere(ProjectileExplosionRadius);

    FCollisionQueryParams Settings = FCollisionQueryParams::DefaultQueryParam;
    Settings.AddIgnoredActor(this);
    Settings.bTraceComplex = true;
    Settings.TraceTag = "ExplodeTrace";


    bool ExplodeSweepResult = GetWorld()->SweepMultiByChannel(OnExplodeHits,
        CurrentLocation,
        CurrentLocation + FVector(0.1f),
        FQuat::Identity,
        ECollisionChannel::ECC_Visibility,
        ColisionShape,
        Settings);

    GetWorld()->DebugDrawTraceTag = "ExplodeTrace";

    if (ExplodeSweepResult) 
        for (FHitResult CurrentHit : OnExplodeHits) {
            AActor* CurrentHitActor = CurrentHit.GetActor();

            if (!CurrentHitActor)
                continue;

            AplyDamage(CurrentHitActor);
            AplyPushForce(CurrentHitActor);
        }
    
    OnExplodeEffects();
}

void AProjectile::DoFlatHit(AActor* OtherActor) {
    bool bIsDestroyed = false;

    AplyDamage(OtherActor);
    AplyPushForce(OtherActor);
}

void AProjectile::OnExplodeEffects() const {
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorTransform());
    UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionAudioEffect, GetActorLocation());
}

void AProjectile::AplyDamage(AActor* OtherActor){
    bool bIsDestroyed;
    
    IDestructible* DamagedActor = Cast<IDestructible>(OtherActor);
    if (DamagedActor) {
        FDamageData DamageData;
        DamageData.DamageValue = ShotDamage;
        DamageData.Instigator = GetInstigator();
        DamageData.DamageMaker = this;

        bIsDestroyed = DamagedActor->GetHealthComponent()->CauseDamage(DamageData);

		if (bIsDestroyed){
            APlayerVehicle* ScoredActor = Cast<APlayerVehicle>(GetInstigator());
            if(ScoredActor){
                 ATankPlayerState* PlayerState = Cast<ATankPlayerState>(ScoredActor->GetPlayerState());
                if(PlayerState)
                    PlayerState->IncrementScore(1, OtherActor);
            }
			else{
                APlayerVehicle* Player = Cast<APlayerVehicle>(OtherActor);
                if(Player){
                    ATankPlayerState* PlayerState = Cast<ATankPlayerState>(Player->GetPlayerState());
                    if(PlayerState)
                        PlayerState->PlayerDie();
                }
			}
		}
    }
}

void AProjectile::AplyPushForce(AActor* OtherActor){
    UPrimitiveComponent* TouchedMesh = Cast<UPrimitiveComponent>(OtherActor->GetRootComponent());
    if (TouchedMesh) {
        if (TouchedMesh->IsSimulatingPhysics()) {
            FVector ForceVector = OtherActor->GetActorLocation() - GetActorLocation();
            ForceVector.Normalize();

            TouchedMesh->AddImpulse(ForceVector * PushForce, NAME_None, true);
        }
    }
}


void AProjectile::OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    if (OtherActor == GetInstigator() || OtherActor->GetClass()->IsChildOf(StaticClass()))
        return; 

    if (bIsExploding)
        DoExplodeHit();
    else
        DoFlatHit(OtherActor);

    End();    
}

bool AProjectile::IsUsing() const{
    UE_LOG(LogTemp, Display, TEXT("Projectile %s is %s"), *GetName(), (bIsUsing ? TEXT("true") : TEXT("false")));

	return bIsUsing;
}