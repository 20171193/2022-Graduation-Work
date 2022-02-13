// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter_K.h"
#include "MyTestCharacter_K.generated.h"

/**
 * 
 */
UCLASS()
class GRADUATIONWORK22_API AMyTestCharacter_K : public ABasicCharacter_K
{
	GENERATED_BODY()
	
public:
	AMyTestCharacter_K();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;
};
