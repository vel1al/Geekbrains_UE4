#include "MainMenuWidget.h"

#include "DialogWidget.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Animation/WidgetAnimation.h"

#include "StylesSet.h"


FMainMenuStyle UMainMenuWidget::GetMainMenuStyle(ETheme theme){
    FMainMenuStyle ReturnValue;
    
    switch(theme){
        case ETheme::Bright:    ReturnValue = FStyleSet::Get().GetWidgetStyle<FMainMenuStyle>("Bright_MainMenuStyle");
        break;
        case ETheme::Dark:      ReturnValue = FStyleSet::Get().GetWidgetStyle<FMainMenuStyle>("Dark_MainMenuStyle");
        break;
        default:                ReturnValue = FStyleSet::Get().GetWidgetStyle<FMainMenuStyle>("Default_MainMenuStyle");
        break;
    }

    return ReturnValue;
}

void UMainMenuWidget::NativePreConstruct(){
    const FMainMenuStyle Style = GetMainMenuStyle(WidgetTheme);

    if(GameIcon)
        GameIcon->Brush = Style.GameIcon;

    if(NewGame_btn)
        NewGame_btn->WidgetStyle = Style.MainButtonsStyle;
    if(LoadGame_btn)
        LoadGame_btn->WidgetStyle = Style.MainButtonsStyle;
    if(QuitPlayGame_btn)
        QuitPlayGame_btn->WidgetStyle = Style.MainButtonsStyle;
    if(Play_btn)
        Play_btn->WidgetStyle = Style.MainButtonsStyle;
    if(Settings_btn)
        Settings_btn->WidgetStyle = Style.MainButtonsStyle;
    if(QuitGame_btn)
        QuitGame_btn->WidgetStyle = Style.MainButtonsStyle;

    if(QuitSettings_btn)
        QuitSettings_btn->WidgetStyle = Style.SettingsButtonsStyle;
    if(Quit_btn)
        Quit_btn->WidgetStyle = Style.SettingsButtonsStyle;
    if(Audio_btn)
        Audio_btn->WidgetStyle = Style.SettingsButtonsStyle;
    if(Video_btn)
        Video_btn->WidgetStyle = Style.SettingsButtonsStyle;
    if(Graphics_btn)
        Graphics_btn->WidgetStyle = Style.SettingsButtonsStyle;
    if(Apply_btn)
        Apply_btn->WidgetStyle = Style.SettingsButtonsStyle;
}

void UMainMenuWidget::NativeConstruct() {
    Super::NativeConstruct();

    BackBindings.Add(EStatus::Settings, EStatus::MainButtons);
    BackBindings.Add(EStatus::SubSettings, EStatus::Settings);

    BackBindings.Add(EStatus::PlayGame, EStatus::MainButtons);
    //BackBindings.Add(EStatus::Credits, EStatus::MainButtons);
    BackBindings.Add(EStatus::ConfirmationDialog, EStatus::MainButtons);
    BackBindings.Add(EStatus::ApplyDialog, EStatus::SubSettings);

    Bindings.Add(EStatus::MainButtons, MainButtons);
    Bindings.Add(EStatus::Settings, Buttons);
    Bindings.Add(EStatus::SubSettings, SubSettings);
    Bindings.Add(EStatus::PlayGame, PlayGame);

    Bindings.Add(EStatus::ConfirmationDialog, OnConfirmationDialogWidget);
    Bindings.Add(EStatus::ApplyDialog, OnApplyDialogWidget);

    SettingsBindings.Add(ESubSettingsStatus::Audio, 0);
    SettingsBindings.Add(ESubSettingsStatus::Video, 1);
    SettingsBindings.Add(ESubSettingsStatus::Graphics, 2);

    if(MainButtonsChangedAnimations)
        MenuChangingAnimations.Add(EStatus::MainButtons, MainButtonsChangedAnimations);
    if(SettingsChangedAnimations)
        MenuChangingAnimations.Add(EStatus::Settings, SettingsChangedAnimations);
    if(PlayGameChangedAnimations)
        MenuChangingAnimations.Add(EStatus::PlayGame, PlayGameChangedAnimations);
    if(SubSettingsChangedAnimations)
        MenuChangingAnimations.Add(EStatus::SubSettings, SubSettingsChangedAnimations);
    if(ConfirmationDialogChangedAnimations)
        MenuChangingAnimations.Add(EStatus::ConfirmationDialog, ConfirmationDialogChangedAnimations);
    if(ApplyDialogChangedAnimations)
        MenuChangingAnimations.Add(EStatus::ApplyDialog, ApplyDialogChangedAnimations);

    if(MainButtonsChoosenAnimations)
        MenuChosenAnimations.Add(EStatus::MainButtons, MainButtonsChoosenAnimations);
    if(SettingsChoosenAnimations)
        MenuChosenAnimations.Add(EStatus::Settings, SettingsChoosenAnimations);
    if(PlayGameChoosenAnimations)
        MenuChosenAnimations.Add(EStatus::PlayGame, PlayGameChoosenAnimations);
    if(SubSettingsChoosenAnimations)
        MenuChosenAnimations.Add(EStatus::SubSettings, SubSettingsChoosenAnimations);
    if(ConfirmationDialogChoosenAnimations)
        MenuChosenAnimations.Add(EStatus::ConfirmationDialog, ConfirmationDialogChoosenAnimations);
    if(ApplyDialogChoosenAnimations)
        MenuChosenAnimations.Add(EStatus::ApplyDialog, ApplyDialogChoosenAnimations);

    if(NewGame_btn)
        NewGame_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnNewGameButtonPressed);
    if(LoadGame_btn)
        LoadGame_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLoadGameButtonPressed);
    if(QuitPlayGame_btn)
        QuitPlayGame_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitPlayGameButtonPressed);
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
    if(Apply_btn)
        Apply_btn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnApplyButtonPressed);

    OnAnimationEnd.BindDynamic(this, &UMainMenuWidget::PlayNextAnimation);

    CurrentMenu = EStatus::MainButtons;
};

void UMainMenuWidget::GoTo(EStatus NextMenu){
    if(NextMenu == EStatus::None)
        return;
    if(NextMenu == CurrentMenu)
        return;

    SetActive(CurrentMenu, false);

    if(MenuChangingAnimations.Contains(CurrentMenu)){
        //MenuChangingAnimations[CurrentMenu]->BindToAnimationFinished(this, OnAnimationEnd);
        PlayAnimation(MenuChangingAnimations[CurrentMenu]);
    }

    CurrentMenu = NextMenu;
    PlayNextAnimation();
}

void UMainMenuWidget::PlayNextAnimation(){
    SetActive(CurrentMenu, true);

    if(MenuChosenAnimations.Contains(CurrentMenu))
         PlayAnimation(MenuChosenAnimations[CurrentMenu]);
}

void UMainMenuWidget::BackToParent(){
    if(CurrentMenu == EStatus::MainButtons)
        OnQuitGameButtonPressed();
    else
        GoTo(BackBindings[CurrentMenu]);
}

void UMainMenuWidget::SetSubSetting(ESubSettingsStatus SubSetting){
    if(SubSetting != ESubSettingsStatus::None)
        SettingsWidgetSwitcher->SetActiveWidgetIndex(SettingsBindings[SubSetting]);
}

void UMainMenuWidget::SetActive(EStatus RequiredMenu, bool bActive){
    if(!(Bindings.Contains(RequiredMenu))){
        if(RequiredMenu != EStatus::None)
            SetActive(CurrentMenu, bActive);
    }

    //Bindings[RequiredMenu]->SetIsEnabled(bActive);

    if(bActive)
        Bindings[RequiredMenu]->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    else
        Bindings[RequiredMenu]->SetVisibility(ESlateVisibility::Collapsed);
}

    // switch(RequiredMenu){
    //     case EStatus::MainButtons:
    //         MainButtons->SetIsEnabled(bActive);
    //     break;
    //     case EStatus::PlayGame:
    //         PlayGame->SetIsEnabled(bActive);
    //     break;
    //     case EStatus::Settings:
    //         Settings->SetIsEnabled(bActive);
    //         SettingsWidgetSwitcher->SetActiveWidgetIndex(0);
    //     break;

    //     case EStatus::Audio:
    //         Audio->SetIsEnabled(bActive);
    //         SettingsWidgetSwitcher->SetActiveWidgetIndex(1);
    //     break;
    //     case EStatus::Video:
    //         Video->SetIsEnabled(bActive);
    //         SettingsWidgetSwitcher->SetActiveWidgetIndex(2);
    //     break;
    //     case EStatus::Graphics:
    //         Graphics->SetIsEnabled(bActive);
    //         SettingsWidgetSwitcher->SetActiveWidgetIndex(3);
    //     break;

    //     case EStatus::ConfirmationDialog:
    //         OnConfirmationDialogWidget->SetIsEnabled(bActive);
    //     break;
        
    //     case EStatus::ApplyDialog:
    //         OnApplyDialogWidget->SetIsEnabled(bActive);
    //     break;
        
    //     default:
    //         if(CurrentMenu != EStatus::None)
    //             SetActive(CurrentMenu, bActive);
    //     break;
    // }
//}

void UMainMenuWidget::DisableCurrent(){
    SetActive(CurrentMenu, false);
}

void UMainMenuWidget::CallConfirmationDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)()){
    //SetActive(CurrentMenu, false);
    SetActive(EStatus::ConfirmationDialog, true);
    CurrentMenu = EStatus::ConfirmationDialog;

    if(MenuChosenAnimations.Contains(CurrentMenu))
        PlayAnimation(MenuChosenAnimations[CurrentMenu]);

    OnConfirmationDialogWidget->OnCancel.RemoveAll(this);
    if(OnCancelFunc)
        OnConfirmationDialogWidget->OnCancel.AddUObject(this, OnCancelFunc);
    else
        OnConfirmationDialogWidget->OnCancel.AddUObject(this, &UMainMenuWidget::BackToParent);

    OnConfirmationDialogWidget->OnApply.RemoveAll(this);
    if(OnApplyFunc)
        OnConfirmationDialogWidget->OnApply.AddUObject(this, OnApplyFunc);
}
//refactor soon
void UMainMenuWidget::CallApplySettingsDialog(void (UMainMenuWidget::*OnApplyFunc)(), void (UMainMenuWidget::*OnCancelFunc)()){
    //SetActive(CurrentMenu, false);
    SetActive(EStatus::ApplyDialog, true);
    CurrentMenu = EStatus::ApplyDialog;   

    if(MenuChosenAnimations.Contains(CurrentMenu))
        PlayAnimation(MenuChosenAnimations[CurrentMenu]);

    OnApplyDialogWidget->OnCancel.RemoveAll(this);
    if(OnCancelFunc)
        OnApplyDialogWidget->OnCancel.AddUObject(this, OnCancelFunc);
    else
        OnApplyDialogWidget->OnCancel.AddUObject(this, &UMainMenuWidget::BackToParent);

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

void UMainMenuWidget::OnQuitPlayGameButtonPressed(){
    BackToParent();
}

void UMainMenuWidget::OnSettingsButtonPressed(){
    GoTo(EStatus::Settings);
}

void UMainMenuWidget::OnQuitGameButtonPressed(){
    CallConfirmationDialog(&UMainMenuWidget::QuitGame, nullptr);
}

void UMainMenuWidget::OnAudioButtonPressed(){
    GoTo(EStatus::SubSettings);
    SetSubSetting(ESubSettingsStatus::Audio);
}

void UMainMenuWidget::OnVideoGameButtonPressed(){
    GoTo(EStatus::SubSettings);
    SetSubSetting(ESubSettingsStatus::Video);
}

void UMainMenuWidget::OnGraphicsButtonPressed(){
    GoTo(EStatus::SubSettings);
    SetSubSetting(ESubSettingsStatus::Graphics);
}

void UMainMenuWidget::OnQuitButtonPressed(){
    BackToParent();
}

void UMainMenuWidget::OnApplyButtonPressed(){
    bIsSettingsApllyed = true;
}

void UMainMenuWidget::OnQuitSettingsButtonPressed(){
    if(bIsSettingsApllyed)
        BackToParent();
    else
        CallApplySettingsDialog(&UMainMenuWidget::ApllySettings, &UMainMenuWidget::CancelSettings);
}

void UMainMenuWidget::QuitGame(){
    UE_LOG(LogTemp, Display, TEXT("QuitGame"));

    OnQuitGame.Broadcast();
}

void UMainMenuWidget::ApllySettings(){
    //do some
    
    BackToParent();
    GoTo(EStatus::Settings);
}
void UMainMenuWidget::CancelSettings(){
    //do some

    BackToParent();
}

// void UMainMenuWidget::BeginDestroy(){
//     // Bindings.Empty();
//     // MenuChangingAnimations.Empty();
//     // MenuChosenAnimations.Empty();
// }