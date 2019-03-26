// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Wesley_S_FinalGameMode.h"
#include "Wesley_S_FinalHUD.h"
#include "Wesley_S_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Final_GameStateBase.h"
#include "CubePiece.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"

AWesley_S_FinalGameMode::AWesley_S_FinalGameMode()
	: Super()
{
	//// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	//// use our custom HUD class
	//HUDClass = AWesley_S_FinalHUD::StaticClass();
}

void AWesley_S_FinalGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
    //CALL Super Function
    Super::HandleStartingNewPlayer_Implementation(NewPlayer);
    //CALL HandleNewPlayer() pass in NewPlayer
    HandleNewPlayer(NewPlayer);
}

void AWesley_S_FinalGameMode::BeginPlay()
{
    if (Role == ROLE_Authority) //Checks whether we are the server
    {
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACubePiece::StaticClass(), FoundActors);
    TArray<UMaterialInterface*> InMaterials;
    
    //SET/ASSIGN DefaultTPMaterials to the GameStates's TeamOnePMaterials
    AFinal_GameStateBase* GameState = Cast<AFinal_GameStateBase>(GetWorld()->GetGameState());
    InMaterials.Add(GameState->TeamOnePMaterials);
    InMaterials.Add(GameState->TeamTwoPMaterials);
    for (int i = 0; i < FoundActors.Num(); i++)
    {
        //CALL ApplyMaterialsToMesh() and pass in GetSkeletalMesh(), DefaultTPMaterials
        UStaticMeshComponent* box = Cast<UStaticMeshComponent>(FoundActors[i]->GetComponentByClass(UStaticMeshComponent::StaticClass()));
        int rand = FMath::RandRange(0, 1);
        box->SetMaterial(rand, InMaterials[rand]);
        ACubePiece* cubetemp = Cast<ACubePiece>(FoundActors[i]);
        cubetemp->SetTeam(rand);
    }
    }
}

//TODO Week 7: Handle the new player that has logged in, assign team and net index
void AWesley_S_FinalGameMode::HandleNewPlayer(APlayerController* NewPlayer)
{
    //DECLARE a ACharacterBase* called character and assign it to the Cast of NewPlayer->GetPawn()
    AWesley_S_FinalCharacter* character = Cast<AWesley_S_FinalCharacter>(NewPlayer->GetPawn());
    //IF the character is not nullptr
    if (character)
    {
        //Draw a debug message saying character has logged in
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, "Character Logged In");
        //CALL AssignTeams() on the character
        //character->AssignTeams();
        //CALL AssignNetIndex() on the character
        //character->AssignNetIndex();
    }
    //ENDIF
}