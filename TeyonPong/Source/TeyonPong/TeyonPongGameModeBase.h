// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ball.h"
#include "PaddleController.h"
#include "TeyonPongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TEYONPONG_API ATeyonPongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	ABall* ball;
	APaddleController* control0;
	APaddleController* control1;

public:
	ATeyonPongGameModeBase(const FObjectInitializer& ObjectInitializer);

	virtual void StartPlay() override;	

	ABall* GetBall();

	void Goal(int playerId);

	void SpawnBall(FVector position);
};
