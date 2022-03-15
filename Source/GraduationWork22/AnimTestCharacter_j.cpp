// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimTestCharacter_j.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Engine/Classes/GameFramework/Character.h"
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

	sprintSpeed = 250.0f;
	sprintAble = true;

	isSit = false;
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

	InputComponent->BindAxis("ActRoll", this, &AAnimTestCharacter_j::ActRoll);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AAnimTestCharacter_j::Jump);
	InputComponent->BindAction("Sit", IE_Pressed, this, &AAnimTestCharacter_j::Sit);

	InputComponent->BindAction("Sprint", IE_Pressed, this, &AAnimTestCharacter_j::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &AAnimTestCharacter_j::StopSprinting);
}

void AAnimTestCharacter_j::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}
void AAnimTestCharacter_j::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
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
	if ((Controller != NULL) && !isSit)
	{
		Crouch();
		isSit = true;
	}
	else
	{
		UnCrouch();
		isSit = false;
	}
}

void AAnimTestCharacter_j::ActRoll(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}


void AAnimTestCharacter_j::Sprint()
{
	// ���׹̳ʰ� 0�� ���
	if (currentStamina <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Not yet Sprint");
	}
	// ���׹̳ʰ� 0�� �ƴ� ���
	else
	{
		// recover Ÿ�̸� ����
		GetWorldTimerManager().ClearTimer(recoverTH);
		GetWorldTimerManager().SetTimer(consumeTH, this, &AAnimTestCharacter_j::ConsumeStamina, 1.0f, true);
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
				GetWorldTimerManager().SetTimer(recoverTH, this, &AAnimTestCharacter_j::RecoverStamina, 1.0f, true);
				sprintAble = true;
			}), waitCount, false);
	}
	else if(sprintAble)
	{
		// consume Ÿ�̸� ����
		GetWorldTimerManager().ClearTimer(consumeTH);
		GetWorldTimerManager().SetTimer(recoverTH, this, &AAnimTestCharacter_j::RecoverStamina, 1.0f, true);
	}
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}

// ���׹̳� ����
void AAnimTestCharacter_j::ConsumeStamina()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, "consume start");
	--currentStamina;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::SanitizeFloat(currentStamina));
	// ���׹̳� ��� ���� �� ĳ������ �ӵ� ����.
	if (currentStamina <= 0)
	{
		currentStamina = 0;
		sprintAble = false;
		GetWorldTimerManager().ClearTimer(consumeTH);
		GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	}
	// ���׹̳ʰ� ���� ��� ĳ������ �ӵ� ����.
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 650.0f;
	}
}

// ���׹̳� ȸ��
void AAnimTestCharacter_j::RecoverStamina()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, "recover start");
	++currentStamina;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::SanitizeFloat(currentStamina));
	// ���׹̳ʰ� 10 �̻��� ��� recover ����.
	if (currentStamina >= 5)
	{
		currentStamina = 5;
		GetWorldTimerManager().ClearTimer(recoverTH);
	}
	// �⺻ ȸ�����

}

