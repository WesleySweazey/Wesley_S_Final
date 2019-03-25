// Fill out your copyright notice in the Description page of Project Settings.

#include "Final_PlayerState.h"
#include "Net/UnrealNetwork.h"

void AFinal_PlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(AFinal_PlayerState, PlayerTeam);
    //DOREPLIFETIME(AFinal_PlayerState, Score);
}

