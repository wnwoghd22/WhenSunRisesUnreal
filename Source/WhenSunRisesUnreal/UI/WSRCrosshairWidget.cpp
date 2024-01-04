// Jay(wnwoghd22) All Rights Reserved.


#include "UI/WSRCrosshairWidget.h"
#include "Components/Image.h"
#include "Interface/WSRWidgetInterface.h"

UWSRCrosshairWidget::UWSRCrosshairWidget(const FObjectInitializer& ObjectInitializer)
{
}

void UWSRCrosshairWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Crosshair = Cast<UImage>(GetWidgetFromName(TEXT("CrosshairDot")));
	ensure(Crosshair);

	IWSRWidgetInterface* WidgetInterface = Cast<IWSRWidgetInterface>(OwningActor);
	if (WidgetInterface)
	{
		WidgetInterface->SetupWidget(this);
	}
}

void UWSRCrosshairWidget::SetCrosshair(bool bInActive)
{
	Crosshair->SetVisibility(bInActive ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
