#include "FGWaypoint.h"
#include "DrawDebugHelpers.h"

AFGWaypoint::AFGWaypoint() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

bool AFGWaypoint::ShouldTickIfViewportsOnly() const {
	return true;
}

void AFGWaypoint::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	if (NextWaypoint)
		DrawDebugLine(GetWorld(), GetPosition(), NextWaypoint->GetPosition(), FColor(0, 0, 255), false, deltaTime * 2, 0, 1.f);
}

void AFGWaypoint::WaypointReached() {
	OnWaypointReached();
}
