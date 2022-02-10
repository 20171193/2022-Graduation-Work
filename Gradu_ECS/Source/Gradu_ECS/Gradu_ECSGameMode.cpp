// Copyright Epic Games, Inc. All Rights Reserved.

#include "Gradu_ECSGameMode.h"
#include "Gradu_ECSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGradu_ECSGameMode::AGradu_ECSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
