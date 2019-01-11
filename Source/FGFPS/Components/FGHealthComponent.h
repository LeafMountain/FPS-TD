#pragma once

#include "Components/ActorComponent.h"
#include "FGHealthComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API UFGHealthComponent : public UActorComponent {
	GENERATED_BODY()

protected:
	void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	int MaxHealth = 1;

	UPROPERTY(EditAnywhere)
	int CurrentHealth = 1;

	UFUNCTION(BlueprintCallable)
	void AdjustHealth(int Value);

	UFUNCTION(BlueprintCallable)
		void TakeDamage(int Value);

	FORCEINLINE	float GetHealthPercentage() { return CurrentHealth / MaxHealth;  }
};