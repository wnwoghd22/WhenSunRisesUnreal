// Jay(wnwoghd22) All Rights Reserved.


#include "UI/WSRWidgetComponent.h"
#include "WSRUserWidget.h"

void UWSRWidgetComponent::InitWidget()
{
	Super::InitWidget();

	UWSRUserWidget* WSRUserWidget = Cast<UWSRUserWidget>(GetWidget());
	if (WSRUserWidget)
	{
		WSRUserWidget->SetOwningActor(GetOwner());
	}
}
