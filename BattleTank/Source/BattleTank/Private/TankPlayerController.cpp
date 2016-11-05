// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

// Tick
	// Super
	
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller bot possesing a tank"));
	}
	UE_LOG(LogTemp, Warning, TEXT("Player controller possessing %s"), *(ControlledTank->GetName()));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
			//TODO tell controlled tank to aim at this point
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return false;
}


