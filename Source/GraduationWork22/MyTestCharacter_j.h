// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter_j.h"
#include "MyTestCharacter_j.generated.h"

/**
 * 
 */
UCLASS()
class GRADUATIONWORK22_API AMyTestCharacter_j : public ABasicCharacter_j
{
	GENERATED_BODY()
	
public:
	AMyTestCharacter_j();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* FollowCamera;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;

	void MoveFoward(float value);

	void MoveRight(float value);
};
