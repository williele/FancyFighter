// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "FFDurabilityComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FANCYFIGHTER_API UFFDurabilityComponent : public UActorComponent {
  GENERATED_BODY()

 public:
  // Sets default values for this component's properties
  UFFDurabilityComponent();

 protected:
  // Called when the game starts
  virtual void BeginPlay() override;

 private:
  void InitializeMisc();

 private:
  // Misc
  float Durability = 100.0f;

 private:
  // Properties
  UPROPERTY(Category = Durability, EditDefaultsOnly)
  float MaxDurability = 100.0f;

 private:
  // Event handle
  UFUNCTION()
  void TakeAnyDamageHandle(AActor* DamagedActor,
                           float Damage,
                           const class UDamageType* DamageType,
                           class AController* InstigatedBy,
                           AActor* DamageCauser);

 public:
  // Called every frame
  virtual void TickComponent(
      float DeltaTime,
      ELevelTick TickType,
      FActorComponentTickFunction* ThisTickFunction) override;

 public:
  // Getter
  UFUNCTION(BlueprintCallable)
  float GetDurability() { return Durability; }
  UFUNCTION(BlueprintCallable)
  float GetDurabilityRemain() { return Durability / MaxDurability; }
};
