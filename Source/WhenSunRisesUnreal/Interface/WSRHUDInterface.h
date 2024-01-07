// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WSRHUDInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWSRHUDInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WHENSUNRISESUNREAL_API IWSRHUDInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetupHUDWidget(class UWSRHUDWidget* InHUDWidget) = 0;
};
