#include "TankPlayerController.h"
#include "PlayerInventoryInteraction.h"
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
    InputComponent->BindAxis("RotateZAxis", this, &ATankPlayerController::RotateZAxis);

    InputComponent->BindAction("FireMain", IE_Pressed, this, &ATankPlayerController::FireMain);
    InputComponent->BindAction("FireSecond", IE_Pressed, this, &ATankPlayerController::FireSecond);

    InputComponent->BindKey(EKeys::LeftMouseButton, IE_Released, this, &ATankPlayerController::OnMouseButtonUpFunc);

    InputComponent->BindKey(EKeys::LeftShift, IE_Pressed, this, &ATankPlayerController::OnLeftShiftPressed);
    InputComponent->BindKey(EKeys::LeftShift, IE_Released, this, &ATankPlayerController::OnLeftShiftReleased);
    
    InputComponent->BindAction("ChangeTurret", IE_Pressed, this, &ATankPlayerController::ChangeTurret);
    InputComponent->BindAxis("RotateTurretZAxis");
}

void ATankPlayerController::OnMouseButtonUpFunc(){
    if(OnMouseButtonUp.IsBound())
        OnMouseButtonUp.Broadcast();
}

void ATankPlayerController::OnLeftShiftPressed(){
    if(OnLeftShift.IsBound())
        OnLeftShift.Broadcast(true);
}

void ATankPlayerController::OnLeftShiftReleased() {
    if(OnLeftShift.IsBound())
        OnLeftShift.Broadcast(false);
}

void ATankPlayerController::MoveXAxis(const float AxisValue){
    if (TankPawn)
        TankPawn->SetMoveTorqueXAxis(AxisValue);
}
void ATankPlayerController::RotateZAxis(const float AxisValue){
    if (TankPawn)
        TankPawn->SetRotateTorqueZAxis(AxisValue);
}

void ATankPlayerController::FireMain(){
    if (TankPawn)
        TankPawn->FireMain();
}

void ATankPlayerController::FireSecond(){
    if (TankPawn)
        TankPawn->FireSecond();
}

void ATankPlayerController::ChangeTurret(){
    if(TankPawn)
        TankPawn->ChangeTurret();
}

FVector ATankPlayerController::GetMousePos() const{
    return CachedMousePosition;
}

void ATankPlayerController::Tick(float DeltaSeconds){
    Super::Tick(DeltaSeconds);


    if (TankPawn){
        bShowMouseCursor = bIsControllingByMouse;

        FVector MousePosition, MouseDirection;
        DeprojectMousePositionToWorld(MousePosition, MouseDirection);

        float TurretRotationZAxis = GetInputAxisValue("RotateTurretZAxis");
        
        if(FMath::IsNearlyZero(TurretRotationZAxis) && (MousePosition != PreviousMousePosition || bIsControllingByMouse)){
            bIsControllingByMouse = true;

            FVector TankPosition = TankPawn->GetActorLocation();
            FVector TankTurretDirection = TankPawn->GetTurretDirection();

            CachedMousePosition = MousePosition - TankPosition;
            CachedMousePosition.Z = 0;

            CachedMousePosition.Normalize();

            float AngleOfReferenceTurret = FMath::RadiansToDegrees(FMath::Atan2(TankTurretDirection.Y, TankTurretDirection.X));
            float AngleOfReferenceMouse = FMath::RadiansToDegrees(FMath::Atan2(CachedMousePosition.Y, CachedMousePosition.X));

            float SignedAngle = AngleOfReferenceMouse - AngleOfReferenceTurret;

            if (SignedAngle > 180) SignedAngle -= 360;
            if (SignedAngle <= -180) SignedAngle += 360;

            float TurretRotationTorque = 0;
            
            if(FMath::Abs(SignedAngle) > 5){
                if(SignedAngle > 0)
                    TurretRotationTorque = 1;
                else
                    TurretRotationTorque = -1;
            }

            TankPawn->SetRotateTurretTorqueZAxis(TurretRotationTorque);
        } 
        else{
            TankPawn->SetRotateTurretTorqueZAxis(TurretRotationZAxis);

            bIsControllingByMouse = false;
        }

        PreviousMousePosition = MousePosition;
    }
}

