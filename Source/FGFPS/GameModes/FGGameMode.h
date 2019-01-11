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

	// The current time left
	float CurrentTime = 10;

	float TimerTimeScale = 1;

protected:	
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
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

	UFUNCTION(BlueprintCallable)
		void ResetGame();

	FText GetLifeUI();
	FText GetTimeUI();

// Timer functions
	// The start time
	UPROPERTY(EditAnywhere)
	float MaxTimer = 360;

	// Set the current time to MaxTimer
	UFUNCTION(BlueprintCallable)
	void ResetTimer();

	// Get the current time
	UFUNCTION(BlueprintPure)
	float GetTimeLeft();

	// Pause
	UFUNCTION(BlueprintCallable)
	void PauseToggle();

	// Modify Timer
	UFUNCTION(BlueprintCallable)
	void SetTimer(float Seconds);

	// Add value to timer
	UFUNCTION(BlueprintCallable)
	void AdjustTimer(float Seconds);

	UFUNCTION(BlueprintCallable)
	void PauseTimer();

	UFUNCTION(BlueprintCallable)
	void ResumeTimer();

	UFUNCTION(BlueprintCallable)
		void SetTimerTimeScale(float Value);

	UFUNCTION(BlueprintCallable)
	float GetTimeLeftPercentage();
};