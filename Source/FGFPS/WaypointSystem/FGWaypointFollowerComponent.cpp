#include "FGWaypointFollowerComponent.h"
#include "FGWaypointComponent.h"

void UFGWaypointFollowerComponent::BeginPlay() {
	// Start a timer to check if destination has been reached
	StartDestinationCheck();
}

void UFGWaypointFollowerComponent::StartDestinationCheck() {
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UFGWaypointFollowerComponent::CheckIfDestinationReached, timeAccuracy, false);
}

void UFGWaypointFollowerComponent::StopDestinationCheck() {
	GetWorld()->GetTimerManager().ClearTimer(timerHandle);
}

void UFGWaypointFollowerComponent::SetDestination(UFGWaypointComponent* waypoint) {
	destinationWaypoint = waypoint;

	if (destinationWaypoint) {
		// Tell the waypoint that it has been reached
		waypoint->WaypointReached();

		// Set destination
		destination = destinationWaypoint->GetPosition();

		// Send out an event to tell listeners that a new waypoint has been aquired
		OnNewDestination.Broadcast(destinationWaypoint->GetPosition());

		// Start destination check
		StartDestinationCheck();
	}
	else {
		// The final destination has been reached
		OnDestinationReached.Broadcast();
		// Stop the destination check
		StopDestinationCheck();
	}
}

bool UFGWaypointFollowerComponent::DestinationReached() {
	return FVector::Distance(GetOwner()->GetActorLocation(), destination) < reachRadius;
}

void UFGWaypointFollowerComponent::CheckIfDestinationReached() {
	if (DestinationReached()) {
		SetDestination(destinationWaypoint);
	}
	else {
		StartDestinationCheck();
	}
}
