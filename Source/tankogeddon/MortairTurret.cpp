#include "MortairTurret.h"
#include "MortairCannon.h"


void AMortairTurret::BeginPlay(){
	Super::BeginPlay();


	SetUpCannon(DefaultCannonClass);
	CastCannonToClass();

    check(Cannon);
}

void AMortairTurret::CastCannonToClass() {
	AMortairCanon* SpawnedCannon = Cast<AMortairCanon>(BaseCannon);
	if(SpawnedCannon) 
    	Cannon = SpawnedCannon;
}

AMortairCanon* AMortairTurret::GetMortairCannon() const {
    if(Cannon)
        return Cannon;

    return nullptr;
}