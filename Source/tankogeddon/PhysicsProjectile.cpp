#include "PhysicsProjectile.h"

#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

#include <DrawDebugHelpers.h>
#include "Kismet/KismetMathLibrary.h"

#include "TimerManager.h"


APhysicsProjectile::APhysicsProjectile(){
    TrailEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TrailEffect"));
    TrailEffect->SetupAttachment(Mesh);
}

void APhysicsProjectile::SetPrestartData(FPhysicsProjectilePreStartData PrestartData){
    SetActorLocation(PrestartData.Location);
    SetInstigator(PrestartData.Instigator);

    ShotDamage = ProjectileDamage + PrestartData.CanonDamage;

    TargetPoint = PrestartData.DestinitionPoint;
    SupportPoint = PrestartData.SupportPoint;
    StartPoint = PrestartData.Location;
}

void APhysicsProjectile::Start(){
	bIsUsing = true;
	Mesh->SetVisibility(true);
    CurrentSpeed = MoveSpeed;
    // SetActorLocation(StartData.Location);
    // SetInstigator(StartData.Instigator);

    // ShotDamage = ProjectileDamage + StartData.CanonDamage;

    // TargetPoint = StartData.Instigator->GetActorLocation();
    // StartPoint = GetActorLocation();

    bIsFlying = (TargetPoint != StartPoint);
    if(!(bIsFlying)){
        End();
        return;
    }
    // float StartDistance = FVector::Distance(StartPoint, TargetPoint);

    // float SupportPointX;
    // if(StartPoint.X < TargetPoint.X) SupportPointX = StartPoint.X + StartDistance;
    // else                             SupportPointX = StartPoint.X - StartDistance;

    // float SupportPointZ = StartPoint.Z + StartDistance;

    // SupportPoint = FVector(SupportPointX, 0, SupportPointZ);

    GetWorld()->GetTimerManager().SetTimer(MovementTimerHandle, this, &APhysicsProjectile::Move, MoveRate, true, MoveRate);
}

void APhysicsProjectile::End(){
	bIsUsing  = false;
    bIsFlying = false;
	Mesh->SetVisibility(false);

	SetActorLocation(FVector(0.f));

	GetWorld()->GetTimerManager().ClearTimer(MovementTimerHandle);
}

void APhysicsProjectile::Move(){
    if(!(bIsFlying))
        End();

    FVector CurrentLocation = GetActorLocation();

    UE_LOG(LogTemp, Display, TEXT("%s %s %s"), *TargetPoint.ToString(), *SupportPoint.ToString(), *CurrentLocation.ToString());

    float StartDistance = FVector::Distance(StartPoint, TargetPoint);
    float DistanceReached = FVector::Distance(StartPoint, CurrentLocation);
    float DistanceLeft = FVector::Distance(CurrentLocation, TargetPoint);

    if ((StartDistance > DistanceReached + DistanceLeft) || (StartDistance < FMath::Abs(DistanceReached - DistanceLeft)))
        End();
    else {
        FVector RelativeLocation = (SupportPoint - CurrentLocation);
        FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(RelativeLocation, FVector(0.f, 0.f, 1));
        SetActorRotation(Rotation);

        CurrentSpeed; 
        if(CurrentLocation.Z <= SupportPoint.Z) CurrentSpeed = FMath::Lerp(CurrentSpeed, MoveSpeed * SlowestSpeedAdjuster, MoveRate * 2);
        else                                    CurrentSpeed = FMath::Lerp(CurrentSpeed, MoveSpeed * HighestSpeedAdjuster, MoveRate * 2);
        
        UE_LOG(LogTemp, Display, TEXT("%f"), CurrentSpeed);

        FVector ToTargetPointDirection = TargetPoint - SupportPoint;
        ToTargetPointDirection.Normalize();
        SupportPoint = SupportPoint + ToTargetPointDirection * CurrentSpeed * MoveRate;

        FVector ToSupportPointDirection = SupportPoint - CurrentLocation;
        ToSupportPointDirection.Normalize();
        SetActorLocation(CurrentLocation + ToSupportPointDirection * CurrentSpeed * MoveRate);

        DrawDebugLine(GetWorld(), CurrentLocation, SupportPoint, FColor::Yellow, true, -1, 4, 10);
        DrawDebugLine(GetWorld(), SupportPoint, TargetPoint, FColor::Red, true, -1, 4, 10);

        if (GetActorLocation() == TargetPoint) {
            End();

            DoExplodeHit();
            OnExplodeEffects();
        }
    }

    //DrawDebugPoint(GetWorld(), StartPoint, 50, FColor::Green, true, 1);
    //DrawDebugPoint(GetWorld(), GetActorLocation(), 50, FColor::Yellow, true, 1);
    //DrawDebugPoint(GetWorld(), SupportPoint, 50, FColor::Orange, true, 1);
    //DrawDebugPoint(GetWorld(), TargetPoint, 50, FColor::Red, true, 1);
}

float APhysicsProjectile::GetProjectileMoveSpeed(){
    return MoveSpeed;
}