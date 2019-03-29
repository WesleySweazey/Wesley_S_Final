// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Final_GameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class WESLEY_S_FINAL_API AFinal_GameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
    AFinal_GameStateBase();

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (ClampMin = 0), Replicated)
        int TeamOneScore;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (ClampMin = 0), Replicated)
        int TeamTwoScore;
	
    int GetScoreTeamOne() { return TeamOneScore; }
    int GetScoreTeamTwo() { return TeamTwoScore; }

    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetScoreTeamOne(int Score);
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetScoreTeamTwo(int Score);

    //UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
        class UMaterialInterface* TeamOnePMaterials;

    //UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
        class UMaterialInterface* TeamTwoPMaterials;

    //UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
        class UMaterialInterface* TeamThreePMaterials;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay, Replicated)
        bool bIsPlayerOneLoggedIn;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay, Replicated)
        bool bIsPlayerTwoLoggedIn;
};
