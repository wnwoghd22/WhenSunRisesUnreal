// Jay(wnwoghd22) All Rights Reserved.


#include "Player/WSRPlayerController.h"

void AWSRPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}
