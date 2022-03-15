// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfMonster_K.h"
#include "BAI_K.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ASelfMonster_K::ASelfMonster_K()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
	
	
	/*CapsuleComponent->SetSimulatePhysics(true);
	CapsuleComponent->SetNotifyRigidBodyCollision(true);*/

	/*CapsuleComponent->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	CapsuleComponent->OnComponentHit.AddDynamic(this, &ASelfMonster_K::OnCompHit);

	 
	RootComponent = CapsuleComponent;*/
	
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

void ASelfMonster_K::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit")));
	
}

