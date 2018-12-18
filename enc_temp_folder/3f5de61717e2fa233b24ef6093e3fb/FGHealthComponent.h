#pragma once

#include "Components/ActorComponent.h"
#include "FGHealthComponent.generated.h"

UCLASS()
class FGFPS_API UFGHealthComponent : public UActorComponent {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	int MaxHealth = 1;

	UPROPERTY(EditAnywhere)
	int CurrentHealth = 1;

	UFUNCTION()
	void AdjustHealth(int Value);

	FORCEINLINE	float GetHealthPercentage() { return CurrentHealth / MaxHealth;  }
};