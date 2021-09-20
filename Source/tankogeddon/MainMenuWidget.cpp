#include "MainMenuWidget.h"

#include "DialogWidget.h"

#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"
#include "Animation/WidgetAnimation.h"


void UMainMenuWidget::NativeConstruct() {
    Super::NativeConstruct();

    BackBindings.Add(EStatus::Settings, EStatus::MainButtons);
    BackBindings.Add(EStatus::Audio, EStatus::Settings);
    BackBindings.Add(EStatus::Video, EStatus::Settings);
    BackBindings.Add(EStatus::Graphics, EStatus::Settings);

    BackBindings.Add(EStatus::PlayGame, EStatus::MainButtons);
    //BackBindings.Add(EStatus::Credits, EStatus::MainButtons);
    BackBindings.Add(EStatus::ConfirmationDialog, EStatus::MainButtons);
    BackBindings.Add(EStatus::ApplyDialog, EStatus::MainButtons);

    if(NewGame_btn)
        NewGame_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnNewGameButtonPressed);
    if(LoadGame_btn)
        LoadGame_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLoadGameButtonPressed);

    if(Play_btn)
        Play_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPlayButtonPressed);
    if(Settings_btn)
        Settings_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSettingsButtonPressed);
    if(QuitGame_btn)
        QuitGame_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitGameButtonPressed);

    if(QuitSettings_btn)
        QuitSettings_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitSettingsButtonPressed);
    if(Quit_btn)
        Quit_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButtonPressed);
    if(Audio_btn)
        Audio_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnAudioButtonPressed);
    if(Video_btn)
        Video_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnVideoGameButtonPressed);
    if(Graphics_btn)
        Graphics_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnGraphicsButtonPressed);

    CurrentMenu = EStatus::MainButtons;
};

void UMainMenuWidget::GoTo(EStatus NextMenu){
    if(NextMenu == EStatus::None)
        return;
    if(MenuChangingAnimations[CurrentMenu])
        PlayAnimation(MenuChangingAnimations[CurrentMenu]);
    
    SetActive(CurrentMenu, false);
    SetActive(NextMenu, true);

    if(MenuChosenAnimations[NextMenu])
        PlayAnimation(MenuChosenAnimations[NextMenu]);

    CurrentMenu = NextMenu;
}

void UMainMenuWidget::BackToParent(){
    if(CurrentMenu == EStatus::MainButtons)
        OnQuitGameButtonPressed();
    else
        GoTo(BackBindings[CurrentMenu]);
}

void UMainMenuWidget::SetActive(EStatus RequiredMenu, bool bActive){
    switch(RequiredMenu){
        case EStatus::MainButtons:
            MainButtons->SetIsEnabled(bActive);
        break;
        case EStatus::PlayGame:
            PlayGame->SetIsEnabled(bActive);
        break;
        case EStatus::Settings:
            Settings->SetIsEnabled(bActive);
            SettingsWidgetSwitcher->SetActiveWidgetIndex(0);
        break;

        case EStatus::Audio:
            Audio->SetIsEnabled(bActive);
            SettingsWidgetSwitcher->SetActiveWidgetIndex(1);
        break;
        case EStatus::Video:
            Video->SetIsEnabled(bActive);
            SettingsWidgetSwitcher->SetActiveWidgetIndex(2);
        break;
        case EStatus::Graphics:
            Graphics->SetIsEnabled(bActive);
            SettingsWidgetSwitcher->SetActiveWidgetIndex(3);
        break;

        case EStatus::ConfirmationDialog:
            OnConfirmationDialogWidget->SetIsEnabled(bActive);
        break;
        
        case EStatus::ApplyDialog:
            OnApplyDialogWidget->SetIsEnabled(bActive);
        break;
        
        default:
            if(CurrentMenu != EStatus::None)
                SetActive(CurrentMenu, bActive);
        break;
    }
}

void UMainMenuWidget::DisableCurrent(){
    SetActive(CurrentMenu, false);
}

void UMainMenuWidget::CallConfirmationDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)()){
    SetActive(CurrentMenu, false);
    SetActive(EStatus::ConfirmationDialog, true);

    OnConfirmationDialogWidget->OnCancel.RemoveAll(this);
    if(OnCancelFunc)
        OnConfirmationDialogWidget->OnCancel.AddUObject(this, OnCancelFunc);
    else
        OnConfirmationDialogWidget->OnCancel.AddUObject(this, &UMainMenuWidget::DisableCurrent);

    OnConfirmationDialogWidget->OnApply.RemoveAll(this);
    if(OnApplyFunc)
        OnConfirmationDialogWidget->OnApply.AddUObject(this, OnApplyFunc);
}

void UMainMenuWidget::CallApplySettingsDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)()){
    SetActive(CurrentMenu, false);
    SetActive(EStatus::ApplyDialog, true);

    OnApplyDialogWidget->OnCancel.RemoveAll(this);
    if(OnCancelFunc)
        OnApplyDialogWidget->OnCancel.AddUObject(this, OnCancelFunc);
    else
        OnApplyDialogWidget->OnCancel.AddUObject(this, &UMainMenuWidget::DisableCurrent);

    OnApplyDialogWidget->OnApply.RemoveAll(this);
    if(OnApplyFunc)
        OnApplyDialogWidget->OnApply.AddUObject(this, OnApplyFunc);
}

void UMainMenuWidget::OnPlayButtonPressed(){
    GoTo(EStatus::PlayGame);
}

void UMainMenuWidget::OnNewGameButtonPressed(){
    UE_LOG(LogTemp, Display, TEXT("NewGame"));

    OnNewGameStart.Broadcast();
}

void UMainMenuWidget::OnLoadGameButtonPressed(){
    UE_LOG(LogTemp, Display, TEXT("LoadGame"));

    OnNewGameStart.Broadcast();
}

void UMainMenuWidget::OnSettingsButtonPressed(){
    GoTo(EStatus::Settings);
}

void UMainMenuWidget::OnQuitGameButtonPressed(){
    CallConfirmationDialog(&UMainMenuWidget::QuitGame, nullptr);
}

void UMainMenuWidget::OnAudioButtonPressed(){
    GoTo(EStatus::Audio);
}

void UMainMenuWidget::OnVideoGameButtonPressed(){
    GoTo(EStatus::Video);
}

void UMainMenuWidget::OnGraphicsButtonPressed(){
    GoTo(EStatus::Graphics);
}

void UMainMenuWidget::OnQuitButtonPressed(){
    if(bIsSettingsApllyed)
        BackToParent();
    else
        CallApplySettingsDialog(&UMainMenuWidget::BackToParent, nullptr);
}

void UMainMenuWidget::OnApplyButtonPressed(){
    bIsSettingsApllyed = true;
}

void UMainMenuWidget::OnQuitSettingsButtonPressed(){
    BackToParent();
}

void UMainMenuWidget::QuitGame(){
    UE_LOG(LogTemp, Display, TEXT("QuitGame"));

    OnQuitGame.Broadcast();
}