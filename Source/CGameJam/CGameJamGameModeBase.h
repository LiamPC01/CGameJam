// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CGameJamGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CGAMEJAM_API ACGameJamGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform SpawnTransformationGameMode;

		UFUNCTION()
			void SetNewSpawnTransform(FTransform NewTransform);
};
