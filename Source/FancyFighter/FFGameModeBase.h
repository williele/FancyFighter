// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "FFGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class FANCYFIGHTER_API AFFGameModeBase : public AGameModeBase {
  GENERATED_BODY()

 public:
  AFFGameModeBase();

 protected:
  virtual void BeginPlay() override;

 private:
  UPROPERTY(Category = GameModeMisc,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float HorizontalMin = -400.0f;

  UPROPERTY(Category = GameModeMisc,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float HorizontalMax = 400.0f;

  UPROPERTY(Category = GameModeMisc,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float VerticalMin = -400.0f;

  UPROPERTY(Category = GameModeMisc,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float VerticalMax = 400.0f;

 public:
  // Getter
  float GetHorizontalMin() { return HorizontalMin; }
  float GetHorizontalMax() { return HorizontalMax; }
  float GetVerticalMin() { return VerticalMin; }
  float GetVerticalMax() { return VerticalMax; }

 public:
  virtual void Tick(float DeltaSeconds) override;
};
