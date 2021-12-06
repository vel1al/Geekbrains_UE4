#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "LocationMarker.generated.h"


DECLARE_MULTICAST_DELEGATE_TwoParams(FOnLocationEnter, AActor*, AActor*);


UINTERFACE()
class ULocationMarker : public UInterface {
	GENERATED_BODY()
};


class QUESTSYSTEMPLUGIN_API ILocationMarker {
		GENERATED_BODY()

	public:
		void OnLocationEnterFunction(AActor* OverlappingActor, AActor* SelfActor) {
			if(OnLocationEnter.IsBound())
				OnLocationEnter.Broadcast(OverlappingActor, SelfActor);
		}

		FOnLocationEnter OnLocationEnter;
};
