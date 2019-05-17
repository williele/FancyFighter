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
  // Misc
  UPROPERTY(Category = Weapon,
            EditDefaultsOnly,
            meta = (AllowPrivateAccess = "true"))
  bool bIsPrimaryWeapon = false;

 public:
  // getter
  bool GetIsPrimaryWeapon() { return bIsPrimaryWeapon; }

 protected:
  // Called when the game starts
  virtual void BeginPlay() override;

 public:
  // Called every frame
  virtual void TickComponent(
      float DeltaTime,
      ELevelTick TickType,
      FActorComponentTickFunction* ThisTickFunction) override;
};
