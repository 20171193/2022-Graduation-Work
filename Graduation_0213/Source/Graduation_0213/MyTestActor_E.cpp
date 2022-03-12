// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor_E.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BasedCharacter_E.h"
#include "TestCharacter.h"
#include "Engine.h"

// Sets default values
AMyTestActor_E::AMyTestActor_E()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OBJ"));
	RootComponent = mStaticMesh;

	//CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	//CollisionSphere->InitSphereRadius(100.0f);
	//CollisionSphere->SetupAttachment(RootComponent);

	CollisionBox_Y = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox_Y"));
	CollisionBox_Y->InitBoxExtent(FVector(100.0f,100.0f,100.0f));
	CollisionBox_Y->SetupAttachment(RootComponent);

	CollisionBox_X = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox_X"));
	CollisionBox_X->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	CollisionBox_X->SetupAttachment(RootComponent);

	//CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AMyTestActor_E::OnOverlapBegin);
	CollisionBox_Y->OnComponentBeginOverlap.AddDynamic(this, &AMyTestActor_E::OnOverlapBegin);
	CollisionBox_X->OnComponentBeginOverlap.AddDynamic(this, &AMyTestActor_E::OnOverlapBegin);
}


// Called when the game starts or when spawned
void AMyTestActor_E::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyTestActor_E::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTestActor_E::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&
	SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch"));
	/*if (OtherActor->IsA(ATestCharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch"));
		Destroy();
	}*/
}