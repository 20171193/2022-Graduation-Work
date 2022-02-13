// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor_K.h"
#include "Engine.h"

// Sets default values
AMyTestActor_K::AMyTestActor_K()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello world"));
}

// Called when the game starts or when spawned
void AMyTestActor_K::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestActor_K::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

