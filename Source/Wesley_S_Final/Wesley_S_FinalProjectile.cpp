// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Wesley_S_FinalProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "CubePiece.h"
#include "Components/BoxComponent.h"
#include "Wesley_S_FinalCharacter.h"
#include "Wesley_S_Final/Final_GameStateBase.h"
AWesley_S_FinalProjectile::AWesley_S_FinalProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AWesley_S_FinalProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
    SetReplicates(true);
    SetReplicateMovement(true);
}

void AWesley_S_FinalProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics

        /*if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
        {
            OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
        }*/
        if (OtherActor)
        {
            if (Role == ROLE_Authority) //Checks whether we are the server
            {
                if (OtherActor->ActorHasTag("CubePiece"))
                {
                    ACubePiece* cube = Cast<ACubePiece>(OtherActor);
                    /*if (Team == cube->GetTeam())
                    {*/

                    TArray<AActor*> Overlapping;
                    AActor* player = this->GetOwner();
                    AWesley_S_FinalCharacter * playerCharacter = Cast<AWesley_S_FinalCharacter>(player);
                    RecurseSearch(cube, Overlapping);
                    for (int i = 0; i < Overlapping.Num(); i++)
                    {

                        Overlapping[i]->Destroy();
                        /*if (Team == 1)
                        {
                            playerCharacter->GetLocalGameState()->TeamOneScore++;
                        }
                        if (Team == 2)
                        {
                            playerCharacter->GetLocalGameState()->TeamTwoScore++;
                        }*/
                        playerCharacter->Score++;
                    }
                    cube->NetMulticast_Destruction();
                    //}
                }
            }
            Destroy();
        }
}

void AWesley_S_FinalProjectile::RecurseSearch(AActor* Cube, TArray<AActor*> &ArrayOfFound)
{
    //Get the Overlapping Cubes for the Cube
        //    For Each actor in the overlapping Cubes
        //    IF the actor Color is the same as the Cube Color
        //    Add the actor to the ArrayOfFound // make sure actor is not already part of arrayoffound
        //    RecurseSearch on actor
        //    ENDIF
        //    ENDFOR
    TArray<AActor*> overlappingActors;
    ACubePiece* castCube = Cast<ACubePiece>(Cube);
    castCube->GetCollisionBox()->GetOverlappingActors(overlappingActors, ACubePiece::StaticClass());
    for (int i = 0; i < overlappingActors.Num(); i++)
    {
        ACubePiece* tempCube = Cast<ACubePiece>(overlappingActors[i]);
        if (castCube->GetTeam() == tempCube->GetTeam())
        {
            if (ArrayOfFound.Find(overlappingActors[i]) == INDEX_NONE)
            {
                ArrayOfFound.Add(overlappingActors[i]);
                RecurseSearch(overlappingActors[i], ArrayOfFound);
            }
        }
    }
}