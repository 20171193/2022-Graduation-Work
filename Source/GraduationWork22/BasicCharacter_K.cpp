// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter_K.h"

// Sets default values
ABasicCharacter_K::ABasicCharacter_K()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicCharacter_K::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter_K::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter_K::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

