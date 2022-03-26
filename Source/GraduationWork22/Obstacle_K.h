// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle_K.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USceneComponent;

UCLASS()
class GRADUATIONWORK22_API AObstacle_K : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle_K();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		 UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere)
		 UStaticMeshComponent* ObstacleMesh;

	UPROPERTY(EditAnywhere)
		 USceneComponent* Scene;
};
