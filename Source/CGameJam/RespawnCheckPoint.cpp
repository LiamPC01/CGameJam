// Fill out your copyright notice in the Description page of Project Settings.



#include "RespawnCheckPoint.h"
#include "Components/BoxComponent.h"
#include "CGameJamGameModeBase.h"
#include "PlayerCharacter.h"

// Sets default values
ARespawnCheckPoint::ARespawnCheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
}

// Called when the game starts or when spawned
void ARespawnCheckPoint::BeginPlay()
{
	Super::BeginPlay();

	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ARespawnCheckPoint::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &ARespawnCheckPoint::OnOverlapEnd);

	GameMode = (ACGameJamGameModeBase*)GetWorld()->GetAuthGameMode();

	
}

// Called every frame
void ARespawnCheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARespawnCheckPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("COLLIDESTART"));
	if (OtherActor) {
		APlayerCharacter* MyPlayer = Cast<APlayerCharacter>(OtherActor);
		
		playerLocation = MyPlayer->GetActorLocation();
		playerRespawnTransform = MyPlayer->GetActorTransform();
		GameMode->SetNewSpawnTransform(playerRespawnTransform);

	
		UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *playerRespawnTransform.ToString());
	}
}

void ARespawnCheckPoint::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

