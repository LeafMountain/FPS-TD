#include "FGHealthComponent.h"

void UFGHealthComponent::BeginPlay()
{
	// Add method to take damage function built into ue4 on actor
	AActor* Owner = GetOwner();
}

void UFGHealthComponent::AdjustHealth(int Value) {
	CurrentHealth = FMath::Clamp(CurrentHealth + Value, 0, MaxHealth);
}

void UFGHealthComponent::TakeDamage(int Value)
{
	AdjustHealth(-Value);
}

