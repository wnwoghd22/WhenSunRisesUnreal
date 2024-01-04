// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/WSRUserWidget.h"
#include "WSRCrosshairWidget.generated.h"

/**
 * 
 */
UCLASS()
class WHENSUNRISESUNREAL_API UWSRCrosshairWidget : public UWSRUserWidget
{
	GENERATED_BODY()

public:
	UWSRCrosshairWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

public:
	void SetCrosshair(bool bInActive);

protected:
	UPROPERTY()
	TObjectPtr<class UImage> Crosshair;
};
