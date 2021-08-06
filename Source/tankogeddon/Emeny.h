#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "Emeny.generated.h"


UCLASS()
class TANKOGEDDON_API AEmeny : public ADamageTaker{
		GENERATED_BODY()

	public:
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreValue")
		int PointForDestruction;

		int GetDestructionPoints() const;
};
