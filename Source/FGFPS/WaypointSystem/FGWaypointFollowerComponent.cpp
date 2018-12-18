#include "FGWaypointFollowerComponent.h"
#include "DrawDebugHelpers.h"
#include "FGWaypoint.h"

UFGWaypointFollowerComponent::UFGWaypointFollowerComponent() {
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UFGWaypointFollowerComponent::BeginPlay() {
	Super::BeginPlay();

	if (destinationWaypoint)
		SetDestination(destinationWaypoint);

	// Start a timer to check if destination has been reached
	StartDestinationCheck();
}

void UFGWaypointFollowerComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DrawLineToDestination(DeltaTime);

	AActor* owner = GetOwner();
	FVector currentPosition = owner->GetActorLocation();
	FVector targetDestination = destination;
	targetDestination.Z = currentPosition.Z;
	FVector directionToDestination = targetDestination - currentPosition;
	directionToDestination.Normalize();

	owner->SetActorLocation(currentPosition + directionToDestination * DeltaTime * moveSpeed);
	owner->SetActorRotation(directionToDestination.Rotation());
}

void UFGWaypointFollowerComponent::StartDestinationCheck() {
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UFGWaypointFollowerComponent::CheckIfDestinationReached, timeAccuracy, false);
}

void UFGWaypointFollowerComponent::StopDestinationCheck() {
	GetWorld()->GetTimerManager().ClearTimer(timerHandle);
}

void UFGWaypointFollowerComponent::DrawLineToDestination(float lifetime) {
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), destination, FColor(0, 255, 255), false, lifetime);
}

void UFGWaypointFollowerComponent::SetDestination(AFGWaypoint* waypoint) {
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
		SetDestination(destinationWaypoint->NextWaypoint);
	}
	else {
		StartDestinationCheck();
	}
}
