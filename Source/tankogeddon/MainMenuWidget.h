#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "MainMenuWidget.generated.h"

class UWidgetAnimation;
class UWidgetSwitcher;
class UDialogWidget;
class UVerticalBox;
class UBorder;
class UButton;

UENUM()
enum class EStatus : uint8{
    None = 0 UMETA(DisplayName = "None"),
    MainButtons = 1 UMETA(DisplayName = "MainButtons"),
    ConfirmationDialog = 2 UMETA(DisplayName = "ConfirmationDialog"),
    ApplyDialog = 3 UMETA(DisplayName = "ApplyDialog"),
    PlayGame = 4 UMETA(DisplayName = "PlayGame"),
    Settings = 5 UMETA(DisplayName = "Settings"),
    Audio = 6 UMETA(DisplayName = "Audio"),
    Video = 7 UMETA(DisplayName = "Video"),
    Graphics = 8 UMETA(DisplayName = "Graphics")
};


UCLASS()
class TANKOGEDDON_API UMainMenuWidget : public UUserWidget{
        GENERATED_BODY()

    public:
        void NativeConstruct() override;

        DECLARE_EVENT(UMainMenuWidget, FOnNewGameStart);
        DECLARE_EVENT(UMainMenuWidget, FOnQuitGame);

        FOnNewGameStart OnNewGameStart;
        FOnQuitGame OnQuitGame;

    protected:
        void CallConfirmationDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)());
        void CallApplySettingsDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)());

        UPROPERTY()
        TMap<EStatus, EStatus> BackBindings;

        //Animations
            UPROPERTY()
            TMap<EStatus, UWidgetAnimation*> MenuChangingAnimations;
            UPROPERTY()
            TMap<EStatus, UWidgetAnimation*> MenuChosenAnimations;

        //Dialogs
            UPROPERTY(meta = (BindWidgetOptional))
            UDialogWidget* OnApplyDialogWidget;
            UPROPERTY(meta = (BindWidgetOptional))
            UDialogWidget* OnConfirmationDialogWidget;

        //Boxes
            UPROPERTY(meta = (BindWidget))
            UVerticalBox* MainButtons;
            UPROPERTY(meta = (BindWidget))
            UVerticalBox* Settings;
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
            UPROPERTY(meta = (BindWidgetOptional))
            UWidgetSwitcher* SettingsWidgetSwitcher;

        //Buttons
            //PlayGame
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* NewGame_btn;
                UPROPERTY(meta = (BindWidgetOptional))
                UButton* LoadGame_btn;

                UFUNCTION()
                void OnNewGameButtonPressed();
                UFUNCTION()
                void OnLoadGameButtonPressed();

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

        UFUNCTION()
        void GoTo(EStatus NextMenu);
        UFUNCTION()
        void BackToParent();
        
        UFUNCTION()
        void QuitGame();

        UFUNCTION()
        void SetActive(EStatus RequiredMenu, bool bActive = false);

        UFUNCTION()
        void DisableCurrent();

    private:
        bool bIsSettingsApllyed = false;
        bool bIsAnyDialogOppened = false;

        EStatus CurrentMenu = EStatus::None;
};
