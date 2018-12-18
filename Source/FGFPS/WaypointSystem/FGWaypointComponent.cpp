#include "FGWaypointComponent.h"
#include "FGWaypointFollowerComponent.h"

void UFGWaypointComponent::WaypointReached() {
	UE_LOG(LogTemp, Warning, TEXT("Waypoint reached"));

	OnWaypointReached.Broadcast();
	//// Try to get the waypoint follower component
	//UFGWaypointFollowerComponent* waypointFollower = (UFGWaypointFollowerComponent*)OtherActor->GetComponentByClass(UFGWaypointFollowerComponent::StaticClass());
	//
	//// Exit if the other actor is not a waypoint follower
	//if (!waypointFollower)
	//	return;

	//// Check if there's another waypoint
	//if (NextWaypoint) {
	//	// Provide the next waypoint
	//	waypointFollower->SetDestination(NextWaypoint);
	//}
	//else {
	//	// Final destination reached
	//	waypointFollower->SetDestination(nullptr);
	//}
}

