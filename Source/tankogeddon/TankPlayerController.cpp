#include "TankPlayerController.h"
#include "TankPawn.h"

ATankPlayerController::ATankPlayerController(){
    bShowMouseCursor = true;
}

void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();

    TankPawn = Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::SetupInputComponent(){
    Super::SetupInputComponent();

    InputComponent->BindAxis("MoveXAxis", this, &ATankPlayerController::MoveXAxis);
    InputComponent->BindAxis("RotateYAxis", this, &ATankPlayerController::RotateYAxis);
    InputComponent->BindAction("FireMain", IE_Pressed, this, &ATankPlayerController::FireMain);
    InputComponent->BindAction("FireSecond", IE_Pressed, this, &ATankPlayerController::FireSecond);
}

void ATankPlayerController::MoveXAxis(const float AxisValue){
    if (TankPawn){
        TankPawn->SetMoveTorqueXAxis(AxisValue);
    }
}
void ATankPlayerController::RotateYAxis(const float AxisValue){
    if (TankPawn){
        TankPawn->SetRotateTorqueYAxis(AxisValue);
    }
}

void ATankPlayerController::FireMain(){
    if (TankPawn){
        TankPawn->FireMain();
    }
}

void ATankPlayerController::FireSecond(){
    if (TankPawn){
        TankPawn->FireSecond();
    }
}

FVector ATankPlayerController::GetMousePos() const{
    return CachedMousePosition;
}

void ATankPlayerController::Tick(float DeltaSeconds){
    Super::Tick(DeltaSeconds);

    FVector MousePosition, MouseDirection;
    DeprojectMousePositionToWorld(MousePosition, MouseDirection);

    if (TankPawn){
        FVector TankPosition = TankPawn->GetActorLocation();
        CachedMousePosition = MousePosition - TankPosition;
        CachedMousePosition.Z = 0;
        CachedMousePosition.Normalize();
        CachedMousePosition = TankPosition + CachedMousePosition * 1000.f;
    }
}

