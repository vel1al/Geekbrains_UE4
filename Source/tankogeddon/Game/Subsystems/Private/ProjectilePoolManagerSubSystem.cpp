#include "tankogeddon/Game/Subsystems/Public/ProjectilePoolManagerSubSystem.h"
#include "tankogeddon/Game/Subsystems/Public/ProjectilePoolManager.h"

#include "tankogeddon/Game/Misc/Components/Public/Projectile.h"


UProjectilePoolManager* UProjectilePoolManagerSubSystem::GetProjectilePoolManager(TSubclassOf<AProjectile> ProjectileClass) {
    UProjectilePoolManager* ReturningValue = nullptr;
    auto Predicate = [&](const UProjectilePoolManager* element){
        return element->GetProjectileClass() == ProjectileClass;
    };

    if(!(ProjectileClass))
        return nullptr;
    
    if(ProjectilePoolManagers.Num() > 0)
        ReturningValue = *ProjectilePoolManagers.FindByPredicate(Predicate);

    if(!(ReturningValue)){
        ProjectilePoolManagers.Add(NewObject<UProjectilePoolManager>(this));
        ProjectilePoolManagers.Top()->SetProjectileClass(ProjectileClass);

        ReturningValue = ProjectilePoolManagers.Top();
    }

    return ReturningValue;
}