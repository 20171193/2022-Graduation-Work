// Fill out your copyright notice in the Description page of Project Settings.


#include "ATCAnimInstance_j.h"
#include "Engine/Classes/GameFramework/Character.h"
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"

UATCAnimInstance_j::UATCAnimInstance_j()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ROLL_MONTAGE(TEXT("AnimMontage'/Game/ShimJaeChun/Anim_j/RollMontage.RollMontage'"));
	if (ROLL_MONTAGE.Succeeded())
	{
		rollMontage = ROLL_MONTAGE.Object;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Montage error");
	}
	isSit = false;
	currentPawnSpeed = 0.0f;
}

void UATCAnimInstance_j::PlayRollMontage()
{
	Montage_Play(rollMontage, 1.0f);
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


		// 점프, 공중에 떠 있는 경우 예외처리
		if (isInAir)
		{
			character->sitAble = false;
			character->rollAble = false;
			if (isSit)
			{
				character->sitAble = true;
				character->UnCrouch();
			}
		}
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