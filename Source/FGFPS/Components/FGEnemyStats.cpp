#include "FGEnemyStats.h"
#include "WaypointSystem/FGWaypointFollowerComponent.h"

float UFGEnemyStats::GetSpeed()
{
	return 10;
}

float UFGEnemyStats::GetHealth()
{
	return 10;
}

float UFGEnemyStats::GetProgress()
{
	UFGWaypointFollowerComponent* WaypointFollower = (UFGWaypointFollowerComponent*)GetOwner()->GetComponentByClass(UFGWaypointFollowerComponent::StaticClass());

	int Progress = 0;

	if (WaypointFollower)
		Progress = WaypointFollower->GetProgress();

	return Progress;
}
