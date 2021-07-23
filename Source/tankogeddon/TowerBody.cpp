#include "TowerBody.h"
#include "TowerTurret.h"
#include "Components/StaticMeshComponent.h"
#include <Components/BoxComponent.h>
#include "Components/ArrowComponent.h"
#include <Components/AudioComponent.h>
#include "HealthComponent.h"
#include <DrawDebugHelpers.h>
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include <Particles/ParticleSystemComponent.h>

ATowerBody::ATowerBody(){
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* sceeneCpm = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = sceeneCpm;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret body"));

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
    HealthComponent->OnDie.AddUObject(this, &ATowerBody::Die);
    HealthComponent->OnTookDamage.AddUObject(this, &ATowerBody::DamageTook);

	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->SetupAttachment(RootComponent);

	TurretSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("TurretSetupPoint"));
	TurretSetupPoint->AttachToComponent(BodyMesh, FAttachmentTransformRules::KeepRelativeTransform);
}

bool ATowerBody::CauseDamage(FDamageData DamageData){
    return HealthComponent->TakeDamage(DamageData);
}

void ATowerBody::Die(){
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Red, TEXT("Tower: was destroyed"));

	bIsDestroyed = true;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestroyedEffect, GetActorTransform());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), DestroyedAudioEffect, GetActorLocation());

	InvalidateTurret();
	Destroy();
}

void ATowerBody::DamageTook(float DamageValue){
	GEngine->AddOnScreenDebugMessage(10, 5.f, FColor::Orange, TEXT("Tower took damage"));
}

void ATowerBody::SetUpTurret(TSubclassOf<class ATowerTurret> NewTurretClass){
	if(Turret)
		InvalidateTurret();

	FActorSpawnParameters Params;
    Params.Owner = this;
	Params.Instigator = this;

    Turret = GetWorld()->SpawnActor<ATowerTurret>(NewTurretClass, Params);
    Turret->AttachToComponent(TurretSetupPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void ATowerBody::InvalidateTurret(){
	if(Turret){
		Turret->Destroy();
		Turret = nullptr;
	}
}

void ATowerBody::BeginPlay(){
	Super::BeginPlay();

	SetUpTurret(DefaultTurretClass);
    PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	AngleToPlayer = GetAngleToPlayer();

	TargetingSpeed = 1.f / (360.f / TargetingSpeedDegrees);
}

void ATowerBody::EndPlay(EEndPlayReason::Type Reason){
    Super::EndPlay(Reason);


    InvalidateTurret();
}

void ATowerBody::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);


	if(CheckRange())
		if(IsPlayerInView()){
			RotateTurretYAxis();

			AngleToPlayer = GetAngleToPlayer();

			if(AngleToPlayer < Accurency)
				Fire();
		}
}

void ATowerBody::RotateTurretYAxis(){
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(Turret->GetActorLocation(), PlayerPawn->GetActorLocation());
	FRotator CurrentRotation = Turret->GetTurretMeshRotation();

	TargetRotation.Pitch = CurrentRotation.Pitch;
	TargetRotation.Roll = CurrentRotation.Roll;

	Turret->SetTurretMeshRotation(FMath::Lerp(CurrentRotation, TargetRotation, TargetingSpeed));
}

bool ATowerBody::CheckRange(){
	if(PlayerPawn)
    	return FVector::Distance(PlayerPawn->GetActorLocation(), GetActorLocation()) <= TargetingRange;

	return false;
}

void ATowerBody::Fire(){
	if(Turret)
		Turret->FireMain();
}

int ATowerBody::GetScoreValue() const{
	if(IsDestroyed())
		return 0;

	return ScoreValue;
}

FVector ATowerBody::GetTurretDirection() const {
	return Turret->GetTurretMeshDirection();
}

bool ATowerBody::IsPlayerInView(){
    APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (PlayerTank){
        FCollisionQueryParams Params(FName(TEXT("VeiewCheck")), true, this);
        FHitResult HitResult;

        Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(Turret);
        Params.bReturnPhysicalMaterial = false;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, Turret->GetActorLocation(), PlayerTank->GetActorLocation(), ECC_Visibility, Params))
            if (HitResult.Actor.IsValid()){
				DrawDebugLine(GetWorld(), Turret->GetActorLocation(), HitResult.Location, FColor::Red, false, 5.f, 0, 5);
               	return HitResult.Actor.Get() == PlayerTank;
			}
		
		DrawDebugLine(GetWorld(), Turret->GetActorLocation(), HitResult.Location, FColor::Green, false, 5.f, 0, 5);

		return false;
	}

	return false;
}

float ATowerBody::GetAngleToPlayer() {
	if(!(PlayerPawn))
		return 0.f;

	FVector TargetingDirection = GetTurretDirection();
    FVector DirectionToPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();

    DirectionToPlayer.Normalize();

	return FMath::RadiansToDegrees(acosf(FVector::DotProduct(TargetingDirection, DirectionToPlayer)));
}

bool ATowerBody::IsDestroyed() const {
    return bIsDestroyed;
}