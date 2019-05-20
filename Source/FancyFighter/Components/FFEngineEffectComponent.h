// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"

#include "FFEngineEffectComponent.generated.h"

/**
 *
 */
UCLASS(ClassGroup = Effects,
       Blueprintable,
       meta = (BlueprintSpawnableComponent))
class FANCYFIGHTER_API UFFEngineEffectComponent
    : public UParticleSystemComponent {
  GENERATED_BODY()

 public:
  UFFEngineEffectComponent();

 private:
  // Misc
  UPROPERTY(Category = EngineEffectName, EditDefaultsOnly)
  FName BoostName = FName("Boost");

 private:
  // Properties
  UPROPERTY(Category = EngineEffect, EditDefaultsOnly)
  float MaxParticleVeloctiy = 50.0f;

 public:
  // Actions
  void UpdateVelocity(float Velocity);
};
