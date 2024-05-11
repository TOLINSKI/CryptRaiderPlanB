// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();

	// ...
	
}

// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/* Gettin Actor owner information etc :
	======================================
	AActor* Owner = GetOwner();

	FVector location = Owner -> GetActorLocation();

	FString location_str = location.ToCompactString();

	UE_LOG(LogTemp, Display, TEXT("My address is: %s"), *location_str);
	*/
	/* 	// My Nonsense: (That works hehe)
		//=================================
	if (ShouldMove)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = (OriginalLocation + MoveOffSet);
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		GetOwner() -> SetActorLocation(NewLocation);
	}
	else 
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = OriginalLocation + MoveOffSet;
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;
		if (FVector::Distance(OriginalLocation, CurrentLocation) > 0.01 )
		{
			TargetLocation = OriginalLocation;
			FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
			GetOwner() -> SetActorLocation(NewLocation);
		}
	*/

	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector TargetLocation = OriginalLocation;
	float Speed = MoveOffSet.Length() / MoveTime;
	if (ShouldMove)
	{
		TargetLocation = OriginalLocation + MoveOffSet;
	}
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	GetOwner() -> SetActorLocation(NewLocation);

	// ...
}

// 			My Functions:
// =====================================
void UMover::SetShouldMove(bool NewShouldMove)
{
	ShouldMove = NewShouldMove;
}


