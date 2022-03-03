// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimTestCharacter.h"

// Sets default values
AAnimTestCharacter::AAnimTestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnimTestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimTestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAnimTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AAnimTestCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AAnimTestCharacter::MoveRight);
	InputComponent->BindAxis("ActRoll", this, &AAnimTestCharacter::ActRoll);
}

void AAnimTestCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}

void AAnimTestCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}

void AAnimTestCharacter::ActRoll(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}