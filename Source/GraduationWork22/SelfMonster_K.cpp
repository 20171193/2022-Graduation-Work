// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfMonster_K.h"
#include "BAI_K.h"

// Sets default values
ASelfMonster_K::ASelfMonster_K()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ABAI_K::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void ASelfMonster_K::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASelfMonster_K::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASelfMonster_K::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

