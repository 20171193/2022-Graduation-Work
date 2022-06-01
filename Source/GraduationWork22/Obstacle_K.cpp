// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle_K.h"
#include "Components/BoxComponent.h"
//#include "GameFramework/Actor.h"

// Sets default values
AObstacle_K::AObstacle_K()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneLoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneLoot"));
	
	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));	
   
	RootComponent = SceneLoot;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(RootComponent);
	ObstacleMesh->SetupAttachment(RootComponent);
	
	Box->OnComponentBeginOverlap.AddDynamic(this, &AObstacle_K::OnOverlapBegin);
	
	
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

void AObstacle_K::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	
		if (OtherActor->ActorHasTag(TEXT("PLAYER"))) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit:Player")));
			Damage(OtherActor);
			if (finish == false)
				ActiveFalse();
		
			}
		}


	




void AObstacle_K::ActiveFalse()
{
	//this->SetActorTickEnabled(false);
	this->SetActorHiddenInGame(true);
	this->SetActorEnableCollision(false);
	
	
}
void AObstacle_K::ActiveTrue()
{
	//this->SetActorTickEnabled(true);
	this->SetActorHiddenInGame(false);
	this->SetActorEnableCollision(true);
	
}
void AObstacle_K::Shoot()
{

}