#include "FGEnemyStats.h"

float UFGEnemyStats::GetSpeed()
{
	return 10;
}

float UFGEnemyStats::GetHealth()
{
	return 10;
}

FVector UFGEnemyStats::GetPosition()
{
	return GetOwner()->GetActorLocation();
}
