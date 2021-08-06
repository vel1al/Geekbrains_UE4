#include "ProjectilePoolManager.h"
#include <algorithm>
#include "Projectile.h"


UProjectilePoolManager::UProjectilePoolManager(){
    SetProjectileClass(AProjectile::StaticClass());
}

void UProjectilePoolManager::PostInitProperties(){
    Super::PostInitProperties();


    if(GetOuter() && GetOuter()->GetWorld()) 
        BeginPlay();
}

void UProjectilePoolManager::BeginPlay(){
    CreateProjectile();
}

void UProjectilePoolManager::BeginDestroy(){
    Super::BeginDestroy();


    AllocatedObjects.Empty();
}

AProjectile* UProjectilePoolManager::FindNextAvaibleObject(){
    AProjectile* ReturningValue = nullptr;

    if(AllocatedObjects.Num() > 1)
        for (int element = 0; element < AllocatedObjects.Num(); ++element){
            if(AllocatedObjects[element]){
                if(!(AllocatedObjects[element]->IsUsing()))
                    ReturningValue = AllocatedObjects[element];
            }
            else
                AllocatedObjects.RemoveAt(element);
        }

    return ReturningValue;
}

AProjectile* UProjectilePoolManager::GetProjectile(){
    AProjectile* ReturningValue;

    if(!(FirstAvaibleObject))
        ReturningValue = CreateProjectile();
    else{
        ReturningValue = FirstAvaibleObject;

        FirstAvaibleObject = FindNextAvaibleObject();
    }

    return ReturningValue;
}

AProjectile* UProjectilePoolManager::CreateProjectile(){
    AProjectile* ReturningValue;
    ReturningValue = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, FVector(0.f), FRotator(0.f));

    AllocatedObjects.Add(ReturningValue);

    return ReturningValue;
}

TSubclassOf<AProjectile> UProjectilePoolManager::GetProjectileClass() const{
    return ProjectileClass;
}

void UProjectilePoolManager::SetProjectileClass(TSubclassOf<AProjectile> projectileClass){
    ProjectileClass = projectileClass;
}

void UProjectilePoolManager::Tick(const float DeltaTime){
    if(GetOuter() && GetOuter()->GetWorld())
        if(!(FirstAvaibleObject))
            FirstAvaibleObject = FindNextAvaibleObject();
}

bool UProjectilePoolManager::IsTickable() const{
	return true;
}

TStatId UProjectilePoolManager::GetStatId() const{
	return TStatId();
}