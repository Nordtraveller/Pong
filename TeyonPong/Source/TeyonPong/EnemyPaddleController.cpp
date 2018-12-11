// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPaddleController.h"
#include "Paddle.h"
#include "TeyonPongGameModeBase.h"

void AEnemyPaddleController::Move(float axisValue)
{
	float value = FMath::Clamp(axisValue, -1.0f, 1.0f);
	((APaddle*)GetPawn())->Move(value);
	if (haveBall && axisValue != 0.0f)
	{
		Cast<ATeyonPongGameModeBase>(GetWorld()->GetAuthGameMode())->GetBall()->StartBall(1);
		haveBall = false;
	}
}

