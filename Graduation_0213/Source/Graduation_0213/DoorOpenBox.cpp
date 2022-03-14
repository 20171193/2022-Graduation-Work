// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpenBox.h"

// Sets default values
ADoorOpenBox::ADoorOpenBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OBJ"));
	RootComponent = mStaticMesh;

}

// Called when the game starts or when spawned
void ADoorOpenBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorOpenBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

