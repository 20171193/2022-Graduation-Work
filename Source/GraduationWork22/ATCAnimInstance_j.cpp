// Fill out your copyright notice in the Description page of Project Settings.


#include "ATCAnimInstance_j.h"
#include "Engine/Classes/GameFramework/Character.h"
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"

UATCAnimInstance_j::UATCAnimInstance_j()
{
	isSit = false;
	isLadder = false;
	isPushing = false;
	currentPawnSpeed = 0.0f;
}

void UATCAnimInstance_j::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	APawn* Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		character = Cast<AAnimTestCharacter_j>(Pawn);
	}
}

void UATCAnimInstance_j::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (::IsValid(character))
	{
		currentPawnSpeed = character->GetVelocity().Size();
		isSit = character->GetMovementComponent()->IsCrouching();
		isInAir = character->GetCharacterMovement()->IsFalling();

		isDeath = character->IsDeath;
		isLadder = character->IsLadder2;
		isPushing = character->IsPushing2;
		isInswarmp = character->isInSwamp;
	
		if (character->isInSwamp)
		{
			character->GetCharacterMovement()->JumpZVelocity = character->swampjumpZvelocity;
		}
		else
		{
			character->GetCharacterMovement()->JumpZVelocity = character->jumpZvelocity;
		}

		// 점프, 공중에 떠 있는 경우 예외처리
		if (isInAir)
		{
			character->sitAble = false;
			character->rollAble = false;
			
			// 앉은 상태로 낙하할 경우
			if (isSit)
			{
				character->sitAble = true;
				character->UnCrouch();
			}
		}
		// 공중에 떠 있지 않은 경우
		else
		{
			// 앉은 경우 재 입력 방지
			if (isSit)
			{
				character->sitAble = false;
			}
			else
			{
				character->sitAble = true;
			}
			character->rollAble = true;
		}
	}
}