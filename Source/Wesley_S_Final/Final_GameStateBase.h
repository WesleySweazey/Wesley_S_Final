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
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (ClampMin = 0), Replicated)
        int TeamOneScore;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (ClampMin = 0), Replicated)
        int TeamTwoScore;
	
    //UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
        class UMaterialInterface* TeamOnePMaterials;

    //UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Materials, Replicated)
        class UMaterialInterface* TeamTwoPMaterials;
};
