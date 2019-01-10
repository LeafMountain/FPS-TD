#include "FGWaypointFollowerComponent.h"
#include "DrawDebugHelpers.h"
#include "FGWaypoint.h"
#include "FGAutoMoveComponent.h"
#include "Components/FGEnemyStats.h"


UFGWaypointFollowerComponent::UFGWaypointFollowerComponent()
{
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UFGWaypointFollowerComponent::BeginPlay() {
	Super::BeginPlay();

	if (TargetWaypoint)
	{
		SetDestination(TargetWaypoint);

		// Set the full length of the route
		StartToFinalDestinationDistance = GetRemainingDistance();
	}


	// Start a timer to check if destination has been reached
	StartDestinationCheck();
}

void UFGWaypointFollowerComponent::StartDestinationCheck() {
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UFGWaypointFollowerComponent::CheckIfDestinationReached, UpdateIntervalInSeconds, false);
}

void UFGWaypointFollowerComponent::StopDestinationCheck() {
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void UFGWaypointFollowerComponent::DrawLineToDestination(float lifetime) {
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), WaypointPosition, FColor(0, 255, 255), false, lifetime);
}

void UFGWaypointFollowerComponent::SetDestination(AFGWaypoint* Waypoint) {
	TargetWaypoint = Waypoint;

	if (TargetWaypoint)
	{
		// If the distance isn't set, set it now
		if (StartToFinalDestinationDistance <= 0)
			StartToFinalDestinationDistance = GetRemainingDistance();

		WaypointPosition = TargetWaypoint->GetActorLocation();
		OnNewDestination.Broadcast(WaypointPosition);
	}
}

bool UFGWaypointFollowerComponent::DestinationReached() 
{
	return DistanceToDestination() < ReachRadius;
}

float UFGWaypointFollowerComponent::DistanceToDestination()
{
	return FVector::Distance(GetOwner()->GetActorLocation(), WaypointPosition);
}

void UFGWaypointFollowerComponent::CheckIfDestinationReached() 
{
	StopDestinationCheck();

	//UFGEnemyStats* EnemyStats = (UFGEnemyStats*)TargetWaypoint->GetComponentByClass(UFGEnemyStats::StaticClass());
	//UE_LOG(LogTemp, Warning, TEXT("%f time left"), EnemyStats->GetTimeRemaining());

	// Check if destination has been reached
	if (DestinationReached()) {

		// Check if there's another waypoint
		if (TargetWaypoint->NextWaypoint)
			SetDestination(TargetWaypoint->NextWaypoint);
		// Else the final checkpoint has been reached
		else
			OnDestinationReached.Broadcast();
	}

	StartDestinationCheck();
}

float UFGWaypointFollowerComponent::GetRemainingDistance()
{
	float LengthToDestination = 0;
	AFGWaypoint* Waypoint = TargetWaypoint;

	while (Waypoint)
	{
		LengthToDestination += Waypoint->DistanceToNextWaypoint();
		Waypoint = Waypoint->NextWaypoint;
	}

	return LengthToDestination;
}

float UFGWaypointFollowerComponent::GetProgress()
{
	return 1 - GetRemainingDistance() / StartToFinalDestinationDistance;
}
