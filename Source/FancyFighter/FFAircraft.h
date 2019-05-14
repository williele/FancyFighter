// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "FFAircraft.generated.h"

UCLASS()
class FANCYFIGHTER_API AFFAircraft : public APawn {
  GENERATED_BODY()

 public:
  // Sets default values for this pawn's properties
  AFFAircraft();

  // Components
 private:
  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class USceneComponent* AircraftContainComp;

  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UStaticMeshComponent* AircraftComp;

  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UFloatingPawnMovement* MovementComp;

  class UInputComponent* InputComponent;

  // Event handle
 private:
 protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // Tick functions
 private:
  void TickMovement(float DeltaTime);

 public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent* PlayerInputComponent) override;

  // Misc
 protected:
  UPROPERTY(Category = InputName, EditDefaultsOnly)
  FName VerticalInputName = FName("Vertical");

  UPROPERTY(Category = InputName, EditDefaultsOnly)
  FName HorizontalInputName = FName("Horizontal");
};
