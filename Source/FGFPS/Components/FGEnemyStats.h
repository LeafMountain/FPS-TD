#pragma once

#include "Components/ActorComponent.h"
#include "FGEnemyStats.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API UFGEnemyStats : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		float GetSpeed();

	UFUNCTION(BlueprintCallable)
		float GetHealth();

	UFUNCTION(BlueprintPure)
		float GetProgress();

};