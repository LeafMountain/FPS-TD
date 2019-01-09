#pragma once

#include "FGSpawner.h"
#include "FGEnemySpawner.generated.h"

UCLASS()
class FGFPS_API AFGEnemySpawner : public AFGSpawner {
	GENERATED_BODY()

protected:
	virtual void PostSpawn(class AActor* OtherActor) override;

public:

	UPROPERTY(EditAnywhere)
	class AFGWaypoint* FirstWaypoint;
};