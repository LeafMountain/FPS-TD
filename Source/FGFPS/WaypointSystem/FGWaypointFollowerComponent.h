#pragma once

#include "Components/ActorComponent.h"
#include "FGWaypointFollowerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFGOnNewDestination, FVector, destination);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFGOnDestinationReached);

UCLASS()
class FGFPS_API UFGWaypointFollowerComponent : public UActorComponent {
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere)
	class UFGWaypointComponent* destinationWaypoint;

	FVector destination;

	FTimerHandle timerHandle;

	float timeAccuracy = 1.f;

	// The distance this actor is allowed to be from the destination to count as destination reached
	float reachRadius = 10.f;

	void StartDestinationCheck();
	void StopDestinationCheck();

public:
	UFUNCTION()
	void SetDestination(class UFGWaypointComponent* waypoint);

	// Event triggered when a new destination has been set
	FFGOnNewDestination OnNewDestination;

	// Event triggered when the final destination has been reached (aka when this is a nullptr)
	FFGOnDestinationReached OnDestinationReached;

	bool DestinationReached();

	void CheckIfDestinationReached();

};