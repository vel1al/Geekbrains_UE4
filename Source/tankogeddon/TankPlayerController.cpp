#include "TankPlayerController.h"
#include "TankPawn.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    TankPawn = Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis("MoveXAxis", this, &ATankPlayerController::MoveXAxis);
    InputComponent->BindAxis("MoveYAxis", this, &ATankPlayerController::MoveYAxis);
}

void ATankPlayerController::MoveXAxis(float AxisValue)
{
    if (TankPawn){
        TankPawn->MoveXAxis(AxisValue);
    }
}
void ATankPlayerController::MoveYAxis(float AxisValue)
{
    if (TankPawn){
        TankPawn->MoveYAxis(AxisValue);
    }
}