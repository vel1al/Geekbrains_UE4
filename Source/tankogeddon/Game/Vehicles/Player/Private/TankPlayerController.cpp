#include "tankogeddon/Game/Vehicles/Player/Public/TankPlayerController.h"
#include "tankogeddon/Game/Vehicles/Player/Public/PlayerVehicle.h"

#include "tankogeddon/Game/Misc/Components/Public/PlayerInventoryInteraction.h"
#include "tankogeddon/Game/Misc/Components/Public/TurretBase.h"
#include "tankogeddon/Game/Subsystems/Public/WidgetSubsystem.h"


ATankPlayerController::ATankPlayerController(){
    bShowMouseCursor = true;
}

void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();

    PlayerVehicle = Cast<APlayerVehicle>(GetPawn());
}

void ATankPlayerController::SetupInputComponent(){
    Super::SetupInputComponent();

    InputComponent->BindAxis("MoveXAxis", this, &ATankPlayerController::MoveXAxis);
    InputComponent->BindAxis("RotateZAxis", this, &ATankPlayerController::RotateZAxis);

    InputComponent->BindAction("FireMain", IE_Pressed, this, &ATankPlayerController::FireMain);
    InputComponent->BindAction("FireSecond", IE_Pressed, this, &ATankPlayerController::FireSecond);

    InputComponent->BindAction("Interaction", IE_Pressed, this, &ATankPlayerController::Interaction);
    InputComponent->BindAction("OpenInventory", IE_Pressed, this, &ATankPlayerController::OpenInvetory);
    InputComponent->BindAction("CloseInventory", IE_Pressed, this, &ATankPlayerController::CloseInvetory);

    InputComponent->BindAction("OpenQuestLog", IE_Pressed, this, &ATankPlayerController::OpenQuestLog);
    InputComponent->BindAction("CloseQuestLog", IE_Pressed, this, &ATankPlayerController::CloseQuestLog);
    
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
    if (PlayerVehicle)
        PlayerVehicle->SetBodyMoveTorque(AxisValue);
}
void ATankPlayerController::RotateZAxis(const float AxisValue){
    if (PlayerVehicle)
        PlayerVehicle->SetBodyRotationTorque(AxisValue);
}

void ATankPlayerController::FireMain(){
    if (PlayerVehicle)
        PlayerVehicle->FireMain();
}

void ATankPlayerController::FireSecond(){
    if (PlayerVehicle)
        PlayerVehicle->FireSecond();
}

void ATankPlayerController::ChangeTurret(){
    if(PlayerVehicle) 
        PlayerVehicle->ChangeTurret();
}

void ATankPlayerController::Interaction() {
    if(PlayerVehicle)
        PlayerVehicle->Interact();
}

void ATankPlayerController::OpenInvetory() {
    if(PlayerVehicle)
        PlayerVehicle->ToggleInventory(true);
}
void ATankPlayerController::CloseInvetory() {
    if(PlayerVehicle)
        PlayerVehicle->ToggleInventory(false);
}

void ATankPlayerController::OpenQuestLog() {
    UWidgetSubsystem* WidgetSubSystem = GetWorld()->GetGameInstance()->GetSubsystem<UWidgetSubsystem>();
    if(WidgetSubSystem)
        WidgetSubSystem->ToggleWidgetVisibility(EWidget::QuestJournal, true);
}

void ATankPlayerController::CloseQuestLog() {
    UWidgetSubsystem* WidgetSubSystem = GetWorld()->GetGameInstance()->GetSubsystem<UWidgetSubsystem>();
    if(WidgetSubSystem)
        WidgetSubSystem->ToggleWidgetVisibility(EWidget::QuestJournal, false);
}

FVector ATankPlayerController::GetMousePos() const{
    return CachedMousePosition;
}

void ATankPlayerController::Tick(float DeltaSeconds){
    Super::Tick(DeltaSeconds);


    if (PlayerVehicle){
        bShowMouseCursor = bIsControllingByMouse;

        FVector MousePosition, MouseDirection;
        DeprojectMousePositionToWorld(MousePosition, MouseDirection);

        float TurretRotationZAxis = GetInputAxisValue("RotateTurretZAxis");
        
        if(FMath::IsNearlyZero(TurretRotationZAxis) && (MousePosition != PreviousMousePosition || bIsControllingByMouse)){
            bIsControllingByMouse = true;

            FVector TankPosition = PlayerVehicle->GetActorLocation();

            FVector TankTurretDirection = FVector(0.f);
            if(PlayerVehicle->GetTurret())
                TankTurretDirection = PlayerVehicle->GetTurret()->GetTurretMeshDirection();

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

            PlayerVehicle->SetTurretRotationTorque(TurretRotationTorque);
        } 
        else{
            PlayerVehicle->SetTurretRotationTorque(TurretRotationZAxis);

            bIsControllingByMouse = false;
        }

        PreviousMousePosition = MousePosition;
    }
}

