// Jay(wnwoghd22) All Rights Reserved.


#include "Character/WSRCharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "WSRCharacterControlData.h"
#include "Physics/WSRCollision.h"

AWSRCharacterPlayer::AWSRCharacterPlayer()
{
	// Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Input
	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionChangeControlRef(TEXT("/Script/EnhancedInput.InputAction'/Game/WhenSunRises/Input/Actions/IA_ChangeControl.IA_ChangeControl'"));
	if (InputActionChangeControlRef.Object != nullptr)
	{
		ChangeControlAction = InputActionChangeControlRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpRef(TEXT("/Script/EnhancedInput.InputAction'/Game/WhenSunRises/Input/Actions/IA_Jump.IA_Jump'"));
	if (InputActionJumpRef.Object != nullptr)
	{
		JumpAction = InputActionJumpRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionFocusingMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/WhenSunRises/Input/Actions/IA_FocusingMove.IA_FocusingMove'"));
	if (InputActionFocusingMoveRef.Object != nullptr)
	{
		FocusingMoveAction = InputActionFocusingMoveRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionFocusingLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/WhenSunRises/Input/Actions/IA_FocusingLook.IA_FocusingLook'"));
	if (InputActionFocusingLookRef.Object != nullptr)
	{
		FocusingLookAction = InputActionFocusingLookRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionFocusingHitRef(TEXT("/Script/EnhancedInput.InputAction'/Game/WhenSunRises/Input/Actions/IA_FocusingHit.IA_FocusingHit'"));
	if (InputActionFocusingHitRef.Object != nullptr)
	{
		FocusingHitAction = InputActionFocusingHitRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/WhenSunRises/Input/Actions/IA_ShoulderMove.IA_ShoulderMove'"));
	if (InputActionShoulderMoveRef.Object != nullptr)
	{
		ShoulderMoveAction = InputActionShoulderMoveRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionShoulderLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/WhenSunRises/Input/Actions/IA_ShoulderLook.IA_ShoulderLook'"));
	if (InputActionShoulderLookRef.Object != nullptr)
	{
		ShoulderLookAction = InputActionShoulderLookRef.Object;
	}
	CurrentCharacterControlType = ECharacterControlType::Shoulder;

	InteractionTraceRange = 150.0f;
}

void AWSRCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();

	SetCharacterControl(CurrentCharacterControlType);
}

void AWSRCharacterPlayer::Tick(float DeltaSeconds)
{
	/** TODO:
	 * make crosshair when focusing mode.
	 * line trace to catch interactable,
	 * if on hit, change crosshair
	 */
}

void AWSRCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComponent->BindAction(FocusingMoveAction, ETriggerEvent::Triggered, this, &AWSRCharacterPlayer::FocusingMove);
	EnhancedInputComponent->BindAction(FocusingLookAction, ETriggerEvent::Triggered, this, &AWSRCharacterPlayer::FocusingLook);
	EnhancedInputComponent->BindAction(FocusingHitAction, ETriggerEvent::Triggered, this, &AWSRCharacterPlayer::FocusingHit);
	EnhancedInputComponent->BindAction(ShoulderMoveAction, ETriggerEvent::Triggered, this, &AWSRCharacterPlayer::ShoulderMove);
	EnhancedInputComponent->BindAction(ShoulderLookAction, ETriggerEvent::Triggered, this, &AWSRCharacterPlayer::ShoulderLook);
	EnhancedInputComponent->BindAction(ChangeControlAction, ETriggerEvent::Triggered, this, &AWSRCharacterPlayer::ChangeCharacterControl);
}

void AWSRCharacterPlayer::ChangeCharacterControl()
{
	if (CurrentCharacterControlType == ECharacterControlType::Focusing)
	{
		SetCharacterControl(ECharacterControlType::Shoulder);
	}
	else if (CurrentCharacterControlType == ECharacterControlType::Shoulder)
	{
		SetCharacterControl(ECharacterControlType::Focusing);
	}
}

void AWSRCharacterPlayer::SetCharacterControl(ECharacterControlType NewCharacterControlType)
{
	UWSRCharacterControlData* NewCharacterControl = CharacterControlManager[NewCharacterControlType];
	check(NewCharacterControl);

	SetCharacterControlData(NewCharacterControl);

	APlayerController* PlayerController = CastChecked<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		UInputMappingContext* NewMappingContext = NewCharacterControl->InputMappingContext;
		if (NewMappingContext)
		{
			Subsystem->AddMappingContext(NewMappingContext, 0);
		}
	}
	CurrentCharacterControlType = NewCharacterControlType;
}

void AWSRCharacterPlayer::SetCharacterControlData(const UWSRCharacterControlData* CharacterControlData)
{
	Super::SetCharacterControlData(CharacterControlData);

	CameraBoom->TargetArmLength = CharacterControlData->TargetArmLength;
	CameraBoom->SetRelativeRotation(CharacterControlData->RelativeRotation);
	CameraBoom->bUsePawnControlRotation = CharacterControlData->bUsePawnControlRotation;
	CameraBoom->bInheritPitch = CharacterControlData->bInheritPitch;
	CameraBoom->bInheritYaw = CharacterControlData->bInheritYaw;
	CameraBoom->bInheritRoll = CharacterControlData->bInheritRoll;
	CameraBoom->bDoCollisionTest = CharacterControlData->bDoColliisonTest;

	FollowCamera->SetRelativeLocation(CharacterControlData->CameraRelativeLocation);
}

void AWSRCharacterPlayer::FocusingMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);
}

void AWSRCharacterPlayer::FocusingLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void AWSRCharacterPlayer::FocusingHit()
{
	FHitResult OutHitResult;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(Interact), false, this);

	const FVector& TraceDirection = FollowCamera->GetForwardVector();
	const FVector& Start = FollowCamera->GetComponentLocation() + TraceDirection * (CameraBoom->TargetArmLength + 10.0f);
	const FVector End = Start + TraceDirection * InteractionTraceRange;

	bool HitDetected = GetWorld()->LineTraceSingleByChannel(OutHitResult, Start, End, CCHANNEL_WSR_HIT, Params);
	if (HitDetected)
	{
		/** 
		 * TODO: make interactable interface and cast here
		 * - make less dependency
		 */

		OutHitResult.GetActor()->Destroy();
	}

#if ENABLE_DRAW_DEBUG

	FColor DrawColor = HitDetected ? FColor::Green : FColor::Red;
	DrawDebugLine(GetWorld(), Start, End, DrawColor, false, 10.0f);

#endif
}

void AWSRCharacterPlayer::ShoulderMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);
}

void AWSRCharacterPlayer::ShoulderLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}
