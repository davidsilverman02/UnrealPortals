// Fill out your copyright notice in the Description page of Project Settings.


#include "MirrorCharacter.h"

// Sets default values
AMirrorCharacter::AMirrorCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMirrorCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMirrorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMirrorCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

