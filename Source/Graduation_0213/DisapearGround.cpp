// Fill out your copyright notice in the Description page of Project Settings.


#include "DisapearGround.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "TestCharacter.h"
#include "Engine.h"

// Sets default values
ADisapearGround::ADisapearGround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mSMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OBJ"));
	RootComponent = mSMesh;


	DAGCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DAGCollisionBox"));
	DAGCollisionBox->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	DAGCollisionBox->SetupAttachment(RootComponent);

	DAGCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ADisapearGround::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ADisapearGround::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADisapearGround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADisapearGround::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&
	SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch"));
	/*if (OtherActor->IsA(ATestCharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch"));
		Destroy();
	}*/
}