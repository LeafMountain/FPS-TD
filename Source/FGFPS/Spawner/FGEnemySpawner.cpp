#include "FGEnemySpawner.h"
#include "Engine/World.h"
#include "Spawner/FGSpawnerProfile.h"
#include "WaypointSystem/FGWaypointFollowerComponent.h"
#include "GameFramework/Actor.h"

void AFGEnemySpawner::PostSpawn(AActor* OtherActor) {
	if (FirstWaypoint) {
		UFGWaypointFollowerComponent* WaypointFollower = (UFGWaypointFollowerComponent*)OtherActor->GetComponentByClass(UFGWaypointFollowerComponent::StaticClass());

		if(WaypointFollower)
			WaypointFollower->SetDestination(FirstWaypoint);
	}
}
