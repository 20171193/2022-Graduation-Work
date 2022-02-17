// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasedCharacter_E.generated.h"

UCLASS()
class GRADUATION_0213_API ABasedCharacter_E : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasedCharacter_E();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
