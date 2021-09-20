#include "MortairCannon.h"

#include "Components/ArrowComponent.h"
#include <Particles/ParticleSystemComponent.h>
#include <Components/AudioComponent.h>

#include "ProjectilePoolManager.h"
#include "PhysicsProjectile.h"
#include "ProjectilePoolManagerSubSystem.h"


void AMortairCanon::SetTarget(const FVector2D value) {
	TargetPoint = FVector(value, DeadZ);
}

void AMortairCanon::SetSupportPoint(const FVector value) {
	SupportPoint = value;
}

void AMortairCanon::Fire(){
	ShootEffect->ActivateSystem();
	ShootAudioEffect->Play();

	if (GetOwner() && GetOwner() == GetWorld()->GetFirstPlayerController()->GetPawn()){
        if (ShootForceEffect){
            FForceFeedbackParameters ShootForceEffectParams;

            ShootForceEffectParams.bLooping = false;
            ShootForceEffectParams.Tag = "ShootForceEffectParams";

            GetWorld()->GetFirstPlayerController()->ClientPlayForceFeedback(ShootForceEffect, ShootForceEffectParams);
        }

        if (ShootShake)
            GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(ShootShake);
    }

	APhysicsProjectile* Projectile = Cast<APhysicsProjectile>(GetGameInstance()->GetSubsystem<UProjectilePoolManagerSubSystem>()->GetProjectilePoolManager(ProjectileClass)->GetProjectile());
	if (Projectile){	
		FPhysicsProjectilePreStartData ProjectileData;

		ProjectileData.Location = ProjectileSpawnPoint->GetComponentLocation();
		ProjectileData.DestinitionPoint = TargetPoint;
		ProjectileData.SupportPoint = SupportPoint;
		ProjectileData.Instigator = GetInstigator();
		ProjectileData.CanonDamage = FireDamage;

		Projectile->SetMoveRange(FireRange);
		Projectile->SetPrestartData(ProjectileData);

		UE_LOG(LogTemp, Display, TEXT("%s"), *ProjectileData.Location.ToString());

		Projectile->Start();
	}
}