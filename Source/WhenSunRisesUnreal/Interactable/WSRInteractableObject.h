// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/WSRInteractableInterface.h"
#include "WSRInteractableObject.generated.h"

UCLASS()
class WHENSUNRISESUNREAL_API AWSRInteractableObject : public AActor, public IWSRInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWSRInteractableObject();

// Interaction Section
public:
	virtual void Interact() override;

	UFUNCTION(BlueprintImplementableEvent, Category = Game, Meta = (DisplayName = "OnInteractCpp"))
	void K2_OnInteract();

protected:
	UPROPERTY(VisibleAnywhere, Category = Trigger)
	TObjectPtr<class UBoxComponent> Trigger;

};
