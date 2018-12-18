#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmmoPack.generated.h"

class USphereComponent;
class AFGCharacter;
class UMaterial;

UCLASS()
class FGFPS_API AAmmoPack : public AActor
{
	GENERATED_BODY()

public:
/*	AAmmoPack(const &FObjectInitializer& ObjectInitializer);*/

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	AAmmoPack();

	UPROPERTY(VisibleAnywhere, BLueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Collision")
	USphereComponent* TriggerCollision;

	UPROPERTY(VisibleAnywhere, Category = "TargetCharacter")
	AFGCharacter* PowerUpOwner;

	UPROPERTY(EditAnywhere, Category = "Reload")
	int Reloading;

	UPROPERTY()
	bool HasBeenPickedUp = false;

	UFUNCTION()
	void OnReloadPickUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	class UFGLuaContext* GetLuaContext() const;

protected:



	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = Lua)
	class UFGLuaComponent* LuaComponent = nullptr;
};