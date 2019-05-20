// Fill out your copyright notice in the Description page of Project Settings.

#include "FFWeaponBlaster.h"
#include <Engine/World.h>
#include <Kismet/GameplayStatics.h>
#include "FFBullet.h"

UFFWeaponBlaster::UFFWeaponBlaster() {}

void UFFWeaponBlaster::DoFire() {
  if (GetBulletClass() == nullptr)
    return;

  // Pawn the bullet
  FActorSpawnParameters SpawnParameters;
  SpawnParameters.Owner = GetOwner();

  AFFBullet* Bullet = GetWorld()->SpawnActor<AFFBullet>(
      GetBulletClass(), GetComponentLocation(), GetComponentRotation(),
      SpawnParameters);
  if (Bullet) {
    Bullet->SetupBaseDamage(GetBaseDamage());
  }

  // Pawn emitter
  UGameplayStatics::SpawnEmitterAttached(GetMuzzleEffect(), this, NAME_None);
}
