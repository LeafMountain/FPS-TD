#pragma once

#include "Components/ActorComponent.h"
#include "FGWaypointFollowerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFGOnNewDestination, FVector, destination);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFGOnDestinationReached);

UCLASS(meta = (BlueprintSpawnableComponent))
class FGFPS_API UFGWaypointFollowerComponent : public UActorComponent {
	GENERATED_BODY()

protected:
	UFGWaypointFollowerComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	class AFGWaypoint* destinationWaypoint;

	FVector destination;

	FTimerHandle timerHandle;

	float timeAccuracy = 1.f;

	// The distance this actor is allowed to be from the destination to count as destination reached
	UPROPERTY(EditAnywhere)
	float reachRadius = 100.f;

	void StartDestinationCheck();
	void StopDestinationCheck();

	void DrawLineToDestination(float lifetime);

public:
	UFUNCTION()
	void SetDestination(class AFGWaypoint* waypoint);

	// Event triggered when a new destination has been set
	UPROPERTY(BlueprintAssignable, Category = "FG")
	FFGOnNewDestination OnNewDestination;

	// Event triggered when the final destination has been reached (aka when this is a nullptr)
	UPROPERTY(BlueprintAssignable, Category = "FG")
	FFGOnDestinationReached OnDestinationReached;

	bool DestinationReached();

	void CheckIfDestinationReached();

	UPROPERTY(EditAnywhere)
	float moveSpeed = 200.f;

};