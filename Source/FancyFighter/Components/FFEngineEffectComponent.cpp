// Fill out your copyright notice in the Description page of Project Settings.

#include "FFEngineEffectComponent.h"

UFFEngineEffectComponent::UFFEngineEffectComponent() {}

void UFFEngineEffectComponent::UpdateVelocity(float Velocity) {
  SetVectorParameter(BoostName,
                     FVector(Velocity * MaxParticleVeloctiy, 0.0f, 0.0f));
}
