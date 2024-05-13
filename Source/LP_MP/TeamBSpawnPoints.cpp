// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamBSpawnPoints.h"

// Sets default values
ATeamBSpawnPoints::ATeamBSpawnPoints()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATeamBSpawnPoints::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeamBSpawnPoints::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

