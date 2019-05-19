// Fill out your copyright notice in the Description page of Project Settings.

#include "FFAircraft.h"
#include <Camera/CameraComponent.h>
#include <Components/ArrowComponent.h>
#include <Components/InputComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/FloatingPawnMovement.h>
#include <GameFramework/SpringArmComponent.h>
#include "Components/FFPlayerMovementComponnet.h"
#include "Components/FFWeapon.h"

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

  SpringArmComp =
      CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
  SpringArmComp->bEnableCameraLag = true;
  SpringArmComp->bInheritYaw = false;
  SpringArmComp->bInheritPitch = false;
  SpringArmComp->bInheritRoll = false;
  SpringArmComp->bDoCollisionTest = false;
  SpringArmComp->SetupAttachment(AircraftContainComp);

  CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
  CameraComp->SetupAttachment(SpringArmComp);

  MovementComp =
      CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
}

void AFFAircraft::BeginPrimaryFire() {
  bCanFire = true;
}

void AFFAircraft::EndPrimaryFire() {
  bCanFire = false;
}

void AFFAircraft::SecondaryFire() {
  // Fire on secondary weapon
  for (UFFWeapon* Weapon : SecondaryWeapons) {
    Weapon->Fire();
  }
}

// Called when the game starts or when spawned
void AFFAircraft::BeginPlay() {
  Super::BeginPlay();

  InitializeGun();
}

void AFFAircraft::InitializeGun() {
  TArray<UFFWeapon*> Weapons;
  GetComponents<UFFWeapon>(Weapons);

  for (int16 Index = 0; Index < Weapons.Num(); ++Index) {
    if (Weapons[Index]->GetIsPrimaryWeapon()) {
      PrimaryWeapons.Add(Weapons[Index]);
    } else {
      SecondaryWeapons.Add(Weapons[Index]);
    }
  }
}

void AFFAircraft::TickMovement(float DeltaTime) {
  if (InputComponent == nullptr)
    return;

  float Vertical = InputComponent->GetAxisValue(VerticalInputName);
  float Horizontal = InputComponent->GetAxisValue(HorizontalInputName);
  AddMovementInput(Vertical * GetActorForwardVector());

  // Turning
  float YawDelta = MovementComp->Velocity.Size() / MovementComp->GetMaxSpeed() *
                   Horizontal * Vertical;
  AddActorWorldRotation(FRotator(0.0f, YawDelta * TurnSpeed, 0.0f));

  // Rolling
  float RollTarget = YawDelta * MaxRoll;
  FRotator NewRotator = AircraftContainComp->GetRelativeTransform().Rotator();
  float RollDelta =
      FMath::FInterpTo(NewRotator.Roll, RollTarget, DeltaTime, RollInterpSpeed);
  NewRotator.Roll = RollDelta;
  AircraftContainComp->SetRelativeRotation(NewRotator);
}

void AFFAircraft::TickFire(float DeltaTime) {
  if (!bCanFire)
    return;

  // Fire on primary weapon
  for (UFFWeapon* Weapon : PrimaryWeapons) {
    Weapon->Fire();
  }
}

// Called every frame
void AFFAircraft::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  TickMovement(DeltaTime);
  TickFire(DeltaTime);
}

// Called to bind functionality to input
void AFFAircraft::SetupPlayerInputComponent(
    UInputComponent* PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  InputComponent = PlayerInputComponent;
  // Binding input
  InputComponent->BindAxis(VerticalInputName);
  InputComponent->BindAxis(HorizontalInputName);

  InputComponent->BindAction(PrimaryFireInputName, IE_Pressed, this,
                             &AFFAircraft::BeginPrimaryFire);
  InputComponent->BindAction(PrimaryFireInputName, IE_Released, this,
                             &AFFAircraft::EndPrimaryFire);
  InputComponent->BindAction(SecondaryFireInputName, IE_Pressed, this,
                             &AFFAircraft::SecondaryFire);
}
