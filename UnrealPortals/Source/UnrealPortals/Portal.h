// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "UnrealPortalsCharacter.h"
#include "PortalObjectComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/Classes/Components/SceneCaptureComponent2D.h"
#include "Engine/Classes/Engine/TextureRenderTarget2D.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Portal.generated.h"


class UCameraComponent;
class UMeshComponent;
class UStaticMeshComponent;
class USceneCaptureComponent2D;
class UCameraComponent;
class UTransformComponent;
class UArrowComponent;
class UBoxComponent;


// The first trace channel made in this project was the Portal channel, I believe this will work for channel one thusly
#define Portal ECC_GameTraceChannel1

UCLASS()
class UNREALPORTALS_API APortal : public AActor
{
	//See if boxcomp and boxcoll are different

	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	USceneComponent* defaultComp;

	//Tinker with to see if editable
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* portalCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* intersectionCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	USceneCaptureComponent2D* portalCam;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* playCam;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* teleportBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* playerNearbyBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Portal, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* ForwardArrow;

	

	// Make collision like here https://youtu.be/goD3UZn7Yrg?si=GMTRlEfQad7It0Pw&t=1340

public:	
	// Sets default values for this actor's properties
	APortal();
	
	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	UMaterial* portalBasis;

	// The Portal this specific portal goes to
	UPROPERTY(EditAnywhere, Category = "PortalData")
	APortal* otherPortal;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	UMeshComponent* vision;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	int maxRecursions = 5;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	float portalQuality = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	float nearClipOffset = 0.05f;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	float nearClipLimit = 0.2f;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	float portalClipBaseRange = -3.0f;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	float portalCamDist = 1000.0f;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	UMaterialInstanceDynamic* portalMatter;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	UTextureRenderTarget2D* rendTarg;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	TArray<AActor*> inPortal;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	TArray<AActor*> inNearby;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	TArray<AActor*> portalItems;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	TArray<AActor*> nearbyItems;
	
	// the bool for the function
	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	bool syncedCam;

	// May want to put this in portal object component
	FVector lastPos;
	bool lastInFront;

	//Try to find a late update function

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool IsCameraVisible();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector updatedCaptureLocation();

	FVector updatedCaptureLocation(USceneComponent camManager);

	FRotator updatedCaptureRotation();

	FRotator updatedCaptureRotation(USceneComponent camManager);

	FVector updatedLocation(FVector basePosition);

	FRotator updatedRotation(FRotator baseRotation);

	FVector getPortalLocation(FVector basePos);

	FRotator getPortalRotation(FRotator baseRot);

	FVector getCameraLocation(FVector basePos);

	FRotator getCameraRotation(FRotator baseRot);

	void updateCapture();

	void checkScreen();

	void setupClipPlanes();

	void shouldTeleport();

	UFUNCTION(BlueprintCallable)
	FVector2D getViewport();

	FVector shiftCamAxis(FVector axis);

	FVector alterShiftCamAxis(FVector axis);

	int truncatedQuality(float value);

	FVector relativePortalForward();

	void getOverlappingActorsWithPortalObj(UShapeComponent* basis, TArray<AActor*> &actorsToGive);

	UFUNCTION(BlueprintCallable)
	bool isPointCrossing(FVector point);

	bool isPointCrossing(FVector point, UPortalObjectComponent* comp);

	void teleportActor(AActor* bod);

	void teleportActor(ACharacter* bod);

	FVector translateVelocity(FVector initialVelo);

	UFUNCTION(BlueprintCallable)
	void syncPortals(bool syncState);

	UFUNCTION(BlueprintCallable)
	void teleSync();

	UFUNCTION(BlueprintCallable)
	void nearbySync();

	UFUNCTION(BlueprintCallable)
	void updateOther();

	UFUNCTION(BlueprintCallable)
	void moveItems();

	//Blueprint called functions
	
	UFUNCTION(BlueprintCallable)
	void setPortalMaterial(UMaterial* baseMatter);

	UFUNCTION(BlueprintCallable)
	void initializeMaterials();

	UFUNCTION(BlueprintImplementableEvent)
	void testPortal();

	UFUNCTION(BlueprintImplementableEvent)
	void yelli();

	UFUNCTION(BlueprintImplementableEvent)
	void isntPortOb();

	// This moves the player, will be replaced with a more permanent solution
	UFUNCTION(BlueprintCallable)
	void movePlayer();

	// This updates the position of capture cameras
	UFUNCTION(BlueprintCallable)
	void cameraRotation();

	UFUNCTION(BlueprintCallable)
	void runTeleportation();

	UFUNCTION(BlueprintCallable)
	int getPee(bool penum);

	UFUNCTION(BlueprintCallable)
	FString getObj();

	UFUNCTION(BlueprintImplementableEvent)
	void getPortalItems();

	//UFUNCTION(BlueprintCallable)
	//void teleportActor(AActor* teleported);
};
