#include "FGWaypointFollowerComponent.h"

void UFGWaypointFollowerComponent::SetDestination(UFGWaypointComponent* waypoint) {
	destinationWaypoint = waypoint;

	// Send out an event to tell listeners that a new waypoint has been aquired
}
