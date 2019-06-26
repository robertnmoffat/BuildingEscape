// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework\Actor.h"
#include "Engine\World.h"
#include "GameFramework\PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	//Get the pawn of the player and assign that to the actor that opens, so that the player can trigger the door volume trigger
	actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//Poll trigger volume every frame
	if (pressurePlate->IsOverlappingActor(actorThatOpens)) {
		openTheDoor();
	}

}

void UOpenDoor::openTheDoor() {
	//Find owning actor
	AActor *owner = GetOwner();

	//Create a rotator
	FRotator rotator = FRotator(0.0f, 90.0f, 0.0f);

	//set door rotation
	owner->SetActorRotation(rotator);
}

