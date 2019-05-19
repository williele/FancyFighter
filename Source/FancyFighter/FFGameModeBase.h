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
  UPROPERTY(Category = PlayerLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float PlayerHorizontalMin = -400.0f;
  UPROPERTY(Category = PlayerLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float PlayerHorizontalMax = 400.0f;
  UPROPERTY(Category = PlayerLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float PlayerVerticalMin = -400.0f;
  UPROPERTY(Category = PlayerLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float PlayerVerticalMax = 400.0f;

	UPROPERTY(Category = SceneLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float SceneLimitScale = 1.0f;

  UPROPERTY(Category = SceneLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float HorizontalMin = -1000.0f;
  UPROPERTY(Category = SceneLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float HorizontalMax = 1000.0f;
  UPROPERTY(Category = SceneLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float VerticalMin = -1000.0f;
  UPROPERTY(Category = SceneLimit,
            EditDefaultsOnly,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float VerticalMax = 1000.0f;

 public:
  // Getter
  float GetPlayerHorizontalMin() { return PlayerHorizontalMin; }
  float GetPlayerHorizontalMax() { return PlayerHorizontalMax; }
  float GetPlayerVerticalMin() { return PlayerVerticalMin; }
  float GetPlayerVerticalMax() { return PlayerVerticalMax; }

  float GetHorizontalMin() { return HorizontalMin * SceneLimitScale; }
  float GetHorizontalMax() { return HorizontalMax * SceneLimitScale; }
  float GetVerticalMin() { return VerticalMin * SceneLimitScale; }
  float GetVerticalMax() { return VerticalMax * SceneLimitScale; }

 public:
  virtual void Tick(float DeltaSeconds) override;
};
