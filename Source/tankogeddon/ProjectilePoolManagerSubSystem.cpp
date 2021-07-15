#include "ProjectilePoolManager.h"
#include "Projectile.h"
#include "ProjectilePoolManagerSubSystem.h"
#include "tankogeddonGameModeBase.h"


void UProjectilePoolManagerSubSystem::Deinitialize(){
    ProjectilePoolManagers.Empty();
}

UProjectilePoolManager* UProjectilePoolManagerSubSystem::GetProjectilePoolManager(TSubclassOf<class AProjectile> ProjectileClass) {
    UProjectilePoolManager* ReturningValue = nullptr;
    auto Predicate = [&](const UProjectilePoolManager* element){
        return element->GetProjectileClass() == ProjectileClass;
    };

    if(!(ProjectileClass))
        return nullptr;
    
    if(ProjectilePoolManagers.Num() > 1)
        ReturningValue = *ProjectilePoolManagers.FindByPredicate(Predicate);

    if(!(ReturningValue)){
        ProjectilePoolManagers.Add(NewObject<UProjectilePoolManager>(this));
        ProjectilePoolManagers.Top()->SetProjectileClass(ProjectileClass);

        ReturningValue = ProjectilePoolManagers.Top();
    }

    return ReturningValue;
}