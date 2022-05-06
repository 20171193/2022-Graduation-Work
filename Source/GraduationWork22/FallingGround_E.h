// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingGround_E.generated.h"

UCLASS()
class GRADUATIONWORK22_API AFallingGround_E : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFallingGround_E();

	UPROPERTY(EditAnywhere)
	float ForceStrength;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* mStaticMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void BoxBeginOverlap(
			UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

};
