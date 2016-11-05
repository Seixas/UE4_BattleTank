// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;


	// inheritance, BeginPlay() is in APawn but we are at PlayerController, so que use virtual/override to tell the API we are possesing the tank, we can only do that acessing the function above in inheritance
	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime ) override;

	//Start the tank moving the barrel so that a shot would it where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

private:
	// return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
