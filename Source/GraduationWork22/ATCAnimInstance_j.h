// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ATCAnimInstance_j.generated.h"

/**
 * 
 */
UCLASS()
class GRADUATIONWORK22_API UATCAnimInstance_j : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UATCAnimInstance_j();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	bool isSit;
};
