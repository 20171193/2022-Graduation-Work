// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/SphereComponent.h>
#include <Engine/Classes/GameFramework/ProjectileMovementComponent.h>
#include "Projectile_E.generated.h"

UCLASS()
class GRADUATION_0213_API AProjectile_E : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile_E();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere,Category = "Projectile")
		USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere,Category="Movement")
		UProjectileMovementComponent* ProjectileMovementComponent;

	void FireInDirection(const FVector& ShootDirection);
};
