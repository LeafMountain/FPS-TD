
#include "AmmoPack.h"
#include "Character/FGCharacter.h"
#include "WorldCollision.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
/*#include "Components/FGAmmoComponent.h"*/
#include "Components/FGLuaComponent.h"
#include "Lua/FGLuaContext.h"


AAmmoPack::AAmmoPack()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	TriggerCollision = CreateDefaultSubobject<USphereComponent>("PickUpRange");
	TriggerCollision->SetupAttachment(Mesh);
	TriggerCollision->OnComponentBeginOverlap.AddDynamic(this, &AAmmoPack::OnReloadPickUp);
}

void AAmmoPack::OnReloadPickUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->IsA<AFGCharacter>())
	{
		PowerUpOwner = Cast<AFGCharacter>(OtherActor);

		int MaxAmmo = PowerUpOwner->LuaComponent->GetInteger(TEXT("MaxAmmo"));
		int Ammo = PowerUpOwner->LuaComponent->GetInteger(TEXT("Ammo"));

		if (Ammo < MaxAmmo)
		{
			PowerUpOwner->LuaComponent->CallFunction(TEXT("GetAmmo"));
			AActor::Destroy();
		}
	}
}

void AAmmoPack::BeginPlay()
{
	Super::BeginPlay();


}

void AAmmoPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

