#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"

#include "GameStructs.h"
#include "SMinimapWidget.h"

#include "MinimapWidget.generated.h"


class UTexture2D;
class UBorder;
class SWidget;


UCLASS()
class TANKOGEDDON_API UMinimapWidget : public UWidget{
	GENERATED_BODY()

	DECLARE_DELEGATE_RetVal(FVector2D, TPlayerPositionGetter);
	DECLARE_DELEGATE_RetVal(bool, TCenteringToPlayerGetter);
	DECLARE_DELEGATE_RetVal(float, TSizeAdjustmentGetter);

	TPlayerPositionGetter PlayerPositionGetter;
	TCenteringToPlayerGetter CenteringToPlayerGetter;
	TSizeAdjustmentGetter SizeAdjustmentGetter;

	public:	
		UMinimapWidget();

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		UTexture2D* PlayerSign;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		UTexture2D* BorderTexture;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		UTexture2D* OutlineTexture;
		
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		FVector2D TopLeftCorner;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		FVector2D BottomRightCorner;

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		FVector2D MapTopLeftCorner;
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		FVector2D MapBottomRightCorner;

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		bool bIsCenteringToPlayer;

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(EditCondition="bIsCenteringToPlayer", EditConditionHides))
		float SizeAdjustment;
		
		virtual void ReleaseSlateResources(bool bReleaseChildren) override;
		virtual void SynchronizeProperties() override;

		UFUNCTION()
		FVector2D GetPlayerLocation();
		UFUNCTION()
		bool GetCenteringToPlayer();		
		UFUNCTION()
		float GetSizeAdjustment();

	protected:
    	virtual TSharedRef<SWidget> RebuildWidget() override;

    	TSharedPtr<SMiniMapWidget> AllocatedMiniMap;
};
