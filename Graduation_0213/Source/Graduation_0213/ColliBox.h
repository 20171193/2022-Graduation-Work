// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile_E.h"
#include "ColliBox.generated.h"

UCLASS()
class GRADUATION_0213_API AColliBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColliBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
	class UBoxComponent* CollisionBox;

	UFUNCTION(BlueprintCallable, Category = "OnOverlapBegin_E")
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&
			SweepResult);

	UFUNCTION()
		void FIre();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "GamePlay")
		FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly,Category = "Projectile")
		TSubclassOf<AProjectile_E> ProjectileClass;

};
