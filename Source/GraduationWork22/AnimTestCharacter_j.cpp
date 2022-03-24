// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimTestCharacter_j.h"
#include "ATCAnimInstance_j.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Engine/Classes/GameFramework/Character.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"

// Sets default values
AAnimTestCharacter_j::AAnimTestCharacter_j()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArmComponent->SetupAttachment(GetCapsuleComponent());
	CameraSpringArmComponent->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight));
	CameraSpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CameraSpringArmComponent, USpringArmComponent::SocketName);

	//GetCharacterMovement()->JumpZVelocity = 200.0f;	// ���� ����
	//JumpMaxCount = 1;	// ���� ���� Ƚ��
	//JumpMaxHoldTime = 0.5f;	// ü�� �ð�

	maxStamina = 5.0f;
	currentStamina = 5.0f;

	// ���׹̳� ���� ī��Ʈ
	callStaminaCount = 0;
	// ���׹̳� ���� �� ������
	waitCount = 3;

	sprintSpeed = 650.0f;
	walkSpeed = 400.0f;
	pushSpeed = 200.0f;

	sprintAble = true;
	rollAble = true;

	sitAble = true;
	isRoll = false;
	
	isLadder = false;
	climbable = false;
	isPush = false;
}

// Called when the game starts or when spawned
void AAnimTestCharacter_j::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAnimTestCharacter_j::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAnimTestCharacter_j::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AAnimTestCharacter_j::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AAnimTestCharacter_j::MoveRight);

	InputComponent->BindAction("ActRoll", IE_Pressed, this, &AAnimTestCharacter_j::ActRoll);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AAnimTestCharacter_j::Jump);
	InputComponent->BindAction("Sit", IE_Pressed, this, &AAnimTestCharacter_j::Sit);

	InputComponent->BindAction("Sprint", IE_Pressed, this, &AAnimTestCharacter_j::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &AAnimTestCharacter_j::StopSprinting);
}

void AAnimTestCharacter_j::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && !isLadder/*&& !isRoll*/)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
	else if ((Controller != NULL) && (value != 0.0f) && isLadder)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "is Ladder");
		AddMovementInput(FVector::UpVector, value);
	}
}
void AAnimTestCharacter_j::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && !isLadder/*&& !isRoll*/)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

void AAnimTestCharacter_j::StartJump()
{
	bPressedJump = true;
}

void AAnimTestCharacter_j::StopJump()
{
	bPressedJump = false;
}

// �ɱ� ��� Ȱ��ȭ, �� Ȱ��ȭ
// GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

void AAnimTestCharacter_j::Sit()
{
	if ((Controller != NULL) && sitAble)
	{
		Crouch();
	}
	else
	{
		UnCrouch();
	}
}

void AAnimTestCharacter_j::ActRoll()
{
	if (rollAble)
	{
		auto AnimInstance = Cast<UATCAnimInstance_j>(GetMesh()->GetAnimInstance());
		if (AnimInstance == nullptr)
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "No AnimInstance");

		//FVector rollingVector = this->GetActorForwardVector() * 1000.0f;
		AnimInstance->PlayRollMontage();
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this->Controller, this->GetVelocity() * 1000.0f);
		//this->LaunchCharacter(rollingVector, false, false);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Rolling");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "No Rolling");
	}
}


void AAnimTestCharacter_j::Sprint()
{
	if (!isPush)
	{ // ���׹̳ʰ� 0�� ���
		if (currentStamina <= 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Not yet Sprint");
		}
		// ���׹̳ʰ� 0�� �ƴ� ���
		else
		{
			// recover Ÿ�̸� ����
			GetWorldTimerManager().ClearTimer(recoverTH);
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "consume start");
			GetWorldTimerManager().SetTimer(consumeTH, this, &AAnimTestCharacter_j::ConsumeStamina, 0.1f, true);
		}
	}
}
void AAnimTestCharacter_j::StopSprinting()
{
	if (currentStamina <= 0 && !sprintAble)
	{
		// consume Ÿ�̸� ����
		GetWorldTimerManager().ClearTimer(consumeTH);
		GetWorld()->GetTimerManager().SetTimer(waitHandle, FTimerDelegate::CreateLambda([&]()
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.3f, FColor::Black, "Delay Finished");
				// ������ �� ����
				GetWorld()->GetTimerManager().ClearTimer(waitHandle);
				currentStamina += 3;
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, "recover start");
				GetWorldTimerManager().SetTimer(recoverTH, this, &AAnimTestCharacter_j::RecoverStamina, 0.1f, true);
				sprintAble = true;
			}), waitCount, false);
		}
		else if (sprintAble)
		{
			// consume Ÿ�̸� ����
			GetWorldTimerManager().ClearTimer(consumeTH);
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, "recover start");
			GetWorldTimerManager().SetTimer(recoverTH, this, &AAnimTestCharacter_j::RecoverStamina, 0.1f, true);
	}
}

// ���׹̳� ����
void AAnimTestCharacter_j::ConsumeStamina()
{

	if (this->GetVelocity().Size() >= 600.0f)
	{
		currentStamina -= 0.1f;
	}
	// ���׹̳� ��� ���� �� ĳ������ �ӵ� ����.
	if (currentStamina <= 0)
	{
		currentStamina = 0;
		sprintAble = false;
		GetWorldTimerManager().ClearTimer(consumeTH);
		GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
	}
	// ���׹̳ʰ� ���� ��� ĳ������ �ӵ� ����.
	else if(!isPush)
	{
		GetCharacterMovement()->MaxWalkSpeed = sprintSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = pushSpeed;
	}
}

// ���׹̳� ȸ��
void AAnimTestCharacter_j::RecoverStamina()
{
	if (!isPush)
	{
		GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
	}
	else 
	{
		GetCharacterMovement()->MaxWalkSpeed = pushSpeed;
	}
	currentStamina+=0.1f;
	// ���׹̳ʰ� 10 �̻��� ��� recover ����.
	if (currentStamina >= 5)
	{
		currentStamina = 5;
		GetWorldTimerManager().ClearTimer(recoverTH);
	}
	// �⺻ ȸ�����
}
float AAnimTestCharacter_j::GetMaxStamina()
{
	return maxStamina;
}

float AAnimTestCharacter_j::GetCurrentStamina()
{
	return currentStamina;
}
