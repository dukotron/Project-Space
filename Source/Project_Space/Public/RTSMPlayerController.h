// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RTSMPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_SPACE_API ARTSMPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	// Sets default values for this actor's properties
	ARTSMPlayerController();

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MoveCam() const;
	
private:
	float CamX, CamY;
	float MousePosX, MousePosY;
	int32 ViewPortX, ViewPortY;
	
	UPROPERTY(EditAnywhere, Category = "Camera Properties")
	int32 CamSpeed = 0;
};
