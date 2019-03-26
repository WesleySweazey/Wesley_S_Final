// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubePiece.generated.h"

UCLASS()
class WESLEY_S_FINAL_API ACubePiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubePiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
        int Team;
    UPROPERTY(VisibleAnywhere, Category = "Collision",
        meta = (AllowPrivateAccess))
        class UBoxComponent* BoxComponent;
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UBoxComponent* GetCollisionBox() { return BoxComponent; }
    
    int GetTeam() {return Team; }
    void SetTeam(int value) { Team = value; }
};
