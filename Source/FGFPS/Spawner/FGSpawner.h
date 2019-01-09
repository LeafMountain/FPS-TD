#pragma once

#include "GameFramework/Actor.h"
#include "FGSpawner.generated.h"

UCLASS()
class FGFPS_API AFGSpawner : public AActor {
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	// Handle to keep track of timer
	FTimerHandle timerHandle;

	// Pointer to world
	UWorld* world;

	virtual void PostSpawn(class AActor* SpawnedActor);

public:
	// Spawn an actor
	void Spawn();

	// The time between the spawns
	UPROPERTY(EditAnywhere)
	float timeBetweenSpawn = 2.f;

	// Start a timer to trigger the spawn function
	void StartSpawnTimer();

	// An array of spawn profiles
	UPROPERTY(EditAnywhere)
		TArray<class UFGSpawnerProfile*> spawnProfiles;

private:
	TArray<TSubclassOf<AActor>> GetListOfViableActors();
};