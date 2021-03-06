#pragma once

#include "Components/ActorComponent.h"
#include "FGAutoMoveComponent.generated.h"

// Move the actor towards the goal

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API UFGAutoMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFGAutoMoveComponent();

protected:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);

	float MoveSpeed = 10;

private:
	FVector Destination;

public:
	//Destination precision
	UPROPERTY(EditAnywhere)
	float DestinationPrecision = 10;

	UFUNCTION(BlueprintCallable)
	void SetSpeed(float Value);

	// Set the destination of the actor
	UFUNCTION(BlueprintCallable)
	void SetDestination(FVector NewGoal);

	// Check status on destination reached
	UFUNCTION()
	bool DestinationReached();

	// Returns the remaining distance to target
	UFUNCTION()
	float DistanceToGoal();
};