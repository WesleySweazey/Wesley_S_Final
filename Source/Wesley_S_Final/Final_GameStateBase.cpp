// Fill out your copyright notice in the Description page of Project Settings.

#include "Final_GameStateBase.h"
#include "Net/UnrealNetwork.h"

//TODO Week 7: REPLICATE Variables
void AFinal_GameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    //REPLICATE 
    //DOREPLIFETIME(AFinal_GameStateBase, TeamsEnabled);
    DOREPLIFETIME(AFinal_GameStateBase, TeamOneScore);
    DOREPLIFETIME(AFinal_GameStateBase, TeamTwoScore);

    //DOREPLIFETIME(ABaseGameState, TeamOneMatchScore);
    //DOREPLIFETIME(ABaseGameState, TeamTwoMatchScore);

    //DOREPLIFETIME(ABaseGameState, TeamOneSize);
    //DOREPLIFETIME(ABaseGameState, TeamTwoSize);
    //DOREPLIFETIME(ABaseGameState, GameTime);

    DOREPLIFETIME(AFinal_GameStateBase, TeamOnePMaterials);
    DOREPLIFETIME(AFinal_GameStateBase, TeamTwoPMaterials);

}



