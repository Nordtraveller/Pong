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
		APaddleController* control0 = Cast<APaddleController>(UGameplayStatics::GetPlayerController(world, 0));
		control0->SetId(0);
		APaddleController* control1 = Cast<APaddleController>(UGameplayStatics::CreatePlayer(world, 1, true));
		control1->SetId(1);
		ChoosePlayerStart(world->GetFirstPlayerController());		
	}
	Super::StartPlay();
}
