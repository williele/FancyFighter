// Fill out your copyright notice in the Description page of Project Settings.

#include "FFLimitInScene.h"
#include <Engine/World.h>
#include "FFGameModeBase.h"

// Sets default values for this component's properties
UFFLimitInScene::UFFLimitInScene() {
  // Set this component to be initialized when the game starts, and to be ticked
  // every frame.  You can turn these features off to improve performance if you
  // don't need them.
  PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UFFLimitInScene::BeginPlay() {
  Super::BeginPlay();
}

// Called every frame
void UFFLimitInScene::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  AFFGameModeBase* GameMode =
      Cast<AFFGameModeBase>(GetWorld()->GetAuthGameMode());
  if (GameMode == nullptr)
    return;

  FVector OwnerLocation = GetOwner()->GetActorLocation();
  // Check if actor out of scene
  if (OwnerLocation.X < GameMode->GetHorizontalMin() ||
      OwnerLocation.X > GameMode->GetHorizontalMax() ||
      OwnerLocation.Y < GameMode->GetVerticalMin() ||
      OwnerLocation.Y > GameMode->GetVerticalMax()) {
    GetOwner()->Destroy();
  }
}
