#pragma once

#include "Components/ActorComponent.h"
#include "FGWaypointFollowerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFGOnNewDestination, FVector, destination);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFGOnDestinationReached);

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API UFGWaypointFollowerComponent : public UActorComponent 
{
	GENERATED_BODY()

public:
	UFGWaypointFollowerComponent();

protected:
	//UFGWaypointFollowerComponent();
	virtual void BeginPlay() override;
	//virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	class AFGWaypoint* TargetWaypoint;

	FVector WaypointPosition;

	FTimerHandle TimerHandle;

	float UpdateIntervalInSeconds = 0.2f;

	// The distance this actor is allowed to be from the destination to count as destination reached
	UPROPERTY(EditAnywhere)
	float ReachRadius = 100.f;

	void StartDestinationCheck();
	void StopDestinationCheck();

	void DrawLineToDestination(float Lifetime);

public:
	UFUNCTION()
	void SetDestination(class AFGWaypoint* Waypoint);

	// Event triggered when a new destination has been set
	UPROPERTY(BlueprintAssignable, Category = "FG")
	FFGOnNewDestination OnNewDestination;

	// Event triggered when the final destination has been reached (aka when this is a nullptr)
	UPROPERTY(BlueprintAssignable, Category = "FG")
	FFGOnDestinationReached OnDestinationReached;

	bool DestinationReached();

	// Get the distance to the next waypoint
	float DistanceToDestination();
	void CheckIfDestinationReached();

	//UPROPERTY(EditAnywhere)
	//float moveSpeed = 200.f;

	// Get rematining distance in CM
	float GetRemainingDistance();

	// Get the route progress
	float GetProgress();

	// Store the full length of the waypoint route
	float StartToFinalDestinationDistance;

};