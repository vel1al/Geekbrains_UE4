#include "TowerBody.h"
#include "TurretBase.h"


void ATowerBody::Tick(const float DeltaTime){
	Super::Tick(DeltaTime);


	if(CheckRange())
		if(IsPlayerInView()){
            FVector PlayerLocation = PlayerPawn->GetActorLocation();

			FVector DirectionToPlayer = GetActorLocation() - PlayerLocation;
            DirectionToPlayer.Normalize();

	        TurretTargetingAngle = GetAngleFromTo(BaseTurret->GetTurretMeshDirection(), DirectionToPlayer);

			if(TurretTargetingAngle < TurretTargetingAccurency)
				Fire();
		}
}

bool ATowerBody::IsPlayerInView(){
    if (PlayerPawn){
        FCollisionQueryParams Settings(FName(TEXT("VeiewCheck")), true, this);
        FHitResult HitResult;

        Settings.AddIgnoredActor(this);
		Settings.AddIgnoredActor(BaseTurret);
        Settings.bReturnPhysicalMaterial = false;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, BaseTurret->GetActorLocation(), PlayerPawn->GetActorLocation(), ECC_Visibility, Settings))
            if (HitResult.Actor.IsValid()){
				//DrawDebugLine(GetWorld(), Turret->GetActorLocation(), HitResult.Location, FColor::Red, false, 5.f, 0, 5);

               	return HitResult.Actor.Get() == PlayerPawn;
			}
		
		//DrawDebugLine(GetWorld(), Turret->GetActorLocation(), HitResult.Location, FColor::Green, false, 5.f, 0, 5);

		return false;
	}

	return false;
}