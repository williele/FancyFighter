// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "FFPlayerMovementComponnet.generated.h"

/**
 *
 */
UCLASS()
class FANCYFIGHTER_API UFFPlayerMovementComponnet
    : public UFloatingPawnMovement {
  GENERATED_BODY()

 public:
  UFFPlayerMovementComponnet();

 public:
  virtual void TickComponent(
      float DeltaTime,
      enum ELevelTick TickType,
      FActorComponentTickFunction* ThisTickFunction) override;
};
