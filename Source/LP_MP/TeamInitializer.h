// TeamInitializer.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LP_MPCharacter.h"
#include "TeamInitializer.generated.h"

UCLASS()
class LP_MP_API ATeamInitializer : public AGameModeBase
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "GM_Init")
    bool InitializeTeam();

    UFUNCTION(BlueprintCallable, Category = "GM_Init")
    bool AssertSpawnPoints();

    UFUNCTION(BlueprintCallable, Category = "GM_Init")
    bool SpawnActors();

    virtual void Tick(float DeltaTime) override;

    UPROPERTY(BlueprintReadOnly, Category = "GM_Init")
    TArray<ALP_MPCharacter*> TeamA;

    UPROPERTY(BlueprintReadOnly, Category = "GM_Init")
    TArray<ALP_MPCharacter*> TeamB;

    UPROPERTY(BlueprintReadWrite, Category = "GM_Init")
    int MaxTeamSize;

    UPROPERTY(BlueprintReadOnly, Category = "GM_Init")
    TArray<AActor*> TeamAPlayersSpawnPoints;

    UPROPERTY(BlueprintReadOnly, Category = "GM_Init")
    TArray<AActor*> TeamBPlayersSpawnPoints;
};
