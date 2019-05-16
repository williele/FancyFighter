// Fill out your copyright notice in the Description page of Project Settings.

#include "FFGameModeBase.h"
#include <Engine/Engine.h>
#include <Engine/GameViewportClient.h>

AFFGameModeBase::AFFGameModeBase() {
  DefaultPawnClass = nullptr;
}

void AFFGameModeBase::BeginPlay() {
  Super::BeginPlay();
}

void AFFGameModeBase::Tick(float DeltaSeconds) {
  Super::Tick(DeltaSeconds);
}
