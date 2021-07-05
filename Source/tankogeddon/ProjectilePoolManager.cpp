// Fill out your copyright notice in the Description page of Project Settings.

// #include <algorithm>
// #include "Projectile.h"
// #include "ProjectilePoolManager.h"

// AProjectile* UProjectilePoolManager::FindNextAvaibleObject(){
//     if(AllocatedObjects.Num() > 0)
//         for(size_t itt = 0; itt < AllocatedObjects.Num(); ++itt)
//             if(AllocatedObjects[itt]->IsUsing())
//                 return AllocatedObjects[itt];

//     return GetWorld()->SpawnActor<AProjectile>(FVector(0.f), FRotator(0.f));
// }

// AProjectile* UProjectilePoolManager::GetProjectile(){
//     AProjectile* ReturningValue;

//     GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Orange, TEXT("Projectile: pop projectile from pool"));

//     if(!(FirstAvaibleObject)){
//         GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Orange, TEXT("Projectile: creating new projectile"));
//         ReturningValue = GetWorld()->SpawnActor<AProjectile>(FVector(0.f), FRotator(0.f));
        
//         AllocatedObjects.Add(ReturningValue);
//     } 
//     else{
//         GEngine->AddOnScreenDebugMessage(10, 1.f, FColor::Orange, TEXT("Projectile: getting allocated projectile"));
//         ReturningValue = FirstAvaibleObject;

//         FirstAvaibleObject = FindNextAvaibleObject();
//     }

//     return ReturningValue;
// }

// void UProjectilePoolManager::Tick(const float DeltaTime){
//     if(!(FirstAvaibleObject))
//         FirstAvaibleObject = FindNextAvaibleObject();
// }

// bool UProjectilePoolManager::IsTickable() const{
// 	return true;
// }

// TStatId UProjectilePoolManager::GetStatId() const{
// 	return TStatId();
// }