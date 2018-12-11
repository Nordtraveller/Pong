// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPaddleController.h"
#include "TeyonPongGameModeBase.h"



void AEnemyPaddleController::Tick(float DeltaTime)
{
	if (!paddle) paddle = (APaddle*)GetPawn();
	if (!ball) FindBall();
	if (ball && paddle)
	{
		FVector location = ball->GetActorLocation();
		if (location.Z > paddle->GetActorLocation().Z) Move(1.0f);
		else Move(-1.0f);
	}
}

void AEnemyPaddleController::Move(float axisValue)
{
	float value = FMath::Clamp(axisValue, -1.0f, 1.0f);
	paddle->Move(value);
	if (haveBall && axisValue != 0.0f)
	{
		Cast<ATeyonPongGameModeBase>(GetWorld()->GetAuthGameMode())->GetBall()->StartBall(1);
		haveBall = false;
	}
}

void AEnemyPaddleController::FindBall()
{
	ball = Cast<ATeyonPongGameModeBase>(GetWorld()->GetAuthGameMode())->GetBall();
}

