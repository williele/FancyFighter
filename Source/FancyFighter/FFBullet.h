// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FFBullet.generated.h"

UCLASS()
class FANCYFIGHTER_API AFFBullet : public AActor {
  GENERATED_BODY()

 public:
  // Sets default values for this actor's properties
  AFFBullet();

 private:
  // Components
  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UCapsuleComponent* CapsuleComp;

  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UProjectileMovementComponent* ProjectileComp;

  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UFFLimitInScene* LimitInSceneComp;

  UPROPERTY(Category = VisualEffects,
            EditDefaultsOnly,
            meta = (AllowPrivateAccess = "true"))
  class UParticleSystem* ImpactEffect;

 private:
  // Misc
  float BaseDamage = 0.0f;

  UPROPERTY(Category = Bullet,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class TSubclassOf<UDamageType> DamageType;

 private:
  // Event handle
  UFUNCTION()
  void OverlapHandle(UPrimitiveComponent* OverlappedComponent,
                     AActor* OtherActor,
                     UPrimitiveComponent* OtherComp,
                     int32 OtherBodyIndex,
                     bool bFromSweep,
                     const FHitResult& SweepResult);

 protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

 public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

 public:
  // Setup
  void SetupBaseDamage(float Damage) { BaseDamage = Damage; }
};
