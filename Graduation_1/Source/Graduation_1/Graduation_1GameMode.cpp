// Copyright Epic Games, Inc. All Rights Reserved.

#include "Graduation_1GameMode.h"
#include "Graduation_1Character.h"
#include "UObject/ConstructorHelpers.h"

AGraduation_1GameMode::AGraduation_1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
