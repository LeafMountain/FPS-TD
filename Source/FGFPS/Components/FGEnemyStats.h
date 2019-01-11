#pragma once

#include "Components/ActorComponent.h"
#include "FGEnemyStats.generated.h"

// This component is inteded to use as an easy way to get values related to the actor
// This is also a hard coupled component which has many dependencies

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API UFGEnemyStats : public UActorComponent
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
	//UFGAutoMoveComponent* AutoMoveComponent;
	class UFGLuaComponent* LuaComponent;

public:
	UFUNCTION(BlueprintPure)
		float GetSpeed();

	UFUNCTION(BlueprintCallable)
		float GetHealth();

	UFUNCTION(BlueprintPure)
		float GetProgress();

	UFUNCTION(BlueprintPure)
		float GetTimeRemaining();

	//UFUNCTION(BlueprintCallable)
	//	void SetSpeed(float Value);

	UFUNCTION(BlueprintCallable)
		void AdjustHealth(int Value);
};