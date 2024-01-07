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

public:
	AWSRPlayerController();
	
protected:
	virtual void BeginPlay() override;

// HUD Section
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	TSubclassOf<class UWSRHUDWidget> WSRHUDWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	TObjectPtr<class UWSRHUDWidget> WSRHUDWidget;
};
