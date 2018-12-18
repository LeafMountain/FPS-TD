#pragma once

#include "GameFramework/Actor.h"
#include "FGWaypoint.generated.h"

UCLASS()
class FGFPS_API AFGWaypoint : public AActor {
	GENERATED_BODY()

protected:
	AFGWaypoint();
	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void Tick(float deltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	AFGWaypoint* NextWaypoint;

	// Triggers when this waypoint has been reached by a waypoint follower
	void WaypointReached();

	// Get the position of the waypoint (aka the owners location)
	FORCEINLINE FVector GetPosition() { return GetActorLocation(); }

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaypointReached();

};