#include "TankAIController.h"
#include "TankPawn.h"
#include <DrawDebugHelpers.h>


void ATankAIController::BeginPlay(){
    Super::BeginPlay();


    Initialize();
}

void ATankAIController::Tick(float DeltaTime){
    Super::Tick(DeltaTime);


    if (!ControllingTank || LastPatroolPointIndex == INDEX_NONE){
        Initialize();

        if (!ControllingTank || LastPatroolPointIndex == INDEX_NONE)
            return;
    }

    FVector ControllingTankLocation = ControllingTank->GetActorLocation();
    if (FVector::Distance(CurrentPatroolPoint, ControllingTankLocation) <= ControllingTank->TankMovementAccurancy)
        if(!(GlobalPatrollingPoints.IsValidIndex(++LastPatroolPointIndex)))
           LastPatroolPointIndex = 0;

    bool bPlayerVisibility = false;

    CurrentPatroolPoint = GlobalPatrollingPoints[LastPatroolPointIndex];

    FVector TankForwardVector = ControllingTank->GetActorForwardVector();
    FVector MoveDirection = CurrentPatroolPoint - ControllingTankLocation;

    MoveDirection.Normalize();
    
    DrawDebugLine(GetWorld(), ControllingTankLocation, CurrentPatroolPoint, FColor::Yellow, false, 5.f, 0, 5); 

    float AngleOfReferenceControllingTank = FMath::RadiansToDegrees(FMath::Atan2(TankForwardVector.Y, TankForwardVector.X));
    float AngleOfReferenceMoveDirection = FMath::RadiansToDegrees(FMath::Atan2(MoveDirection.Y, MoveDirection.X));

    float SignedAngle = AngleOfReferenceMoveDirection - AngleOfReferenceControllingTank; 
    
    
    if (SignedAngle > 180) SignedAngle -= 360;
    if (SignedAngle <= -180) SignedAngle += 360;

    float TankRotationTorque = 0;
    if(FMath::Abs(SignedAngle) > 5){
        if(SignedAngle > 0)
            TankRotationTorque = 1;
        else
            TankRotationTorque = -1;
    }

    ControllingTank->SetRotateTorqueZAxis(TankRotationTorque);
    ControllingTank->SetMoveTorqueXAxis(1);


    APawn* TargetTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (TargetTank){
        FVector TargetTankLocation = TargetTank->GetActorLocation();

        if (FVector::Distance(TargetTankLocation, ControllingTankLocation) < TargetingRange){
            FCollisionQueryParams Params(FName(TEXT("VeiewCheck")), true, this);
            FHitResult HitResult;

            Params.AddIgnoredActor(ControllingTank);
            Params.bReturnPhysicalMaterial = false;

            if (GetWorld()->LineTraceSingleByChannel(HitResult, ControllingTank->GetLookFromPosition(), TargetTankLocation, ECC_Visibility, Params)){
                if (HitResult.Actor.IsValid()){
                    bPlayerVisibility = HitResult.Actor.Get() == TargetTank;

                    DrawDebugLine(GetWorld(), ControllingTank->GetLookFromPosition(), HitResult.Location, FColor::Red, false, 5.f, 0, 5); 
                }
                else
                    DrawDebugLine(GetWorld(), ControllingTank->GetLookFromPosition(), HitResult.Location, FColor::Green, false, 5.f, 0, 5);
            }  
        }

        if (bPlayerVisibility){
            FVector DirectionToPlayer = TargetTankLocation - ControllingTankLocation;
            FVector TurretDirection = ControllingTank->GetTurretDirection();

            DirectionToPlayer.Normalize();
            
            float AngleOfReferencePlayer = FMath::RadiansToDegrees(FMath::Atan2(DirectionToPlayer.Y, DirectionToPlayer.X));
            float AngleOfReferenceTurret = FMath::RadiansToDegrees(FMath::Atan2(TurretDirection.Y, TurretDirection.X));

            SignedAngle = AngleOfReferenceTurret - AngleOfReferencePlayer;

            if (SignedAngle > 180) SignedAngle -= 360;
            if (SignedAngle <= -180) SignedAngle += 360;

            UE_LOG(LogTemp, Display, TEXT("%f"), SignedAngle);

            if (FMath::Abs(SignedAngle) > ControllingTank->TankTargettingAccurancy){
                float TurretRotationTorque = 0;
                
                if(SignedAngle > 0)
                    TurretRotationTorque = -1;
                else
                    TurretRotationTorque = 1;

                ControllingTank->SetRotateTurretTorqueZAxis(TurretRotationTorque);
            }
            else
                ControllingTank->FireMain();
        }
        else
            ControllingTank->RotateTurretToStart();
    }
    else
        ControllingTank->RotateTurretToStart();
}

void ATankAIController::Initialize() {
    ControllingTank = Cast<ATankPawn>(GetPawn());

    if (ControllingTank && ControllingTank->LocalPatrollingPoints.Num() > 0){
        LastPatroolPointIndex = 0;

        FVector TankLocation = ControllingTank->GetActorLocation();

        UE_LOG(LogTemp, Display, TEXT("%d"), ControllingTank->LocalPatrollingPoints.Num());

        for (const auto& element : ControllingTank->LocalPatrollingPoints)
            GlobalPatrollingPoints.Add(TankLocation + element);    
    }
}