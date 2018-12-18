#pragma once

#include "Components/ActorComponent.h"
#include "FGSpawnerComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API UFGSpawnerComponent : public UActorComponent {
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	// Handle to keep track of timer
	FTimerHandle timerHandle;
	
	// Pointer to world
	UWorld* world;
public:
	// Spawn an actor
	void Spawn();

	// The time between the spawns
	UPROPERTY(EditAnywhere)
	float timeBetweenSpawn = 1.f;

	// Start a timer to trigger the spawn function
	void StartSpawnTimer();

	// An array of spawn profiles
	UPROPERTY(EditAnywhere)
	TArray<class UFGSpawnerProfile*> spawnProfiles;

private:
	TArray<TSubclassOf<AActor>> GetListOfViableActors();
};