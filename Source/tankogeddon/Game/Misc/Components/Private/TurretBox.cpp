#include "tankogeddon/Game/Misc/Components/Public/TurretBox.h"
#include "tankogeddon/Game/Vehicles/Player/Public/PlayerVehicle.h"

#include "Components/SpotLightComponent.h"
#include "Kismet/KismetMathLibrary.h"


ATurretBox::ATurretBox(){
	PrimaryActorTick.bCanEverTick = true;

    USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = SceneComp;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);

    Mesh->OnComponentBeginOverlap.AddDynamic(this, &ATurretBox::OnMeshOverlapBegin);
    Mesh->SetCollisionProfileName(FName("OverlapAll"));
    Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Mesh->SetGenerateOverlapEvents(true);

	Light = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
    Light->SetupAttachment(RootComponent);
}

void ATurretBox::BeginPlay(){
	Super::BeginPlay();

	ConstLocation = GetActorLocation();
	ConstRotation = GetActorRotation();
}

void ATurretBox::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);

	SinDegrees += FlyingSpeedRatio;
	if(++SinDegrees > 180)
		SinDegrees = 1;

	FRotator TargetRotation = GetActorRotation();
	TargetRotation.Yaw = TargetRotation.Yaw + ConstRotation.Yaw * RotationRatio;
	FVector TargetLocation = GetActorLocation();
	TargetLocation.Z = ConstLocation.Z * UKismetMathLibrary::Sin(SinDegrees) * FlyingHeightRatio;

	SetActorRotation(TargetRotation);
	SetActorLocation(TargetLocation);
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