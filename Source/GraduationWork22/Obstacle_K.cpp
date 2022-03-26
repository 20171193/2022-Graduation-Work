// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle_K.h"
#include "Components/BoxComponent.h"

// Sets default values
AObstacle_K::AObstacle_K()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));	
	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
	RootComponent = Scene;
	ObstacleMesh->SetupAttachment(Scene);
	ObstacleMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	ObstacleMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
   
	//Trigger->SetupAttachment(Scene);


	//Trigger->OnComponentBeginOverlap.AddDynamic(this, &AObstacle_K::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AObstacle_K::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle_K::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

