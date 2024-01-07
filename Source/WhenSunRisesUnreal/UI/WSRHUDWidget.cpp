// Jay(wnwoghd22) All Rights Reserved.


#include "UI/WSRHUDWidget.h"
#include "UI/WSRCrosshairWidget.h"
#include "Interface/WSRHUDInterface.h"

UWSRHUDWidget::UWSRHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UWSRHUDWidget::UpdateCrosshair(bool bInIsActive)
{
	Crosshair->SetCrosshair(bInIsActive);
}

void UWSRHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Crosshair = Cast<UWSRCrosshairWidget>(GetWidgetFromName(TEXT("Crosshair")));
	ensure(Crosshair);

	IWSRHUDInterface* HUDPawn = Cast<IWSRHUDInterface>(GetOwningPlayerPawn());
	if (HUDPawn)
	{
		HUDPawn->SetupHUDWidget(this);
	}
}
