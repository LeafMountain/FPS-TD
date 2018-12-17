#pragma once

#include "ActorComponent.h"
#include "FGWaypointComponent.generated.h"

// Event triggered when waypoint has been reached

UCLASS()
class FGFPS_API UFGWaypointComponent : public UActorComponent {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	UFGWaypointComponent* NextWaypoint;

	void OnWaypointReached(AActor* OtherActor);
};