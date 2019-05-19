// Fill out your copyright notice in the Description page of Project Settings.

#include "FFPlayerMovementComponnet.h"
#include <Engine/World.h>
#include <Kismet/GameplayStatics.h>
#include "FFGameModeBase.h"

UFFPlayerMovementComponnet::UFFPlayerMovementComponnet() {}

void UFFPlayerMovementComponnet::TickComponent(
    float DeltaTime,
    enum ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  AFFGameModeBase* GameMode =
      Cast<AFFGameModeBase>(GetWorld()->GetAuthGameMode());

  if (GameMode == nullptr || GetOwner() == nullptr)
    return;

  FVector ActorLocation = GetActorLocation();

  if (ActorLocation.X < GameMode->GetPlayerVerticalMin()) {
    ActorLocation.X = GameMode->GetPlayerVerticalMin();
  } else if (ActorLocation.X > GameMode->GetPlayerVerticalMax()) {
    ActorLocation.X = GameMode->GetPlayerVerticalMax();
  }

  if (ActorLocation.Y < GameMode->GetPlayerHorizontalMin()) {
    ActorLocation.Y = GameMode->GetPlayerHorizontalMin();
  } else if (ActorLocation.Y > GameMode->GetPlayerHorizontalMax()) {
    ActorLocation.Y = GameMode->GetPlayerHorizontalMax();
  }

  GetOwner()->SetActorLocation(ActorLocation);
}
