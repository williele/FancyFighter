// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/FFWeapon.h"
#include "CoreMinimal.h"

#include "FFWeaponBlaster.generated.h"

/**
 *
 */
UCLASS(ClassGroup = Weapon, Blueprintable, meta = (BlueprintSpawnableComponent))
class FANCYFIGHTER_API UFFWeaponBlaster : public UFFWeapon {
  GENERATED_BODY()

 public:
  UFFWeaponBlaster();

 protected:
  virtual void DoFire() override;
};
