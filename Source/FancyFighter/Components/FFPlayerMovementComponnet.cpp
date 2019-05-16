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

  if (ActorLocation.X < GameMode->GetVerticalMin()) {
    ActorLocation.X = GameMode->GetVerticalMin();
  } else if (ActorLocation.X > GameMode->GetVerticalMax()) {
    ActorLocation.X = GameMode->GetVerticalMax();
  }

  if (ActorLocation.Y < GameMode->GetHorizontalMin()) {
    ActorLocation.Y = GameMode->GetHorizontalMin();
  } else if (ActorLocation.Y > GameMode->GetHorizontalMax()) {
    ActorLocation.Y = GameMode->GetHorizontalMax();
  }

  GetOwner()->SetActorLocation(ActorLocation);
}
