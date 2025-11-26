// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once
#include "CoreMinimal.h"   // Required for Unreal types
#include "VehicleControl.generated.h"

USTRUCT(BlueprintType)
struct CARLA_API FVehicleControl
{
	GENERATED_BODY()

	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite)
	float Throttle = 0.0f;

	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite)
	float Steer = 0.0f;

	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite)
	float Brake = 0.0f;

	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite)
	bool bHandBrake = false;

	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite)
	bool bReverse = false;

	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite)
	bool bManualGearShift = false;

	// New Variable defintion 
	// Change to TArray and FVector for Unreal Engine compatibility
	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite)
	TArray<FVector> AugmentedRealityPath ;

	UPROPERTY(Category = "Vehicle Control", EditAnywhere, BlueprintReadWrite, meta = (EditCondition = bManualGearShift))
	int32 Gear = 0;
};
