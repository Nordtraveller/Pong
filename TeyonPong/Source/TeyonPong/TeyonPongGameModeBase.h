// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ball.h"
#include "PaddleController.h"
#include "EnemyPaddleController.h"
#include "PongGameInstance.h"
#include "Engine/TextRenderActor.h"
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
	AEnemyPaddleController* enemy;
	ATextRenderActor* player0ScoreText;
	ATextRenderActor* player1ScoreText;
	ATextRenderActor* timeText;
	UPongGameInstance* pongGameInstance;
	int player0Score;
	int player1Score;

	ATextRenderActor* SearchWithTag(FName tag);
	FString TimeToString(float time);

public:
	ATeyonPongGameModeBase(const FObjectInitializer& ObjectInitializer);

	virtual void StartPlay() override;	

	virtual void Tick(float DeltaTime) override;

	ABall* GetBall();

	void Goal(int playerId);

	void SpawnBall(FVector position);

	float roundTime = 120.0f;
};
