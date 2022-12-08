// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RespawnCheckPoint.generated.h"

UCLASS()
class CGAMEJAM_API ARespawnCheckPoint : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* CollisionVolume;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FTransform playerRespawnTransform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector playerLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ACGameJamGameModeBase* GameMode;

	// Sets default values for this actor's properties
	ARespawnCheckPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



};
