// Fill out your copyright notice in the Description page of Project Settings.


#include "BasedCharacter_E.h"

// Sets default values
ABasedCharacter_E::ABasedCharacter_E()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasedCharacter_E::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasedCharacter_E::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasedCharacter_E::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

