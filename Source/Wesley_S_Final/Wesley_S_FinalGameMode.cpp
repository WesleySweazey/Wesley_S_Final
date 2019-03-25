// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Wesley_S_FinalGameMode.h"
#include "Wesley_S_FinalHUD.h"
#include "Wesley_S_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWesley_S_FinalGameMode::AWesley_S_FinalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWesley_S_FinalHUD::StaticClass();
}
