// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfMonster_K.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include <vector>
// Sets default values
ASelfMonster_K::ASelfMonster_K()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
	
	
	
}

// Called when the game starts or when spawned
void ASelfMonster_K::BeginPlay()
{
	Super::BeginPlay();
	this->Tags.Add(FName("ENEMY"));
	GetCapsuleComponent()->BodyInstance.SetCollisionProfileName("Pawn");
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ASelfMonster_K::OnCompHit);
	MonsterLocation = this->GetActorLocation();
	MonsterRotation = this->GetActorRotation();
	
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
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if (OtherActor->ActorHasTag(TEXT("PLAYER"))) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit:Player")));
			on = false;
			this->SetActorTickEnabled(false);
			this->SetActorHiddenInGame(true);
			this->SetActorEnableCollision(false);
			GetCapsuleComponent()->SetComponentTickEnabled(false);	
			Respone();
			Timer(10.0f);
			
		}
		else if (OtherActor->ActorHasTag(TEXT("DOOR"))) {
			
			OtherActor->Destroy();
			this->SetActorTickEnabled(false);
			this->SetActorHiddenInGame(true);
			this->SetActorEnableCollision(false);
			GetCapsuleComponent()->SetComponentTickEnabled(false);
			Respone();
			Timer(10.0f);
		}
	
	}
}

void ASelfMonster_K::Timer(float waitTimer)
	{
		GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
			{
				
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("aaaa")));
				 
				this->SetActorLocation(MonsterLocation);
				this->SetActorRotation(MonsterRotation);
				this->SetActorTickEnabled(true);
				this->SetActorHiddenInGame(false);
				this->SetActorEnableCollision(true);
				GetCapsuleComponent()->SetComponentTickEnabled(true);
				on = true;
				
			}), waitTimer, false);
	}

