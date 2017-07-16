// Fill out your copyright notice in the Description page of Project Settings.

#include "RTSMPlayerController.h"
#include "Engine/World.h"

ARTSMPlayerController::ARTSMPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARTSMPlayerController::BeginPlay()
{
	Super::BeginPlay();

	CamX = GetPawn()->GetActorLocation().X;
	CamY = GetPawn()->GetActorLocation().Y;

	GetViewportSize(ViewPortX, ViewPortY);
}

void ARTSMPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!ViewPortX || !ViewPortY) { return; }

	GetMousePosition(MousePosX, MousePosY);

	if (MousePosX >= (ViewPortX - ViewPortX * .05f))
	{
		CamY += CamSpeed;
		MoveCam();
	} 
	if (MousePosX <= ViewPortX * .05f) 
	{
		CamY -= CamSpeed;
		MoveCam();
	} 
	if (MousePosY >= (ViewPortY - ViewPortY * .05f))
	{
		CamX -= CamSpeed;
		MoveCam();
	}
	if (MousePosY <= ViewPortY * .05f)
	{
		CamX += CamSpeed;
		MoveCam();
	}
}

void ARTSMPlayerController::MoveCam() const
{
	FVector NewLocation(CamX, CamY, GetPawn()->GetActorLocation().Z);
	GetPawn()->SetActorLocation(NewLocation);
}