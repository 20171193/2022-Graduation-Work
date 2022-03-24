// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_K.h"
#include "Components/BoxComponent.h"

// Sets default values
AItem_K::AItem_K()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrigger"));
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AItem_K::OnOverlapBegin);
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

