// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

#define PortalTrace ECC_GameTraceChannel1

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
	UMaterialInstanceDynamic* portalMatter;

	UPROPERTY(BlueprintReadWrite, Category = "PortalData")
	UTextureRenderTarget2D* rendTarg;

	TArray<AActor*> inPortal;

	TArray<AActor*> inNearby;

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

	FVector getPortalLocation(FVector basePos);

	FRotator getPortalRotation(FRotator baseRot);

	void updateCapture();

	void checkScreen();

	void setupClipPlanes();

	void shouldTeleport();

	UFUNCTION(BlueprintCallable)
	FVector2D getViewport();

	FVector shiftCamAxis(FVector axis);

	int truncatedQuality(float value);

	FVector relativePortalForward();

	void getOverlappingActorsWithPortalObj(UShapeComponent* basis, TArray<AActor*> &actorsToGive);

	UFUNCTION(BlueprintCallable)
	bool isPointCrossing(FVector point);

	bool isPointCrossing(FVector point, UPortalObjectComponent* comp);

	void teleportActor(AActor* bod);


	//Blueprint called functions
	
	UFUNCTION(BlueprintCallable)
	void setPortalMaterial(UMaterial* baseMatter);

	UFUNCTION(BlueprintCallable)
	void initializeMaterials();

	UFUNCTION(BlueprintImplementableEvent)
	void testPortal();
};
