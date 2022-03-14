// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter_j.h"

// Sets default values
ABasicCharacter_j::ABasicCharacter_j()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicCharacter_j::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter_j::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter_j::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

