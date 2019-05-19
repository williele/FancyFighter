// Fill out your copyright notice in the Description page of Project Settings.

#include "FFBullet.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include "Components/FFLimitInScene.h"

// Sets default values
AFFBullet::AFFBullet() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
      TEXT("ProjectileMovement"));
  ProjectileComponent->InitialSpeed = 1000.0f;
  ProjectileComponent->ProjectileGravityScale = 0.0f;

  LimitInSceneComponent =
      CreateDefaultSubobject<UFFLimitInScene>(TEXT("LimitInScene"));
}

// Called when the game starts or when spawned
void AFFBullet::BeginPlay() {
  Super::BeginPlay();
}

// Called every frame
void AFFBullet::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
}
