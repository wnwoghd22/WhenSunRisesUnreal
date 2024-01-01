// Jay(wnwoghd22) All Rights Reserved.


#include "Game/WSRGameMode.h"

AWSRGameMode::AWSRGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/WhenSunRisesUnreal.WSRCharacterPlayer"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/WhenSunRisesUnreal.WSRPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}
}
