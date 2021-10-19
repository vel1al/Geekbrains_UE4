#include "TurretPopUp.h"

#include "GameStructs.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/DataTable.h"

void UTurretPopUp::SetData(FName RequiredTurret) {
    if(!TurretPopUpDataTable)
        return;

    FTurretInformation* RequredTurretData = TurretPopUpDataTable->FindRow<FTurretInformation>(RequiredTurret, "");

    if(!RequredTurretData)
        return;


    if(TextDescription)
        TextDescription->SetText(RequredTurretData->MainDescription);
    if(Thumbnail)
        Thumbnail->SetBrush(RequredTurretData->Thumbnail);
}