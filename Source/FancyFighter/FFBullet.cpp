// Fill out your copyright notice in the Description page of Project Settings.

#include "FFBullet.h"
#include <Components/CapsuleComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>
#include "Components/FFLimitInScene.h"

// Sets default values
AFFBullet::AFFBullet() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
  CapsuleComp->SetCollisionResponseToAllChannels(ECR_Overlap);
  CapsuleComp->SetCapsuleRadius(4.0f);
  CapsuleComp->SetCapsuleHalfHeight(4.0f);
  RootComponent = (USceneComponent*)CapsuleComp;

  ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>(
      TEXT("ProjectileMovement"));
  ProjectileComp->InitialSpeed = 1000.0f;
  ProjectileComp->ProjectileGravityScale = 0.0f;

  LimitInSceneComp =
      CreateDefaultSubobject<UFFLimitInScene>(TEXT("LimitInScene"));
}

void AFFBullet::OverlapHandle(UPrimitiveComponent* OverlappedComponent,
                              AActor* OtherActor,
                              UPrimitiveComponent* OtherComp,
                              int32 OtherBodyIndex,
                              bool bFromSweep,
                              const FHitResult& SweepResult) {
  if (OtherActor == nullptr || OtherActor == GetOwner())
    return;

  if (GetOwner()) {
    UGameplayStatics::ApplyDamage(OtherActor, BaseDamage,
                                  GetInstigatorController(), GetOwner(),
                                  DamageType);
  }

  if (ImpactEffect) {
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect,
                                             SweepResult.ImpactPoint,
                                             SweepResult.ImpactNormal.Rotation());
  }

  Destroy();
}

// Called when the game starts or when spawned
void AFFBullet::BeginPlay() {
  Super::BeginPlay();

  // Events
  CapsuleComp->OnComponentBeginOverlap.AddDynamic(this,
                                                  &AFFBullet::OverlapHandle);
}

// Called every frame
void AFFBullet::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
}
