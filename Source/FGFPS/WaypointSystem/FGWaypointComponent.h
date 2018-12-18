#pragma once

#include "Components/ActorComponent.h"
#include "FGWaypointComponent.generated.h"

// Event triggered when waypoint has been reached
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFGOnWaypointReached);

UCLASS()
class FGFPS_API UFGWaypointComponent : public UActorComponent {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	UFGWaypointComponent* NextWaypoint;

	// Triggers when this waypoint has been reached by a waypoint follower
	void WaypointReached();

	// Get the position of the waypoint (aka the owners location)
	UFUNCTION()
	FORCEINLINE FVector GetPosition() { return GetOwner()->GetActorLocation(); }

	FFGOnWaypointReached OnWaypointReached;
};