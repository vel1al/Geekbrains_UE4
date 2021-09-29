#pragma once

#include "CoreMinimal.h"
#include "DamageTaker.h"
#include "Emeny.generated.h"


UCLASS()
class TANKOGEDDON_API UEmeny : public UDamageTaker{
		GENERATED_BODY()

	public:
		UPROPERTY(BlueprintReadWrite, EditsDefaultOnly, Category = "Emeny")
		int OnElminatedScoreValue;

		int GetScoreValue() const;
};