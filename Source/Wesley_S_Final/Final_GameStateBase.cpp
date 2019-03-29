// Fill out your copyright notice in the Description page of Project Settings.

#include "Final_GameStateBase.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"

AFinal_GameStateBase::AFinal_GameStateBase()
{
    bIsPlayerOneLoggedIn = false;
    bIsPlayerTwoLoggedIn = false;
    //SetReplicates(true);
}

void AFinal_GameStateBase::Multicast_SetScoreTeamOne_Implementation(int Score)
{
    TeamOneScore = Score;
}

void AFinal_GameStateBase::Multicast_SetScoreTeamTwo_Implementation(int Score)
{
    TeamTwoScore = Score;
}

//TODO Week 7: REPLICATE Variables
void AFinal_GameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    //REPLICATE 
    //DOREPLIFETIME(AFinal_GameStateBase, TeamsEnabled);
    DOREPLIFETIME(AFinal_GameStateBase, TeamOneScore);
    DOREPLIFETIME(AFinal_GameStateBase, TeamTwoScore);

    DOREPLIFETIME(AFinal_GameStateBase, bIsPlayerOneLoggedIn);
    DOREPLIFETIME(AFinal_GameStateBase, bIsPlayerTwoLoggedIn);

    //DOREPLIFETIME(ABaseGameState, TeamOneSize);
    //DOREPLIFETIME(ABaseGameState, TeamTwoSize);
    //DOREPLIFETIME(ABaseGameState, GameTime);

    DOREPLIFETIME(AFinal_GameStateBase, TeamOnePMaterials);
    DOREPLIFETIME(AFinal_GameStateBase, TeamTwoPMaterials);
    DOREPLIFETIME(AFinal_GameStateBase, TeamThreePMaterials);
}



