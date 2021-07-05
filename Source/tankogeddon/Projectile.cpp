// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"


AProjectile::AProjectile(){
    PrimaryActorTick.bCanEverTick = false;
    USceneComponent* sceeneCpm = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = sceeneCpm;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
	//Mesh->SetVisibility(false);

    Mesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnMeshOverlapBegin);
    Mesh->SetCollisionObjectType(ECC_GameTraceChannel1);
}

void AProjectile::EndPlay(EEndPlayReason::Type Reason){
	MovementTimerHandle.Invalidate();

	Super::EndPlay(Reason);
}

void AProjectile::Start(FVector StartPosition, FRotator StartRotation){
	GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Orange, TEXT("Projectile: start"));

	//bIsUsing = true;
	//Mesh->SetVisibility(true);
	//SetActorLocation(StartPosition);
	//SetActorRotation(StartRotation);

    GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &AProjectile::Move, MoveRate, true, MoveRate);
	SetLifeSpan(MoveRange / MoveSpeed);
}

void AProjectile::End(){
	GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Orange, TEXT("Projectile: start"));

	bIsUsing = false;
	Mesh->SetVisibility(false);

	SetActorLocation(FVector(0.f, 0.f, 0.f));

	GetWorld()->GetTimerManager().ClearTimer(MovementTimerHandle);
}

void AProjectile::Move(){
	FVector CurrentPosition = GetActorLocation();
	FVector NextPosition = CurrentPosition + GetActorForwardVector() * MoveSpeed * MoveRate;

	//PassedWay += NextPosition.Size2D();

	//if(PassedWay >= MoveRange)
		//End();
	//else	
    SetActorLocation(NextPosition);
	
}

void AProjectile::OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    //UE_LOG(LogTemp, Warning, TEXT("Projectile %s collided with %s. "), *GetName(), *OtherActor->GetName());
    
	OtherActor->Destroy();
    Destroy();
}

bool AProjectile::IsUsing() const{
	return bIsUsing;
}