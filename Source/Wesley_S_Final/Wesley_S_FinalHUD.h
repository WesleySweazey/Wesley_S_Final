// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Wesley_S_FinalHUD.generated.h"

UCLASS()
class AWesley_S_FinalHUD : public AHUD
{
	GENERATED_BODY()

public:
	AWesley_S_FinalHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

