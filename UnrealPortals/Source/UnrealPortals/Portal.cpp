// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "Camera/CameraComponent.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	defaultComp = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	defaultComp->SetupAttachment(RootComponent);

	portalCollider = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Portal"));
	portalCollider->SetupAttachment(defaultComp);

	intersectionCollider = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Intersection"));
	intersectionCollider->SetupAttachment(defaultComp);

	portalCam = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Portal Cam"));
	portalCam->SetupAttachment(defaultComp);

	playCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Cam"));
	playCam->SetupAttachment(defaultComp);

	teleportBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Teleport Collider"));
	teleportBox->SetupAttachment(defaultComp);

	playerNearbyBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Nearby Collider"));
	playerNearbyBox->SetupAttachment(defaultComp);

	ForwardArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Forward"));
	ForwardArrow->SetupAttachment(defaultComp);
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	//Add delay with bp

	Super::BeginPlay();

	// set portal material and initialize materials
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	updateCapture();

	//checkScreen();

	//shouldTeleport();

	testPortal();
}

FVector APortal::updatedCaptureLocation()
{
	// look at https://youtu.be/goD3UZn7Yrg?si=Zq-42_oSeIGRTsAm&t=549
	FVector invSelf = AActor::GetActorTransform().GetScale3D();
	invSelf.X *= -1.0;
	invSelf.Y *= -1.0;
	FTransform form(AActor::GetActorTransform().Rotator(), AActor::GetActorTransform().GetLocation(), invSelf);

	//implement in the blueprint
	//look at https://youtu.be/goD3UZn7Yrg?si=aL5l7bF35ziHf7W9&t=590
	FVector posOfCam = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentLocation();

	//FVector posOfCam = camManager.GetComponentLocation();

	FVector invert = UKismetMathLibrary::InverseTransformLocation(form, posOfCam);

	return UKismetMathLibrary::TransformLocation(otherPortal->GetActorTransform(), invert);
}

FVector APortal::updatedCaptureLocation(USceneComponent camManager)
{
	// look at https://youtu.be/goD3UZn7Yrg?si=Zq-42_oSeIGRTsAm&t=549
	FVector invSelf = AActor::GetActorTransform().GetScale3D();
	invSelf.X *= -1.0;
	invSelf.Y *= -1.0;
	FTransform form(AActor::GetActorTransform().Rotator(), AActor::GetActorTransform().GetLocation(), invSelf);

	//implement in the blueprint
	//look at https://youtu.be/goD3UZn7Yrg?si=aL5l7bF35ziHf7W9&t=590
	//FVector posOfCam = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentLocation();

	FVector posOfCam = camManager.GetComponentLocation();

	FVector invert = UKismetMathLibrary::InverseTransformLocation(form, posOfCam);

	return UKismetMathLibrary::TransformLocation(otherPortal->GetActorTransform(), invert);
}

FRotator APortal::updatedCaptureRotation()
{
	FRotator baseRotation = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentRotation();
	FVector shiftedX, shiftedY, shiftedZ;
	UKismetMathLibrary::BreakRotIntoAxes(baseRotation, shiftedX, shiftedY, shiftedZ);
	shiftedX = shiftCamAxis(shiftedX);
	shiftedY = shiftCamAxis(shiftedY);
	shiftedZ = shiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;
}

FRotator APortal::updatedCaptureRotation(USceneComponent camManager)
{
	FRotator baseRotation = camManager.GetComponentRotation();
	FVector shiftedX, shiftedY, shiftedZ;
	UKismetMathLibrary::BreakRotIntoAxes(baseRotation, shiftedX, shiftedY, shiftedZ);
	shiftedX = shiftCamAxis(shiftedX);
	shiftedY = shiftCamAxis(shiftedY);
	shiftedZ = shiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;
}

FVector APortal::getPortalLocation(FVector basePos)
{
	FVector invSelf = AActor::GetActorTransform().GetScale3D();
	invSelf.X *= -1.0;
	invSelf.Y *= -1.0;
	FTransform form(AActor::GetActorTransform().Rotator(), AActor::GetActorTransform().GetLocation(), invSelf);

	//implement in the blueprint
	//look at https://youtu.be/goD3UZn7Yrg?si=aL5l7bF35ziHf7W9&t=590
	//FVector posOfCam = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentLocation();


	FVector invert = UKismetMathLibrary::InverseTransformLocation(form, basePos);

	return UKismetMathLibrary::TransformLocation(otherPortal->GetActorTransform(), invert);
}

FRotator APortal::getPortalRotation(FRotator baseRot)
{
	FVector shiftedX, shiftedY, shiftedZ;
	UKismetMathLibrary::BreakRotIntoAxes(baseRot, shiftedX, shiftedY, shiftedZ);
	shiftedX = shiftCamAxis(shiftedX);
	shiftedY = shiftCamAxis(shiftedY);
	shiftedZ = shiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;
}

void APortal::updateCapture()
{
	// study this https://youtu.be/goD3UZn7Yrg?si=XVBR4bEUtkOmUE-4&t=948
	if (otherPortal)
	{
		otherPortal->portalCam->SetWorldLocationAndRotation(updatedCaptureLocation(), updatedCaptureRotation(), false);
	}
}

void APortal::checkScreen()
{
	if (!(rendTarg->SizeX == truncatedQuality(getViewport().X) && rendTarg->SizeY == truncatedQuality(getViewport().Y)))
	{
		UKismetRenderingLibrary::ResizeRenderTarget2D(rendTarg, truncatedQuality(getViewport().X), truncatedQuality(getViewport().Y));
	}
}

void APortal::setupClipPlanes()
{
	portalCam->bEnableClipPlane = true;
	portalCam->ClipPlaneBase = relativePortalForward();
	portalCam->ClipPlaneNormal = ForwardArrow->GetForwardVector();
}

void APortal::shouldTeleport()
{
	// Might delete objs

	/*
	int portalNum = inPortal.Num() - 1;
	int nearbyNum = inNearby.Num() - 1;

	bool cross;

	for (int i = portalNum; i >= 0; i--)
	{
		inPortal.Remove(inPortal[i]);
	}

	for (int i = nearbyNum; i >= 0; i--)
	{
		inNearby.Remove(inNearby[i]);
	}

	getOverlappingActorsWithPortalObj(teleportBox, inPortal);
	getOverlappingActorsWithPortalObj(playerNearbyBox, inNearby);

	portalNum = inPortal.Num() - 1;
	nearbyNum = inNearby.Num() - 1;

	for (int i = 0; i < portalNum; i++)
	{
		if (inNearby.Contains(inPortal[i]))
		{
			cross = isPointCrossing(inPortal[i]->GetActorLocation());
		}
	}

	if (cross)
	{

	}
	*/

	/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Some variable values: x: %f, y: %f"), x, y));*/
}

FVector2D APortal::getViewport()
{
	return FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
}

FVector APortal::shiftCamAxis(FVector axis)
{
	// look at https://youtu.be/goD3UZn7Yrg?si=EzB-Y3Klff3I3T9z&t=714

	FVector shiftedAxis = axis;
	shiftedAxis = UKismetMathLibrary::InverseTransformDirection(AActor::GetActorTransform(), shiftedAxis);
	shiftedAxis = UKismetMathLibrary::MirrorVectorByNormal(shiftedAxis, FVector::ForwardVector);
	shiftedAxis = UKismetMathLibrary::MirrorVectorByNormal(shiftedAxis, FVector::RightVector);
	shiftedAxis = UKismetMathLibrary::TransformDirection(otherPortal->GetActorTransform(), shiftedAxis);
	return shiftedAxis;
}

int APortal::truncatedQuality(float value)
{
	return UKismetMathLibrary::FTrunc(value * portalQuality);
}

FVector APortal::relativePortalForward()
{
	//Check here https://youtu.be/goD3UZn7Yrg?si=Rt73A2A5NaeVkT_i&t=1088

	return (ForwardArrow->GetForwardVector() * portalClipBaseRange) + portalCollider->GetComponentTransform().GetLocation();
}

void APortal::getOverlappingActorsWithPortalObj(UShapeComponent* basis, TArray<AActor*> &actorsToGive)
{
	// if this doesn't work use blueprint
	TArray<AActor*> actorsToTake;

	basis->GetOverlappingActors(actorsToTake, AActor::StaticClass());

	int h = actorsToTake.Num();

	for (int i = 0; i < h; i++)
	{
		// Add print to debug to see if works
		UPortalObjectComponent* comp = actorsToGive[i]->FindComponentByClass<UPortalObjectComponent>();
		if (comp)
		{
			actorsToGive.Add(actorsToGive[i]);
		}
	}
}

bool APortal::isPointCrossing(FVector point)
{
	bool pointInFront;
	bool isIntersecting;
	bool isCrossing;

	float garbage;
	FVector garb;

	FVector portalLocation = GetActorLocation();
	FVector portalNormal = ForwardArrow->GetForwardVector();

	float dotProdPoint = FVector::DotProduct(portalNormal, (point - portalLocation));

	pointInFront = dotProdPoint >= 0.0f;

	FPlane portalSpace = UKismetMathLibrary::MakePlaneFromPointAndNormal(portalLocation, portalNormal);

	isIntersecting = UKismetMathLibrary::LinePlaneIntersection(lastPos, point, portalSpace, garbage, garb);

	isCrossing = isIntersecting && !pointInFront && lastInFront;
	lastInFront = pointInFront;
	lastPos = point;

	return isCrossing;
}

bool APortal::isPointCrossing(FVector point, UPortalObjectComponent* comp)
{
	return false;
}

void APortal::teleportActor(AActor* bod)
{
	
}

// Functions for blueprint

void APortal::setPortalMaterial(UMaterial* baseMatter)
{
	portalBasis = baseMatter;
}

void APortal::initializeMaterials()
{
	SetTickGroup(TG_PostUpdateWork);

	portalMatter = UMaterialInstanceDynamic::Create(portalBasis, this);

	portalCollider->SetMaterial(0, portalMatter);

	FVector2d targetSize(getViewport().X * portalQuality, getViewport().Y * portalQuality);

	rendTarg = UKismetRenderingLibrary::CreateRenderTarget2D(this, targetSize.X, targetSize.Y, RTF_RGBA16f);

	// for a one-parameter texture in which a parameter is a param2d, it will be callled BaseTexture
	portalMatter->SetTextureParameterValue(FName("BaseTexture"), rendTarg);


	//look at https://youtu.be/goD3UZn7Yrg?si=kypqNH1QVj8KMwtU&t=435
	otherPortal->portalCam->TextureTarget = rendTarg;

	setupClipPlanes();
}