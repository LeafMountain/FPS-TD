#pragme once

#include "FGWaypointFollowerComponent.generated.h"

UCLASS()
class FGFPS_API UFGWaypointFollowerComponent : public UActorComponent {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UFGWaypointComponent* destinationWaypoint;

public:
	UFUNCTION()
	void SetDestination(UFGWaypointComponent* waypoint);

};