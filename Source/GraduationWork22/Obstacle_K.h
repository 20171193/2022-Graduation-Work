// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle_K.generated.h"


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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* Box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* ObstacleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* SceneLoot;

	UFUNCTION(BlueprintCallable)
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



	 UFUNCTION(BlueprintCallable, Category = "Active")
		 void ActiveTrue();

	 UFUNCTION(BlueprintCallable, Category = "Active")
		 void ActiveFalse();

	 UFUNCTION(BlueprintCallable, Category = "Shoot")
		 void Shoot();

	 UFUNCTION(BlueprintImplementableEvent, Category = "Damage")
		 void Damage(class AActor* OtherActor);
};
