// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WSRHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class WHENSUNRISESUNREAL_API UWSRHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UWSRHUDWidget(const FObjectInitializer& ObjectInitializer);

public:
	void UpdateCrosshair(bool bInIsActive);

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY()
	TObjectPtr<class UWSRCrosshairWidget> Crosshair;
};
