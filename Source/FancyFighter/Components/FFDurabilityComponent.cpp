// Fill out your copyright notice in the Description page of Project Settings.

#include "FFDurabilityComponent.h"
#include <GameFramework/Actor.h>

// Sets default values for this component's properties
UFFDurabilityComponent::UFFDurabilityComponent() {
  // Set this component to be initialized when the game starts, and to be ticked
  // every frame.  You can turn these features off to improve performance if you
  // don't need them.
  PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UFFDurabilityComponent::BeginPlay() {
  Super::BeginPlay();

  InitializeMisc();

  // Binding take any damage events
  GetOwner()->OnTakeAnyDamage.AddDynamic(
      this, &UFFDurabilityComponent::TakeAnyDamageHandle);
}

void UFFDurabilityComponent::InitializeMisc() {
  Durability = MaxDurability;
}

void UFFDurabilityComponent::TakeAnyDamageHandle(
    AActor* DamagedActor,
    float Damage,
    const class UDamageType* DamageType,
    class AController* InstigatedBy,
    AActor* DamageCauser) {
  Durability = FMath::Clamp(Durability - Damage, 0.0f, MaxDurability);
  if (Durability == 0.0f) {
    GetOwner()->Destroy();
  }
}

// Called every frame
void UFFDurabilityComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
