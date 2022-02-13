// Copyright Epic Games, Inc. All Rights Reserved.

#include "Graduation_0213GameMode.h"
#include "Graduation_0213Character.h"
#include "UObject/ConstructorHelpers.h"

AGraduation_0213GameMode::AGraduation_0213GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
