// Fill out your copyright notice in the Description page of Project Settings.

#include "PaddleController.h"
#include "Paddle.h"

APaddleController::APaddleController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void APaddleController::SetupInputComponent()
{
	Super::SetupInputComponent();
	int32 id = GetLocalPlayer()->GetControllerId();
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
	((APaddle*)GetPawn())->Move(axisValue);
}
