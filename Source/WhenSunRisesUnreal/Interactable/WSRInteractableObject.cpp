// Jay(wnwoghd22) All Rights Reserved.


#include "Interactable/WSRInteractableObject.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Physics/WSRCollision.h"

// Sets default values
AWSRInteractableObject::AWSRInteractableObject()
{
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Trigger;
	Mesh->SetupAttachment(Trigger);

	Trigger->SetCollisionProfileName(CPROFILE_WSR_INTERACTABLE);

	Mesh->SetRelativeLocation(FVector::ZeroVector);
}

void AWSRInteractableObject::Interact()
{
	K2_OnInteract();
}
