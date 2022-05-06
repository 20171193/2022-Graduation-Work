// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingGround_E.h"
#include "Components/BoxComponent.h"
#include "Engine.h"
#include "BasicCharacter_j.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFallingGround_E::AFallingGround_E()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obj"));
	RootComponent = mStaticMesh;

	ForceStrength = 10000.0f;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetBoxExtent(FVector(20.f, 20.f, 20.f));
	CollisionBox->SetupAttachment(RootComponent);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AFallingGround_E::BoxBeginOverlap);

}

// Called when the game starts or when spawned
void AFallingGround_E::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFallingGround_E::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Up = mStaticMesh->GetUpVector();

	mStaticMesh->AddForce(Up * ForceStrength * mStaticMesh->GetMass());
}

void AFallingGround_E::BoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch!!"));
}

