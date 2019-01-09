#include "FGAutoMoveComponent.h"

UFGAutoMoveComponent::UFGAutoMoveComponent()
{
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UFGAutoMoveComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Move towards destination if destination isn't reached
	if (!DestinationReached())
	{
		// Move towards the destination
		AActor* Owner = GetOwner();
		FVector CurrentLocation = Owner->GetActorLocation();
		FVector TargetDestination = Destination;
		TargetDestination.Z = CurrentLocation.Z;
		FVector directionToDestination = TargetDestination - CurrentLocation;
		directionToDestination.Normalize();

		Owner->SetActorLocation(CurrentLocation + directionToDestination * DeltaTime * MoveSpeed);
		Owner->SetActorRotation(directionToDestination.Rotation());		// could do with some lerping
	}
}

void UFGAutoMoveComponent::SetDestination(FVector NewDestination)
{
	// Assign new destination
	Destination = NewDestination;
}

bool UFGAutoMoveComponent::DestinationReached()
{
	return DistanceToGoal() < DestinationPrecision;
}

float UFGAutoMoveComponent::DistanceToGoal()
{
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	return (CurrentLocation - Destination).Size();
}

