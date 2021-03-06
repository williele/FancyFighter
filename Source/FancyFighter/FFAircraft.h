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

 protected:
  // Properties
  UPROPERTY(Category = Aircraft, EditDefaultsOnly, BlueprintReadOnly)
  float MaxRoll = 40.0f;

  UPROPERTY(Category = Aircraft, EditDefaultsOnly, BlueprintReadOnly)
  float TurnSpeed = 2.0f;

  UPROPERTY(Category = Aircraft, EditDefaultsOnly, BlueprintReadOnly)
  float RollInterpSpeed = 5.0f;

 private:
  // Components
  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UCapsuleComponent* CapsuleComp;

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
  class USpringArmComponent* SpringArmComp;

  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UCameraComponent* CameraComp;

  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UFloatingPawnMovement* MovementComp;

  UPROPERTY(Category = Components,
            VisibleAnywhere,
            BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UFFDurabilityComponent* DurabilityComp;

  class UInputComponent* InputComponent;

 private:
  // Events handler
  UFUNCTION()
  void HitHandle(UPrimitiveComponent* HitComponent,
                 AActor* OtherActor,
                 UPrimitiveComponent* OtherComp,
                 FVector NormalImpulse,
                 const FHitResult& Hit);

 public:
  // Actions
  void BeginPrimaryFire();
  void EndPrimaryFire();

  void SecondaryFire();

 protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

 private:
  // Initialize functions
  void InitializeEvents();
  void InitializeGun();
  void InitializeEffects();

 public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent* PlayerInputComponent) override;

 private:
  // Tick functions
  void TickMovement(float DeltaTime);
  void TickFire(float DeltaTime);
  void TickEngine(float DeltaTime);

 protected:
  // Misc
  bool bCanFire = false;

  TSubclassOf<class UDamageType> HitDamageType;

  TArray<class UFFWeapon*> PrimaryWeapons;
  TArray<class UFFWeapon*> SecondaryWeapons;
  TArray<class UFFEngineEffectComponent*> EngineEffects;

  UPROPERTY(Category = InputName, EditDefaultsOnly)
  FName VerticalInputName = FName("Vertical");

  UPROPERTY(Category = InputName, EditDefaultsOnly)
  FName HorizontalInputName = FName("Horizontal");

  UPROPERTY(Category = InputName, EditDefaultsOnly)
  FName PrimaryFireInputName = FName("PrimaryFire");

  UPROPERTY(Category = InputName, EditDefaultsOnly)
  FName SecondaryFireInputName = FName("SecondaryFire");
};
