#include "FGGameMode.h"

void AFGGameMode::BeginPlay()
{
	// Set LifeCurrent to LifeMax to start with full health
	LifeCurrent = LifeMax;
}

void AFGGameMode::ReduceLife()
{
	SetLife(GetCurrentLife() - 1);
	UE_LOG(LogTemp, Warning, TEXT("Current health set to %i"), GetCurrentLife());
}

void AFGGameMode::AddLife()
{
	SetLife(GetCurrentLife() + 1);
}

void AFGGameMode::SetLife(int Value)
{
	LifeCurrent = FMath::Clamp(Value, 0, LifeMax);
}

int AFGGameMode::GetCurrentLife()
{
	return LifeCurrent;
}
