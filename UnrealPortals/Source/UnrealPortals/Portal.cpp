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

	// links teleport box to a new function regarding begin overlap
	teleportBox->OnComponentBeginOverlap.AddDynamic(this, &APortal::portalBeginOverlap);
	teleportBox->OnComponentEndOverlap.AddDynamic(this, &APortal::portalEndOverlap);

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

	shiftedLocation = FVector(shiftDegree, defaultRelativePortalLocation.Y, defaultRelativePortalLocation.Z);

	// set portal material and initialize materials
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	cameraAntiClip();

	updateCapture();

	//checkScreen();

	//shouldTeleport();

	testPortal();
}

FVector APortal::updatedCaptureLocation()
{
	// look at https://youtu.be/goD3UZn7Yrg?si=Zq-42_oSeIGRTsAm&t=549

	// Gets the transform of the actor but inverts its x and y scale
	FVector invSelf = AActor::GetActorTransform().GetScale3D();
	invSelf.X *= -1.0;
	invSelf.Y *= -1.0;
	FTransform form(AActor::GetActorTransform().Rotator(), AActor::GetActorTransform().GetLocation(), invSelf);

	//implement in the blueprint
	//look at https://youtu.be/goD3UZn7Yrg?si=aL5l7bF35ziHf7W9&t=590


	// Returns the position of the camera, relative to the semi inverted scale of of the player camera
	FVector posOfCam = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentLocation();

	//FVector posOfCam = camManager.GetComponentLocation();

	FVector invert = UKismetMathLibrary::InverseTransformLocation(form, posOfCam);

	return UKismetMathLibrary::TransformLocation(otherPortal->GetActorTransform(), invert);
}

FVector APortal::updatedCaptureLocation(USceneComponent camManager)
{
	// look at https://youtu.be/goD3UZn7Yrg?si=Zq-42_oSeIGRTsAm&t=549

	// Gets the transform of the actor but inverts its x and y scale
	FVector invSelf = AActor::GetActorTransform().GetScale3D();
	invSelf.X *= -1.0;
	invSelf.Y *= -1.0;
	FTransform form(AActor::GetActorTransform().Rotator(), AActor::GetActorTransform().GetLocation(), invSelf);

	//implement in the blueprint
	//look at https://youtu.be/goD3UZn7Yrg?si=aL5l7bF35ziHf7W9&t=590
	//FVector posOfCam = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentLocation();

	// Returns the position of the camera, relative to the semi inverted scale of of the player camera
	FVector posOfCam = camManager.GetComponentLocation();

	FVector invert = UKismetMathLibrary::InverseTransformLocation(form, posOfCam);

	return UKismetMathLibrary::TransformLocation(otherPortal->GetActorTransform(), invert);
}

FRotator APortal::updatedCaptureRotation()
{
	// Gets the camera and produces its transforms, and produces 3 vectors to invert its position relative to the portal
	FRotator baseRotation = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentRotation();
	FVector shiftedX, shiftedY, shiftedZ;

	// Places the camera axes into the shifted axes, shifts them relative to the camera, then returns a new camera rotation based on the rotation formed on the axes
	UKismetMathLibrary::BreakRotIntoAxes(baseRotation, shiftedX, shiftedY, shiftedZ);
	shiftedX = shiftCamAxis(shiftedX);
	shiftedY = shiftCamAxis(shiftedY);
	shiftedZ = shiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;
}

FRotator APortal::updatedCaptureRotation(USceneComponent camManager)
{
	// Gets the camera and produces its transforms, and produces 3 vectors to invert its position relative to the portal
	FRotator baseRotation = camManager.GetComponentRotation();
	FVector shiftedX, shiftedY, shiftedZ;

	// Places the camera axes into the shifted axes, shifts them relative to the camera, then returns a new camera rotation based on the rotation formed on the axes
	UKismetMathLibrary::BreakRotIntoAxes(baseRotation, shiftedX, shiftedY, shiftedZ);
	shiftedX = shiftCamAxis(shiftedX);
	shiftedY = shiftCamAxis(shiftedY);
	shiftedZ = shiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;
}

FVector APortal::updatedLocation(FVector basePosition)
{
	// Fix

	// look at https://youtu.be/goD3UZn7Yrg?si=Zq-42_oSeIGRTsAm&t=549

	// Gets the transform of the actor but inverts its x and y scale
	FVector invSelf = AActor::GetActorTransform().GetScale3D();
	invSelf.X *= -1.0;
	invSelf.Y *= -1.0;

	// Returns the position of the camera, relative to the semi inverted scale of of the player camera
	FTransform form(AActor::GetActorTransform().Rotator(), AActor::GetActorTransform().GetLocation(), invSelf);

	FVector invert = UKismetMathLibrary::InverseTransformLocation(form, basePosition);

	return UKismetMathLibrary::TransformLocation(otherPortal->GetActorTransform(), invert);

	//return basePosition;
}

FRotator APortal::updatedRotation(FRotator baseRotation)
{
	// fix

	// Gets the camera's rotator and produces its transforms, and produces 3 vectors to invert its position relative to the portal
	FVector shiftedX, shiftedY, shiftedZ;
	UKismetMathLibrary::BreakRotIntoAxes(baseRotation, shiftedX, shiftedY, shiftedZ);

	// Places the camera axes into the shifted axes, shifts them relative to the camera, then returns a new camera rotation based on the rotation formed on the axes
	shiftedX = shiftCamAxis(shiftedX);
	shiftedY = shiftCamAxis(shiftedY);
	shiftedZ = shiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;

	//return baseRotation;
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
	// Returns the r of the other portal relative to the portal, inverted for portal

	FVector shiftedX, shiftedY, shiftedZ;
	UKismetMathLibrary::BreakRotIntoAxes(baseRot, shiftedX, shiftedY, shiftedZ);
	shiftedX = otherPortal->shiftCamAxis(shiftedX);
	shiftedY = otherPortal->shiftCamAxis(shiftedY);
	shiftedZ = otherPortal->shiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;
}

FVector APortal::getCameraLocation(FVector basePos)
{
	// Gets the transform of the actor but inverts its x and y scale
	FVector invSelf = otherPortal->GetActorTransform().GetScale3D();
	invSelf.X *= -1.0;
	invSelf.Y *= -1.0;

	// Returns the position of the camera, relative to the semi inverted scale of of the player camera
	FTransform form(otherPortal->GetActorTransform().Rotator(), otherPortal->GetActorTransform().GetLocation(), invSelf);

	FVector invert = UKismetMathLibrary::InverseTransformLocation(form, basePos);

	return UKismetMathLibrary::TransformLocation(AActor::GetActorTransform(), invert);
}

FRotator APortal::getCameraRotation(FRotator baseRot)
{
	// Gets the camera's rotator and produces its transforms, and produces 3 vectors to invert its position relative to the portal
	FVector shiftedX, shiftedY, shiftedZ;
	UKismetMathLibrary::BreakRotIntoAxes(baseRot, shiftedX, shiftedY, shiftedZ);

	// Places the camera axes into the shifted axes, shifts them relative to the camera, then returns a new camera rotation based on the rotation formed on the axes
	shiftedX = alterShiftCamAxis(shiftedX);
	shiftedY = alterShiftCamAxis(shiftedY);
	shiftedZ = alterShiftCamAxis(shiftedZ);
	FRotator newRotation = UKismetMathLibrary::MakeRotationFromAxes(shiftedX, shiftedY, shiftedZ);
	return newRotation;
}

void APortal::updateCapture()
{
	// study this https://youtu.be/goD3UZn7Yrg?si=XVBR4bEUtkOmUE-4&t=948

	// use new functions

	FVector posOfCam = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentLocation();
	//FVector tes = updatedLocation(posOfCam);

	FRotator rotOfCam = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetTransformComponent()->GetComponentRotation();
	//FRotator tas = updatedRotation(rotOfCam);
	if (otherPortal)
	{
		//otherPortal->portalCam->SetWorldLocationAndRotation(updatedCaptureLocation(), updatedCaptureRotation(), false);
		otherPortal->portalCam->SetWorldLocationAndRotation(updatedLocation(posOfCam), updatedRotation(rotOfCam), false);
	}
}

void APortal::checkScreen()
{
	if (rendTarg)
	{
		if (!(rendTarg->SizeX == truncatedQuality(getViewport().X) && rendTarg->SizeY == truncatedQuality(getViewport().Y)))
		{
			UKismetRenderingLibrary::ResizeRenderTarget2D(rendTarg, truncatedQuality(getViewport().X), truncatedQuality(getViewport().Y));
		}
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

FVector APortal::alterShiftCamAxis(FVector axis)
{
	FVector shiftedAxis = axis;
	shiftedAxis = UKismetMathLibrary::InverseTransformDirection(otherPortal->GetActorTransform(), shiftedAxis);
	shiftedAxis = UKismetMathLibrary::MirrorVectorByNormal(shiftedAxis, FVector::ForwardVector);
	shiftedAxis = UKismetMathLibrary::MirrorVectorByNormal(shiftedAxis, FVector::RightVector);
	shiftedAxis = UKismetMathLibrary::TransformDirection(AActor::GetActorTransform(), shiftedAxis);
	return shiftedAxis;
}

int APortal::truncatedQuality(float value)
{
	// Rounds decimal numbers down
	return UKismetMathLibrary::FTrunc(value * portalQuality);
}

FVector APortal::relativePortalForward()
{
	//Check here https://youtu.be/goD3UZn7Yrg?si=Rt73A2A5NaeVkT_i&t=1088

	//  Returns the relative forward of the portal based on the space that it actally takes up

	return (ForwardArrow->GetForwardVector() * portalClipBaseRange) + portalCollider->GetComponentTransform().GetLocation();
}

void APortal::getOverlappingActorsWithPortalObj(UShapeComponent* basis, TArray<AActor*> &actorsToGive)
{
	// if this doesn't work use blueprint

	// Produces a list of the actors in the portal, and gives them various actions to do
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

	// Sees if a point is in front of a portal, checks if the point is intersecting the portal, and finally returns if the point is crossing
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
	//gets the location and position of the actor in the cuurent portal, and translates it relative the other portal's perspective
	FVector newLocation = updatedLocation(bod->GetActorLocation());
	FRotator newRotation = updatedRotation(bod->GetActorRotation());
	
	// I need to place the teleportation code here, in the event it doesn't arrive, here it is

	bod->SetActorLocationAndRotation(newLocation, newRotation, false);
}


void APortal::teleportActor(ACharacter* bod)
{
	//gets the location and position of the actor in the cuurent portal, and translates it relative the other portal's perspective
	FVector newLocation = updatedLocation(bod->GetActorLocation());
	FRotator newRotation = updatedRotation(bod->GetActorRotation());

	// I need to place the teleportation code here, in the event it doesn't arrive, here it is

	bod->SetActorLocationAndRotation(newLocation, newRotation, false);
}

FVector APortal::translateVelocity(FVector initialVelo)
{
	// Transposes a velocity relative to another portal

	FVector newDir = UKismetMathLibrary::InverseTransformDirection(AActor::GetTransform(), initialVelo);
	FVector xMirror = UKismetMathLibrary::MirrorVectorByNormal(newDir, FVector::ForwardVector);
	FVector yMirror = UKismetMathLibrary::MirrorVectorByNormal(newDir, FVector::RightVector);
	FVector translMirror = UKismetMathLibrary::TransformDirection(otherPortal->GetTransform(), yMirror);

	return translMirror * initialVelo.Length();
}


void APortal::syncPortals(bool syncState)
{
	syncedCam = syncState;
	otherPortal->syncedCam = syncState;
}


void APortal::teleSync()
{
	// changes the relative vision of the camera to the player teleporting so it can focus on the portal

	if (syncedCam)
	{
		syncPortals(false);

		//Meant to set the camera targeting of the player controller to the portal

		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(this);
	}
	else
	{
		syncPortals(true);

		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	}
}

void APortal::nearbySync()
{
	FHitResult returnNat;

	// has the player ignored by the line trace
	FCollisionQueryParams ignoParam;
	ignoParam.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	

	if (syncedCam)
	{
		// Sees if the player and the camera traces through the portal
		bool intersect = GetWorld()->UWorld::LineTraceSingleByChannel(returnNat, UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation(), UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation(), ECC_GameTraceChannel1, ignoParam);

		// checks the trace itself
		if (returnNat.GetComponent() == intersectionCollider)
		{
			syncPortals(false);

			//Meant to set the camera targeting of the player controller to the other portal

			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(otherPortal);
		}
	}
	else
	{
		// Gets a projection of the camera forward
		FVector camProject = (UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetActorForwardVector() * portalCamDist) + UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();

		// Sees if the camera traces through the portal
		bool intersect = GetWorld()->UWorld::LineTraceSingleByChannel(returnNat, UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation(), camProject, ECC_GameTraceChannel1, ignoParam);

		// checks the trace itself
		if (returnNat.GetComponent() != otherPortal->intersectionCollider)
		{
			syncPortals(true);

			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		}
	}
}

void APortal::updateOther()
{
	// This needs to be improved by a more permanent solution

	// 

	FVector pos = Cast<AUnrealPortalsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetFollowCamera()->GetComponentLocation();
	FRotator rot = Cast<AUnrealPortalsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetFollowCamera()->GetComponentRotation();

	playCam->SetWorldLocationAndRotation(getCameraLocation(pos), getCameraRotation(rot));
}

void APortal::moveItems()
{
	// this function is meant to be the the translation of the blueprints into the code

	// currently, this is designed for the player

	//playerNearbyBox->GetOverlappingActors()
}



// Functions for blueprint

void APortal::setPortalMaterial(UMaterial* baseMatter)
{
	portalBasis = baseMatter;
}

void APortal::initializeMaterials()
{
	// sets up the materials of the portal to make sure they capture actors

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

/*
void APortal::teleportActor(AActor* teleported)
{
	UPortalObjectComponent* comp = teleported->GetComponentByClass<UPortalObjectComponent>();

	if (comp)
	{

	}
	else
		isntPortOb();
}
*/

void APortal::cameraAntiClip()
{
	// this function prevents clipping in the camera when things pass

	// sees if the camera is in between certain distances

	float cameraNear = FVector::DotProduct(ForwardArrow->GetForwardVector(), playCam->GetComponentLocation() - this->GetActorLocation());

	//float clipShift = FMath::Clamp(((1.0 - (cameraNear / 50.0)) * shiftDegree), shiftDegree, 0.0);

	shiftedLocation.X = FMath::Clamp(((1.0 - (cameraNear / 50.0)) * shiftDegree), shiftDegree, 0.0);

	if (cameraNear < 200.0 && cameraNear > shiftDegree)
	{
		portalCollider->SetRelativeLocation(shiftedLocation);
	}
	else
	{
		portalCollider->SetRelativeLocation(defaultRelativePortalLocation);
	}
}

void APortal::movePlayer()
{
	// Gets the original velocity of the entering object
	

	// I need to get the player, and teleport them

	teleportActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	// as the player is moved, it means the player's movement needs to be rotated, which this is a demo of

	UPortalObjectComponent* comp = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetComponentByClass<UPortalObjectComponent>();

	bool needsRotation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetComponentByClass<UPortalObjectComponent>()->getIsPlayer();

	if (needsRotation)
	{
		// rotates the player's movement to account for teleportation
		FRotator newRotation = updatedRotation(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetControlRotation());

		// sets player control rotation, 0 is player id
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetControlRotation(newRotation);

		// cuts the camera from players, 0 is player id
		UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->SetGameCameraCutThisFrame();
	}

	FVector originSpd = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetVelocity();

	// sets the velocity of the travelling object to it's original velocity

	comp->setVelocity(translateVelocity(originSpd)); 
}

void APortal::cameraRotation()
{
	FVector rotationForm = Cast<AUnrealPortalsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetFollowCamera()->GetComponentLocation();
	FRotator rotationRot = Cast<AUnrealPortalsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetFollowCamera()->GetComponentRotation();
	
	FVector newPosition = getCameraLocation(rotationForm);
	FRotator newRotation = getCameraRotation(rotationRot);

	playCam->SetWorldLocationAndRotation(newPosition, newRotation);
}

void APortal::runTeleportation()
{
	// cleans out the list of objects in the portal

	nearbyItems.Empty();

	portalItems.Empty();

	// gets a raw sample of all items considered nearby to the portal and in the portal
	playerNearbyBox->GetOverlappingActors(inNearby, TSubclassOf<AActor>());

	teleportBox->GetOverlappingActors(inPortal, TSubclassOf<AActor>());


	// converts the raw sample into the actors that specifically contain the portal object component
	for (int i = 0; i < inNearby.Num(); i++)
	{
		if (IsValid(inNearby[i]->GetComponentByClass<UPortalObjectComponent>()))
			nearbyItems.Add(inNearby[i]);
	}

	for (int i = 0; i < inPortal.Num(); i++)
	{
		if (IsValid(inPortal[i]->GetComponentByClass<UPortalObjectComponent>()))
			portalItems.Add(inPortal[i]);
	}

	// has objects move around 

	if (nearbyItems.Num() >= 1)
	{
		if (portalItems.Num() >= 1)
		{
			// this will check the player's crossing,

			// this specifically moves the player

			// Make some edits so it affects other characters

			if (isPointCrossing(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation()))
			{
				movePlayer();
				teleSync();
			}
			else
			{
				nearbySync();
			}
		}
		else
		{
			nearbySync();
		}
	}

	

	cameraRotation();
}

int APortal::getPee(bool penum)
{
	if (penum)
	{
		return portalItems.Num();
	}
	else
	{
		return nearbyItems.Num();
	}
}

FString APortal::getObj()
{
	return inPortal[0]->GetFName().ToString();
}