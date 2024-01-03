// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WSRWidgetInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWSRWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * WhenSunRises Widget Interface
 * 
 * All Objects with WSR prefix must implement this interface.
 * It links delegates of objects with a widget.
 */
class WHENSUNRISESUNREAL_API IWSRWidgetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
