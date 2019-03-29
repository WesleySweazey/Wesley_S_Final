// Fill out your copyright notice in the Description page of Project Settings.

#include "CubePiece.h"
#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"
#include "Final_GameStateBase.h"

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
    //SetReplicates(true);
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
    UStaticMeshComponent* box = Cast<UStaticMeshComponent>(this->GetComponentByClass(UStaticMeshComponent::StaticClass()));
    box->SetMaterial(0, DefaultMaterial);
}

void ACubePiece::Multicast_AssignColors_Implementation()
{
    UMaterialInterface* InMaterialsBlue;
    UMaterialInterface* InMaterialsRed;
    UMaterialInterface* InMaterialsGreen;

    //SET/ASSIGN DefaultTPMaterials to the GameStates's TeamOnePMaterials
    AFinal_GameStateBase* GameState = Cast<AFinal_GameStateBase>(GetWorld()->GetGameState());
    InMaterialsBlue = GameState->TeamOnePMaterials;
    InMaterialsRed = GameState->TeamTwoPMaterials;
    InMaterialsGreen = GameState->TeamThreePMaterials;

        int rand = FMath::RandRange(0, 2);
        if (rand == 0)
        {
            DefaultMaterial = InMaterialsBlue;
        }
        else if (rand == 1)
        {
            DefaultMaterial = InMaterialsRed;
        }
        else if (rand == 2)
        {
            DefaultMaterial = InMaterialsGreen;
        }
        Team = rand;
}

void ACubePiece::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
}

void ACubePiece::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ACubePiece, DefaultMaterial);
    DOREPLIFETIME(ACubePiece, Team);
}

//TODO: OnClientDeath Validate Function
bool ACubePiece::NetMulticast_Destruction_Validate()
{
    return true;
}

void ACubePiece::NetMulticast_Destruction_Implementation()
{
    Destroy();
}