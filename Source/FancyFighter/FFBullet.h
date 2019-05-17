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
  class UProjectileMovementComponent* ProjectileComponent;

 protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

 public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;
};
