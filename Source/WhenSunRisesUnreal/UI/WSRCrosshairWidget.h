// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WSRCrosshairWidget.generated.h"

/**
 * 
 */
UCLASS()
class WHENSUNRISESUNREAL_API UWSRCrosshairWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	void SetCrosshair(bool bInActive);

protected:
	UPROPERTY()
	TObjectPtr<class UImage> Crosshair;
};
