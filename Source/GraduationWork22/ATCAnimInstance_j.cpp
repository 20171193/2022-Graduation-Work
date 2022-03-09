// Fill out your copyright notice in the Description page of Project Settings.


#include "ATCAnimInstance_j.h"
#include "Engine/Classes/GameFramework/Character.h"
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"

UATCAnimInstance_j::UATCAnimInstance_j()
{
	CurrentPawnSpeed = 0.0f;
}

void UATCAnimInstance_j::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();

		isSit = Pawn->GetMovementComponent()->IsCrouching();
	}
}