// Fill out your copyright notice in the Description page of Project Settings.

#include "FFAircraft.h"
#include <Components/ArrowComponent.h>
#include <Components/InputComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/FloatingPawnMovement.h>

// Sets default values
AFFAircraft::AFFAircraft() {
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

  AircraftContainComp =
      CreateDefaultSubobject<USceneComponent>(TEXT("AircraftContain"));
  AircraftContainComp->SetupAttachment(GetRootComponent());

  AircraftComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Aircraft"));
  AircraftComp->SetupAttachment(AircraftContainComp);

#if WITH_EDITORONLY_DATA
  UArrowComponent* ArrowComp =
      CreateDefaultSubobject<UArrowComponent>(TEXT("Direction"));
  AircraftComp->SetupAttachment(AircraftContainComp);
#endif

  MovementComp =
      CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
}

// Called when the game starts or when spawned
void AFFAircraft::BeginPlay() {
  Super::BeginPlay();
}

void AFFAircraft::TickMovement(float DeltaTime) {
  if (InputComponent == nullptr)
    return;

  float Vertical = InputComponent->GetAxisValue(VerticalInputName);
  float Horizontal = InputComponent->GetAxisValue(HorizontalInputName);

  AddMovementInput(Vertical * GetActorForwardVector() +
                   Horizontal * GetActorRightVector());

  // Rolling
  float RollTarget = Horizontal * MaxRoll;
  FRotator NewRotator = AircraftContainComp->GetRelativeTransform().Rotator();
  float RollDelta = FMath::FInterpTo(NewRotator.Roll, RollTarget, DeltaTime,
                                     RollInterpSpeed);
  NewRotator.Roll = RollDelta;
  AircraftContainComp->SetRelativeRotation(NewRotator);
}

// Called every frame
void AFFAircraft::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  TickMovement(DeltaTime);
}

// Called to bind functionality to input
void AFFAircraft::SetupPlayerInputComponent(
    UInputComponent* PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  InputComponent = PlayerInputComponent;
  // Binding input
  InputComponent->BindAxis(VerticalInputName);
  InputComponent->BindAxis(HorizontalInputName);
}
