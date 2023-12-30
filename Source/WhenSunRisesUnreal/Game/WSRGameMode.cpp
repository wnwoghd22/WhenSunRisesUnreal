// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/WSRGameMode.h"

AWSRGameMode::AWSRGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));
	if (ThirdPersonClassRef.Class)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}

	ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/WhenSunRisesUnreal.WSRPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}
}
