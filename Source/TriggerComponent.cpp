// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

// 			Constructor:
// =================================
// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* ActorUnlockDoor1 = GetUnlockDoorActor(); // Returns nullptr when the unlocking actor is absent
	if (ActorUnlockDoor1)
	{
		UPrimitiveComponent* PrimComp = Cast<UPrimitiveComponent>(ActorUnlockDoor1 -> GetRootComponent());
		if (PrimComp)
		{
			PrimComp -> AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
			PrimComp -> SetSimulatePhysics(false);
		}
		Mover -> SetShouldMove(true);
	}
	else
	{
		Mover -> SetShouldMove(false);
	}
}

// 				My Functions:
// =================================================
AActor* UTriggerComponent::GetUnlockDoorActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	//  for (auto& Actor : Actors) Can also auto enumerate
	for (AActor* Actor : Actors)
	{
		bool HasUnlockTag = Actor -> ActorHasTag(UnlockDoor1Tag);
		bool IsNotGrabbed = !(Actor -> ActorHasTag("Grabbed")); 
		if (HasUnlockTag && IsNotGrabbed)
		{
			return Actor;
		}
	}
	return nullptr;
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
	Mover = NewMover;
}