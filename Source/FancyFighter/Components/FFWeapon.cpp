// Fill out your copyright notice in the Description page of Project Settings.

#include "FFWeapon.h"
#include <Engine/World.h>

// Sets default values for this component's properties
UFFWeapon::UFFWeapon() {
  // Set this component to be initialized when the game starts, and to be ticked
  // every frame.  You can turn these features off to improve performance if you
  // don't need them.
  PrimaryComponentTick.bCanEverTick = true;
}

void UFFWeapon::Fire() {
  if (NextFire < GetWorld()->GetTimeSeconds()) {
    DoFire();

    NextFire = FireRate + GetWorld()->GetTimeSeconds();
  }
}

void UFFWeapon::DoFire() {
  // Do nothing here
  UE_LOG(LogTemp, Warning, TEXT("Weapon fire"));
}

// Called when the game starts
void UFFWeapon::BeginPlay() {
  Super::BeginPlay();
}

// Called every frame
void UFFWeapon::TickComponent(float DeltaTime,
                              ELevelTick TickType,
                              FActorComponentTickFunction* ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
