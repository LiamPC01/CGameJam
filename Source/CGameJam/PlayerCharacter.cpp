// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	AirControl = 0.5f;
	JumpHeight = 500.0f;
	MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->AirControl = AirControl;
	GetCharacterMovement()->JumpZVelocity = JumpHeight;
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::PlayerJump);
	

}

void APlayerCharacter::MoveRight(float value)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(Direction, value);
	if (value == 1) {
		const FQuat NewRotation(FRotator(0.0f, -90.0f, 0.0f));
		GetMesh()->SetRelativeRotation(NewRotation, false, nullptr, ETeleportType::None);
	}
	else if (value == -1) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Move left"));
		const FQuat NewRotation(FRotator(0.0f,90.0f,0.0f));
		GetMesh()->SetRelativeRotation(NewRotation,false,nullptr,ETeleportType::None);
	}
}

void APlayerCharacter::PlayerJump()
{
	Jump();
}

void APlayerCharacter::PlayerStopJump()
{
	StopJumping();
}




