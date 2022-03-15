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

	//GetCharacterMovement()->JumpZVelocity = 200.0f;	// 점프 높이
	//JumpMaxCount = 1;	// 점프 가능 횟수
	//JumpMaxHoldTime = 0.5f;	// 체공 시간

	maxStamina = 10.0f;
	currentStamina = 10.0f;

	// 스테미너 소진 카운트
	callStaminaCount = 0;
	// 스테미너 소진 시 딜레이
	waitCount = 3;

	sprintSpeed = 250.0f;
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

// 앉기 기능 활성화, 비 활성화
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
	// 탈진 상태가 아닌 경우
	if (currentStamina > 0)
	{
		// 달리는 중 ConsumeStamina 함수 1초에 1번 씩 maxStamina 만큼 실행
		GetWorldTimerManager().SetTimer(staminaTH, this, &AAnimTestCharacter_j::ConsumeStamina, 1.0f, true, maxStamina);
		GetCharacterMovement()->MaxWalkSpeed += sprintSpeed;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("stamina = 0"));
		StopSprinting();
	}
}
void AAnimTestCharacter_j::StopSprinting()
{
	if (currentStamina > 0)
	{
		GetCharacterMovement()->MaxWalkSpeed -= sprintSpeed;
		RecoverStamina();
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 0;
		RecoverStamina();
	}
}
void AAnimTestCharacter_j::ConsumeStamina()
{
	//--currentStamina;
	//// 탈진 상태일 경우 
	//if (currentStamina <= 0)
	//{
	//	GetWorldTimerManager().ClearTimer(staminaTH);
	//	RecoverStamina();
	//}
}
void AAnimTestCharacter_j::RecoverStamina()
{
	//// 탈진 상태 회복모드
	//if (currentStamina <= 0)
	//{
	//	// 탈진 딜레이 적용  
	//	GetWorld()->GetTimerManager().SetTimer(waitHandle, FTimerDelegate::CreateLambda([&]()
	//		{
	//			GetWorld()->GetTimerManager().ClearTimer(waitHandle);
	//		}), waitCount, false);
	//	UE_LOG(LogTemp, Log, TEXT("delay finished"));
	//}
	//// 기본 회복모드
	//else
	//{

	//}
}

