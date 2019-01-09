#pragma once

#include "GameFramework/GameMode.h"
#include "FGGameMode.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API AFGGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	// The current amount of lives
	int LifeCurrent;

protected:	
	void BeginPlay() override;

public:
	// The max amount of lives (the amount to start with)
	UPROPERTY(EditAnywhere)
	int LifeMax = 1;

	// Reduce LifeCurrent by 1
	UFUNCTION(BlueprintCallable)
	void ReduceLife();

	// Add 1 to LifeCurrent
	UFUNCTION(BlueprintCallable)
	void AddLife();

	// Set the LifeCurrent to Value
	UFUNCTION(BlueprintCallable)
	void SetLife(int Value);

	// Get the current amount of lives
	UFUNCTION(BlueprintPure)
	int GetCurrentLife();
};