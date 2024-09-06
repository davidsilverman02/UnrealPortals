// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalObjectComponent.h"

// Sets default values for this component's properties
UPortalObjectComponent::UPortalObjectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPortalObjectComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPortalObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPortalObjectComponent::Teleport(FTransform fromPortal, FTransform toPortal, FVector3f pos, FRotator rot)
{

}

//void UPortalObjectComponent::OnTeleport(FTransform fromPortal, FTransform toPortal, FVector3f pos, FRotator rot)
//{
//	Teleport(fromPortal, toPortal, pos, rot);
//}

void UPortalObjectComponent::PortalEnterStart()
{

}

//void UPortalObjectComponent::OnPortalEnterStart()
//{
//	PortalEnterStart();
//}

void UPortalObjectComponent::PortalExitStart()
{

}

//void UPortalObjectComponent::OnPortalExitStart()
//{
//	PortalExitStart();
//}