// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_K.generated.h"

UCLASS()
class GRADUATIONWORK22_API AItem_K : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem_K();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* Box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere)
		class USceneComponent* SceneLoot;

	UFUNCTION() 
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Active")
		void ActiveTrue();

	UFUNCTION(BlueprintCallable, Category = "Active")
		void ActiveFalse();

};
