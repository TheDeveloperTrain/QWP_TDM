// Copyright Epic Games, Inc. All Rights Reserved.

#include "LP_MPGameMode.h"
#include "LP_MPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALP_MPGameMode::ALP_MPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
