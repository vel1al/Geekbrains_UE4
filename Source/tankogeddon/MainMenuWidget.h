#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidgetStyle.h"

#include "GameStructs.h"

#include "MainMenuWidget.generated.h"

UENUM()
enum class EStatus : uint8{
    None = 0 UMETA(DisplayName = "None"),
    MainButtons = 1 UMETA(DisplayName = "MainButtons"),
    ConfirmationDialog = 2 UMETA(DisplayName = "ConfirmationDialog"),
    ApplyDialog = 3 UMETA(DisplayName = "ApplyDialog"),
    PlayGame = 4 UMETA(DisplayName = "PlayGame"),
    Settings = 5 UMETA(DisplayName = "Settings"),
    SubSettings = 6 UMETA(DisplayName = "SubSettings")
};

UENUM()
enum class ESubSettingsStatus : uint8 {
    None = 0 UMETA(DisplayName = "None"),
    Audio = 1 UMETA(DisplayName = "Audio"),
    Video = 2 UMETA(DisplayName = "Video"),
    Graphics = 3 UMETA(DisplayName = "Graphics")
};

class UWidgetAnimation;
class UWidgetSwitcher;
class UDialogWidget;
class UVerticalBox;
class UCanvasPanel;
class UWidget;
class UBorder;
class UButton;
class UImage;


UCLASS()
class TANKOGEDDON_API UMainMenuWidget : public UUserWidget{
        GENERATED_BODY()

    public:
        void NativeConstruct() override;
        void NativePreConstruct() override;

        DECLARE_EVENT(UMainMenuWidget, FOnNewGameStart);
        DECLARE_EVENT(UMainMenuWidget, FOnQuitGame);

        FOnNewGameStart OnNewGameStart;
        FOnQuitGame OnQuitGame;
        FWidgetAnimationDynamicEvent OnAnimationEnd;

    protected:
        void CallConfirmationDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)());
        void CallApplySettingsDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)());

        UPROPERTY()
        TMap<EStatus, EStatus> BackBindings;
        
        //Animations
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* MainButtonsChangedAnimations;
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* MainButtonsChoosenAnimations;

            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* SettingsChangedAnimations;
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* SettingsChoosenAnimations;

            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* PlayGameChangedAnimations;
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* PlayGameChoosenAnimations;

            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* SubSettingsChangedAnimations;
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* SubSettingsChoosenAnimations;

            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* ApplyDialogChangedAnimations;
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* ApplyDialogChoosenAnimations;

            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* ConfirmationDialogChangedAnimations;
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* ConfirmationDialogChoosenAnimations;

            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* WidgetLabelOnChangedAnimations;
            UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
            UWidgetAnimation* WidgetLabelOnChoosenAnimations;

        //Dialogs
            UPROPERTY(meta = (BindWidgetOptional))
            UDialogWidget* OnApplyDialogWidget;
            UPROPERTY(meta = (BindWidgetOptional))
            UDialogWidget* OnConfirmationDialogWidget;

        //GameIcon
            UPROPERTY(meta = (BindWidgetOptional))
            UImage* GameIcon;

        //Boxes
            UPROPERTY(meta = (BindWidget))
            UVerticalBox* MainButtons;
            UPROPERTY(meta = (BindWidget))
            UCanvasPanel* Settings;
            UPROPERTY(meta = (BindWidget))
            UCanvasPanel* SubSettings;
            UPROPERTY(meta = (BindWidget))
            UVerticalBox* PlayGame;

            UPROPERTY(meta = (BindWidget))
            UBorder* Buttons;
            UPROPERTY(meta = (BindWidget))
            UBorder* Audio;
            UPROPERTY(meta = (BindWidget))
            UBorder* Video;
            UPROPERTY(meta = (BindWidget))
            UBorder* Graphics;

        //Misc
            UPROPERTY(meta = (BindWidget))
            UWidgetSwitcher* SettingsWidgetSwitcher;

        //Buttons
            //PlayGame
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* NewGame_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* LoadGame_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* QuitPlayGame_btn;

                UFUNCTION()
                void OnNewGameButtonPressed();
                UFUNCTION()
                void OnLoadGameButtonPressed();
                UFUNCTION()
                void OnQuitPlayGameButtonPressed();

            //MainButtons
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* Play_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* Settings_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* QuitGame_btn;

                UFUNCTION()
                void OnPlayButtonPressed();
                UFUNCTION()
                void OnSettingsButtonPressed();
                UFUNCTION()
                void OnQuitGameButtonPressed();

            //Settings
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* Audio_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* Video_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* Graphics_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* Quit_btn;

                UFUNCTION()
                void OnAudioButtonPressed();
                UFUNCTION()
                void OnVideoGameButtonPressed();
                UFUNCTION()
                void OnGraphicsButtonPressed();
                UFUNCTION()
                void OnQuitButtonPressed();

            //Settings_Additional
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* Apply_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* QuitSettings_btn;

                UFUNCTION()
                void OnApplyButtonPressed();
                UFUNCTION()
                void OnQuitSettingsButtonPressed();

        UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		ETheme WidgetTheme;

        UFUNCTION()
        void GoTo(EStatus NextMenu);
        UFUNCTION()
        void BackToParent();
        
        UFUNCTION()
        void QuitGame();

        UFUNCTION()
        void SetActive(EStatus RequiredMenu, bool bActive = false);
        UFUNCTION()
        void SetSubSetting(ESubSettingsStatus SubSetting);

        UFUNCTION()
        void DisableCurrent();

        UFUNCTION()
        void ApllySettings();
        UFUNCTION()
        void CancelSettings();
        
        UFUNCTION()
        void PlayNextAnimation();

    protected:
        FMainMenuStyle GetMainMenuStyle(ETheme theme);

		FMainMenuStyle MainMenuStyle;

        TMap<EStatus, UWidget*> Bindings;
        TMap<ESubSettingsStatus, int> SettingsBindings;
        TMap<EStatus, UWidgetAnimation*> MenuChangingAnimations;
        TMap<EStatus, UWidgetAnimation*> MenuChosenAnimations;

        bool bIsSettingsApllyed = false;
        bool bIsAnyDialogOppened = false;

        EStatus CurrentMenu = EStatus::None;
};
