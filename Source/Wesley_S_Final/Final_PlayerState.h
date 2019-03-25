// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Final_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class WESLEY_S_FINAL_API AFinal_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
        int PlayerTeam;

    /*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
        int Score;*/

        
};
