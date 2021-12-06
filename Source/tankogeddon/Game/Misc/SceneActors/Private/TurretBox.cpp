#include "tankogeddon/Game/Misc/SceneActors/Public/TurretBox.h"
#include "tankogeddon/Game/Vehicles/Player/Public/PlayerVehicle.h"
#include "tankogeddon/Game/Misc/Components/Public/FloatingMesh.h"

#include "Components/SpotLightComponent.h"
#include "Kismet/KismetMathLibrary.h"


ATurretBox::ATurretBox(){
	PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<UFloatingMesh>(TEXT("Mesh"));
    RootComponent = Mesh;

    Mesh->Mesh->OnComponentBeginOverlap.AddDynamic(this, &ATurretBox::OnMeshOverlapBegin);
    Mesh->Mesh->SetCollisionProfileName(FName("OverlapAll"));
    Mesh->Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Mesh->Mesh->SetGenerateOverlapEvents(true);

	Light = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
    Light->SetupAttachment(RootComponent);
}

void ATurretBox::OnMeshOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Overlaping"));

	APlayerVehicle* Tank = Cast<APlayerVehicle>(OtherActor);
    if(Tank){
        GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Green, TEXT("Picked up the turret box"));

        //Tank->SetUpTurret(TurretClass);
        Destroy();
    }
}