// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PortalObjectComponent.generated.h"

//struct FTransform;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPORTALS_API UPortalObjectComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties

	AActor* gObject;
	AActor* gGlome;
	
	FVector3d pOffsetOfPortal;

	FVector lastPos;
	bool lastInFront;

	UPortalObjectComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Teleport(FTransform fromPortal, FTransform toPortal, FVector3f pos, FRotator rot);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnTeleport"))
	void OnTeleport(FTransform fromPortal, FTransform toPortal, FVector3f pos, FRotator rot);

	virtual void PortalEnterStart();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnPortalEnterStart"))
	void OnPortalEnterStart();

	virtual void PortalExitStart();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnPortalExitStart"))
	void OnPortalExitStart();
};
