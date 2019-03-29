// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/GameMode.h"
#include "GameFramework/PlayerStart.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Wesley_S_FinalGameMode.generated.h"

UCLASS(minimalapi)
class AWesley_S_FinalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWesley_S_FinalGameMode();
    bool GameOver;

    UFUNCTION(BlueprintGetter)
    bool GetEnd() { return GameOver; }
    //TODO Week 7: Override from GameMode to handle when a new player logs in
    virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

    virtual void BeginPlay() override;

    //virtual void Tick(float deltatime) override;
    UFUNCTION(NetMulticast, Reliable)
        void Multicast_SetCubeColours();

    void CheckForEnd();
private:
    //TODO Week 7: Handle the new player
    void HandleNewPlayer(APlayerController* NewPlayer);
    
};



