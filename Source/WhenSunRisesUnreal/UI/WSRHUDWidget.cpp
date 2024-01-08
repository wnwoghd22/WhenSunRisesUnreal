// Jay(wnwoghd22) All Rights Reserved.


#include "UI/WSRHUDWidget.h"
#include "UI/WSRCrosshairWidget.h"
#include "Components/TextBlock.h"
#include "Interface/WSRHUDInterface.h"

UWSRHUDWidget::UWSRHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UWSRHUDWidget::UpdateCrosshair(bool bInIsActive)
{
	Crosshair->SetCrosshair(bInIsActive);
}

void UWSRHUDWidget::UpdateOnHitText(bool bIsOnHit)
{
	OnHitText->SetVisibility(bIsOnHit ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void UWSRHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Crosshair = Cast<UWSRCrosshairWidget>(GetWidgetFromName(TEXT("Crosshair")));
	ensure(Crosshair);

	OnHitText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TxtOnHit")));
	ensure(OnHitText);

	IWSRHUDInterface* HUDPawn = Cast<IWSRHUDInterface>(GetOwningPlayerPawn());
	if (HUDPawn)
	{
		HUDPawn->SetupHUDWidget(this);
	}
}
