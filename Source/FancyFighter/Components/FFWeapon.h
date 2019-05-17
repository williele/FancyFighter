// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "CoreMinimal.h"

#include "FFWeapon.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FANCYFIGHTER_API UFFWeapon : public USceneComponent {
  GENERATED_BODY()

 public:
  // Sets default values for this component's properties
  UFFWeapon();

 private:
  // Properties
  UPROPERTY(Category = Weapon,
            EditDefaultsOnly,
            meta = (AllowPrivateAccess = "true"))
  bool bIsPrimaryWeapon = false;

  UPROPERTY(Category = Weapon,
            EditDefaultsOnly,
            meta = (AllowPrivateAccess = "true"))
  float FireRate = 0.2f;

  UPROPERTY(Category = Weapon,
            EditDefaultsOnly,
            meta = (AllowPrivateAccess = "true"))
  TSubclassOf<class AFFBullet> BulletClass;

 public:
  // Getter
  bool GetIsPrimaryWeapon() { return bIsPrimaryWeapon; }

  TSubclassOf<class AFFBullet> GetBulletClass() { return BulletClass; }

 public:
  // Actions
  void Fire();

 protected:
  // Functionality
  virtual void DoFire();

 protected:
  // Called when the game starts
  virtual void BeginPlay() override;

 public:
  // Called every frame
  virtual void TickComponent(
      float DeltaTime,
      ELevelTick TickType,
      FActorComponentTickFunction* ThisTickFunction) override;

 private:
  // Misc
  float NextFire = 0.0f;
};
