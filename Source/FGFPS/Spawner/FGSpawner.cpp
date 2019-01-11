#include "FGSpawner.h"
#include "Engine/World.h"
#include "FGSpawnerProfile.h"
#include "GameModes/FGGameMode.h"

void AFGSpawner::BeginPlay() {
	Super::BeginPlay();

	world = GetWorld();

	// Start spawn timer
	StartSpawnTimer();
}

void AFGSpawner::Spawn() {
	// Spawn actor
	if (spawnProfiles.Num() > 0) {
		TArray<TSubclassOf<AActor>> viableActors = GetListOfViableActors();

		if (viableActors.Num() > 0) {
			float randomIndex = FMath::RandRange(0, viableActors.Num() - 1);
			TSubclassOf<AActor> actorToSpawn = viableActors[randomIndex];
			FVector spawnPosition = GetActorLocation();
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = GetOwner();

			AActor* NewSpawnedActor = world->SpawnActor<AActor>(actorToSpawn, spawnPosition, FRotator::ZeroRotator, spawnParams);
		
			PostSpawn(NewSpawnedActor);
		}
	}

	// Start timer again
	StartSpawnTimer();
}

void AFGSpawner::PostSpawn(class AActor* SpawnedActor) 
{

}

void AFGSpawner::StartSpawnTimer() 
{
	world->GetTimerManager().SetTimer(timerHandle, this, &AFGSpawner::Spawn, timeBetweenSpawn, false);
}

TArray<TSubclassOf<AActor>> AFGSpawner::GetListOfViableActors() 
{
	TArray<TSubclassOf<AActor>> ViableActors;

	float TimeLeft = 0.f;		// Percentage

	AFGGameMode* GameMode = (AFGGameMode*)GetWorld()->GetAuthGameMode();

	if (GameMode)
	{
		TimeLeft = GameMode->GetTimeLeftPercentage();
		UE_LOG(LogTemp, Warning, TEXT("Time Left: %f"), TimeLeft);
	}

	// Loop through all the profiles
	for (int i = 0; i < spawnProfiles.Num(); i++) {
		// Check if the profile is setup right and if it's time to spawn the spawnable
		if (spawnProfiles[i]->spawnables.Num() > 0 && spawnProfiles[i]->percentageTimeLeft >= TimeLeft) {
			for (int j = 0; j < spawnProfiles[i]->spawnables.Num(); j++) {
				ViableActors.Add(spawnProfiles[i]->spawnables[j]);
			}
		}
	}

	return ViableActors;
}
