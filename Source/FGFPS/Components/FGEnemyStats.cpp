#include "FGEnemyStats.h"
#include "FGLuaComponent.h"
#include "WaypointSystem/FGWaypointFollowerComponent.h"

void UFGEnemyStats::BeginPlay()
{
	Super::BeginPlay();

	LuaComponent = (UFGLuaComponent*)GetOwner()->GetComponentByClass(UFGLuaComponent::StaticClass());
}

float UFGEnemyStats::GetSpeed()
{
	return LuaComponent ? LuaComponent->CallFunction_RetValueNumber("GetSpeed", -1.f) : -1;
}

float UFGEnemyStats::GetHealth()
{
	return LuaComponent ? LuaComponent->CallFunction_RetValueNumber("GetHealth", -1.f) : -1;
}

float UFGEnemyStats::GetProgress()
{
	UFGWaypointFollowerComponent* WaypointFollower = (UFGWaypointFollowerComponent*)GetOwner()->GetComponentByClass(UFGWaypointFollowerComponent::StaticClass());

	int Progress = -1;

	if (WaypointFollower)
		Progress = WaypointFollower->GetProgress();

	return Progress;
}

float UFGEnemyStats::GetTimeRemaining()
{
	UFGWaypointFollowerComponent* WaypointFollower = (UFGWaypointFollowerComponent*)GetOwner()->GetComponentByClass(UFGWaypointFollowerComponent::StaticClass());

	if (WaypointFollower)
	{
		float RemainingDistanceInCM = WaypointFollower->GetRemainingDistance();
		float SpeedInCmPerSecond = GetSpeed();
		return RemainingDistanceInCM / SpeedInCmPerSecond;
	}
	
	return -1;
}

//void UFGEnemyStats::SetSpeed(float Value)
//{
//
//}

void UFGEnemyStats::AdjustHealth(int Value)
{
	if(LuaComponent)
		LuaComponent->CallFunction_OneParamNumber("AdjustHealth", GetHealth() + Value);
	else
		UE_LOG(LogTemp, Warning, TEXT("No LuaComponent found."));
}
