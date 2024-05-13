#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "PlayerData.generated.h"

USTRUCT()
struct FPlayerData
{
	GENERATED_BODY()

	UPROPERTY()
	AController* controller;

	UPROPERTY()
	int team;
};