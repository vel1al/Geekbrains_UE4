#include "TankTurret.h"


void ATankTurret::SetActive(bool bIsActive){
	TurretMesh->SetVisibility(bIsActive);
}