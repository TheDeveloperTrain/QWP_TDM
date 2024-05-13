// TeamInitializer.cpp
#include "TeamInitializer.h"
#include "LP_MPCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "TeamASpawnPoints.h"
#include "TeamBSpawnPoints.h"

bool ATeamInitializer::InitializeTeam()
{
    bool TeamInitialized = false;

    MaxTeamSize = 4;

    if (MaxTeamSize > 0)
    {
        while (TeamA.Num() < MaxTeamSize)
        {
            TeamA.Add(nullptr);
            TeamB.Add(nullptr);
        }

        TeamInitialized = true;
    }

    return TeamInitialized;
}

bool ATeamInitializer::AssertSpawnPoints()
{
    bool SpawnPointsAsserted = false;

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATeamASpawnPoints::StaticClass(), TeamAPlayersSpawnPoints);
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATeamBSpawnPoints::StaticClass(), TeamBPlayersSpawnPoints);
    SpawnPointsAsserted = true;

    return SpawnPointsAsserted;
}

bool ATeamInitializer::SpawnActors()
{
    bool ActorsSpawned = false;

    if (InitializeTeam() && AssertSpawnPoints())
    {
        // Spawn players for both teams
        for (int i = 0; i < MaxTeamSize; i++)
        {
            if (TeamAPlayersSpawnPoints.IsValidIndex(i))
            {
                if (ALP_MPCharacter* SpawnedCharacter = GetWorld()->SpawnActor<ALP_MPCharacter>(TeamAPlayersSpawnPoints[i]->GetActorLocation(), TeamAPlayersSpawnPoints[i]->GetActorRotation()))
                {
                    TeamA[i] = SpawnedCharacter;
                    SpawnedCharacter->SetTeam(0);
                    // Possess player controller with spawned character
                    if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), i))
                    {
                        PC->Possess(SpawnedCharacter);
                        SpawnedCharacter->SetPlayerController(PC);
                    }
                    
                }
            }

            if (TeamBPlayersSpawnPoints.IsValidIndex(i))
            {
                if (ALP_MPCharacter* SpawnedCharacter = GetWorld()->SpawnActor<ALP_MPCharacter>(TeamBPlayersSpawnPoints[i]->GetActorLocation(), TeamBPlayersSpawnPoints[i]->GetActorRotation()))
                {
                    TeamB[i] = SpawnedCharacter;
                    SpawnedCharacter->SetTeam(1);

                    // Possess player controller with spawned character
                    if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), i))
                    {
                        PC->Possess(SpawnedCharacter);
                        SpawnedCharacter->SetPlayerController(PC);
                    }
                }
            }
        }

        ActorsSpawned = true;
    }

    return ActorsSpawned;
}
