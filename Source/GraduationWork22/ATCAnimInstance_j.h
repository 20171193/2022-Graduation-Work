// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimTestCharacter_j.h"
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
	
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void PlayRollMontage();

	UPROPERTY(EditAnywhere)
	EMoveMode moveMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AAnimTestCharacter_j* character;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	float currentPawnSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	bool isSit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	bool isInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	bool isLadder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	bool isPushing;

};
