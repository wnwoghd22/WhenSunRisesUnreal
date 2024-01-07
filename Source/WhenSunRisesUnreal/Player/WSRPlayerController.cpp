// Jay(wnwoghd22) All Rights Reserved.


#include "Player/WSRPlayerController.h"
#include "UI/WSRHUDWidget.h"

AWSRPlayerController::AWSRPlayerController()
{
	static ConstructorHelpers::FClassFinder<UWSRHUDWidget> WSRHUDWidgetRef(TEXT("/Game/WhenSunRises/UI/WBP_HUD.WBP_HUD_C"));
	if (WSRHUDWidgetRef.Class)
	{
		WSRHUDWidgetClass = WSRHUDWidgetRef.Class;
	}
}

void AWSRPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);

	WSRHUDWidget = CreateWidget<UWSRHUDWidget>(this, WSRHUDWidgetClass);
	if (WSRHUDWidget)
	{
		WSRHUDWidget->AddToViewport();
	}
}
