// Fill out your copyright notice in the Description page of Project Settings.

#include "CubePiece.h"
#include "Components/BoxComponent.h"

// Sets default values
ACubePiece::ACubePiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SetReplicates(true);
    BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Collision");
    BoxComponent->SetCollisionProfileName("OverlapAllDynamic");
    /*BoxComponent->OnComponentBeginOverlap.AddDynamic(this,
        &ATripWireTrap::OnOverlapBegin);*/
    BoxComponent->AttachTo(RootComponent);
    Tags.Add("CubePiece");
}

// Called when the game starts or when spawned
void ACubePiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubePiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubePiece::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
}
