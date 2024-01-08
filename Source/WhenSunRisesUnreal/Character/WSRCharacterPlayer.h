// Jay(wnwoghd22) All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/WSRCharacterBase.h"
#include "InputActionValue.h"
#include "Interface/WSRHUDInterface.h"
#include "WSRCharacterPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnFocusedDelegate, bool /*InOnFocusing*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTraceHitDelegate, bool /*InOnTraceHit*/);

/**
 * 
 */
UCLASS()
class WHENSUNRISESUNREAL_API AWSRCharacterPlayer : public AWSRCharacterBase, public IWSRHUDInterface
{
	GENERATED_BODY()
	
// Unreal Section
public:
	AWSRCharacterPlayer();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// Charactor Control Section
protected:
	void ChangeCharacterControl();
	void SetCharacterControl(ECharacterControlType NewCharacterControlType);
	virtual void SetCharacterControlData(const class UWSRCharacterControlData* CharacterControlData) override;

// Camera Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

// Input Section
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ChangeControlAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> FocusingMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> FocusingLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> FocusingHitAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderLookAction;

	/** Intaraction trace range */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, Meta = (AllowPrivateAccess = "true"))
	float InteractionTraceRange;

	/** Movement Callbacks for Focusing(aim-down-sight) mode. */
	void FocusingMove(const FInputActionValue& Value);
	void FocusingLook(const FInputActionValue& Value);
	void FocusingHit();

	void ShoulderMove(const FInputActionValue& Value);
	void ShoulderLook(const FInputActionValue& Value);

	ECharacterControlType CurrentCharacterControlType;


// UI Widget Section
public:
	FOnFocusedDelegate OnFocused;
	FOnTraceHitDelegate OnTraceHit;

	virtual void SetupHUDWidget(class UWSRHUDWidget* InHUDWidget) override;

};
