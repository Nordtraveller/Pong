// Fill out your copyright notice in the Description page of Project Settings.

#include "TeyonPongGameModeBase.h"
#include "Paddle.h"
#include "PaddleController.h"
#include "PongCamera.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"

ATeyonPongGameModeBase::ATeyonPongGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	DefaultPawnClass = APaddle::StaticClass();
	PlayerControllerClass = APaddleController::StaticClass();
}

void ATeyonPongGameModeBase::StartPlay()
{
	UWorld* const world = GetWorld();
	if (world)
	{
		UGameplayStatics::CreatePlayer(world, 0, true);
		UGameplayStatics::CreatePlayer(world, 1, true);
		ChoosePlayerStart(world->GetFirstPlayerController());
	}
	Super::StartPlay();
}
