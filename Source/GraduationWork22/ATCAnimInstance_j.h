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

	// 구르기 애니메이션 실행
	void PlayRollMontage();

private:
	AAnimTestCharacter_j* character;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Roll", Meta = (AllowPrivateAccess = true))
	UAnimMontage* rollMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	float currentPawnSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	bool isSit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", Meta = (AllowPrivateAccess = true))
	bool isInAir;
};
