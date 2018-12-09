// Fill out your copyright notice in the Description page of Project Settings.

#include "PaddleController.h"
#include "Paddle.h"
#include "TeyonPongGameModeBase.h"
#include "Engine.h"

APaddleController::APaddleController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void APaddleController::SetupInputComponent()
{
	Super::SetupInputComponent();
	id = GetLocalPlayer()->GetControllerId();
	if (id == 0)
	{
		InputComponent->BindAxis("Player0.Move", this, &APaddleController::Move);
	}
	else if (id == 1)
	{
		InputComponent->BindAxis("Player1.Move", this, &APaddleController::Move);
	}
}

void APaddleController::Move(float axisValue)
{
	float value = FMath::Clamp(axisValue, -1.0f, 1.0f);
	((APaddle*)GetPawn())->Move(value);
	if (haveBall && axisValue != 0.0f)
	{
		if (id == 0)
		{
			Cast<ATeyonPongGameModeBase>(GetWorld()->GetAuthGameMode())->GetBall()->StartBall(-1);
			haveBall = false;
		}
		else
		{
			Cast<ATeyonPongGameModeBase>(GetWorld()->GetAuthGameMode())->GetBall()->StartBall(1);
			haveBall = false;
		}
	}
}
