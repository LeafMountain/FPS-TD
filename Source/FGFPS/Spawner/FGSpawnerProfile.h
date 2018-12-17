#pragma once

#include "Engine/DataAsset.h"
#include "FGSpawnerProfile.generated.h"

UCLASS()
class FGFPS_API UFGSpawnerProfile : public UDataAsset {
	GENERATED_BODY()

public:

	// The actors to pick from when spawning
	UPROPERTY(EditAnywhere)
	TArray <TSubclassOf<AActor>> spawnables;

	// At what percentage this profile will be active
	UPROPERTY(EditAnywhere)
		float percentageTimeLeft;
};