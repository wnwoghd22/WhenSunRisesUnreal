// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WSRPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WHENSUNRISESUNREAL_API AWSRPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
