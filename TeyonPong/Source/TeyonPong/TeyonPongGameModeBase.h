// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TeyonPongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TEYONPONG_API ATeyonPongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATeyonPongGameModeBase(const FObjectInitializer& ObjectInitializer);

	virtual void StartPlay() override;	
};
