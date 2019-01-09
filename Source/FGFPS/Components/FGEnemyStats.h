#pragma once

#include "FGEnemyStats.generated.h"

UCLASS()
class FGFPS_API UFGEnemyStats : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
		float GetSpeed();

	UFUNCTION()
		float GetHealth();

	UFUNCTION()
		FVector GetPosition();
};