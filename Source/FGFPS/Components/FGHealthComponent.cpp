#include "FGHealthComponent.h"

void UFGHealthComponent::AdjustHealth(int Value) {
	CurrentHealth = FMath::Clamp(CurrentHealth + Value, 0, MaxHealth);
}

