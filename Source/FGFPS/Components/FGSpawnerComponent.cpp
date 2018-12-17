#include "FGSpawnerComponent.h"
#include "Engine/World.h"
#include "Spawner/FGSpawnerProfile.h"

void UFGSpawnerComponent::BeginPlay() {
	Super::BeginPlay();
	
	world = GetWorld();

	// Start spawn timer
	StartSpawnTimer();
}

void UFGSpawnerComponent::Spawn() {
	// Temp

	// Spawn actor
	if (spawnProfiles.Num() > 0) {
		TArray<TSubclassOf<AActor>> viableActors = GetListOfViableActors();

		if (viableActors.Num() > 0) {
			float randomIndex = FMath::RandRange(0, viableActors.Num() - 1);
			TSubclassOf<AActor> actorToSpawn = viableActors[randomIndex];
			FVector spawnPosition = GetOwner()->GetActorLocation();
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = GetOwner();

			world->SpawnActor<AActor>(actorToSpawn, spawnPosition, FRotator::ZeroRotator, spawnParams);
			UE_LOG(LogTemp, Warning, TEXT("SPAWN!!"));
		}
	}

	// Start timer again
	StartSpawnTimer();
}

void UFGSpawnerComponent::StartSpawnTimer() {
	world->GetTimerManager().SetTimer(timerHandle, this, &UFGSpawnerComponent::Spawn, timeBetweenSpawn, false);
}

TArray<TSubclassOf<AActor>> UFGSpawnerComponent::GetListOfViableActors() {
	TArray<TSubclassOf<AActor>> ViableActors;
	float timeLeft = 0.5f;		// Percentage

	// Loop through all the profiles
	for (int i = 0; i < spawnProfiles.Num(); i++) {
		// Check if the profile is setup right and if it's time to spawn the spawnable
		if (spawnProfiles[i]->spawnables.Num() > 0 && spawnProfiles[i]->percentageTimeLeft >= timeLeft) {
			for (int j = 0; j < spawnProfiles[i]->spawnables.Num(); j++) {
				ViableActors.Add(spawnProfiles[i]->spawnables[j]);
			}
		}
	}

	return ViableActors;
}

