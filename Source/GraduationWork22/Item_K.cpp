// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_K.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
//#include "GameFramework/Actor.h"

// Sets default values
AItem_K::AItem_K()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneLoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneLoot"));

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));

	RootComponent = SceneLoot;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(RootComponent);
	ItemMesh->SetupAttachment(RootComponent);
	

	Box->OnComponentBeginOverlap.AddDynamic(this, &AItem_K::OnOverlapBegin);
}



// Called when the game starts or when spawned
void AItem_K::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem_K::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem_K::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor && (OtherActor != this) && OtherComp) {
		if (OtherActor->ActorHasTag(TEXT("PLAYER"))) {


		}

	}
	}

	void AItem_K::ActiveFalse()
	{
		this->SetActorTickEnabled(false);
		this->SetActorHiddenInGame(true);
		this->SetActorEnableCollision(false);


	}
	void AItem_K::ActiveTrue()
	{
		this->SetActorTickEnabled(true);
		this->SetActorHiddenInGame(false);
		this->SetActorEnableCollision(true);

	}


