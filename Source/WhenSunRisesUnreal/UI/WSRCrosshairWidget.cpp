// Jay(wnwoghd22) All Rights Reserved.


#include "UI/WSRCrosshairWidget.h"
#include "Components/Image.h"
#include "Interface/WSRWidgetInterface.h"


void UWSRCrosshairWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Crosshair = Cast<UImage>(GetWidgetFromName(TEXT("CrosshairDot")));
	ensure(Crosshair);

}

void UWSRCrosshairWidget::SetCrosshair(bool bInActive)
{
	Crosshair->SetVisibility(bInActive ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
