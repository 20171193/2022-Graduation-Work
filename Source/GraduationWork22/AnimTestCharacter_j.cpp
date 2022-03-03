// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimTestCharacter_j.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Engine/Source/Runtime/Engine/Classes/GameFramework/Character.h"

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

	SprintSpeedMultiplier = 2.0f;
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

	InputComponent->BindAction("Sprint", IE_Pressed, this, &AAnimTestCharacter_j::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &AAnimTestCharacter_j::StopSprinting);
}

void AAnimTestCharacter_j::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}
void AAnimTestCharacter_j::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}
void AAnimTestCharacter_j::ActRoll(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}
void AAnimTestCharacter_j::Sprint()
{
	//GetCharacterMovement()->
}

