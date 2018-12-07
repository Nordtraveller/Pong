// Fill out your copyright notice in the Description page of Project Settings.

#include "TeyonPongGameModeBase.h"
#include "Paddle.h"
#include "PaddleController.h"
#include "Ball.h"
#include "PongCamera.h"
#include "Kismet/GameplayStatics.h"

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
		APaddle* paddle0 = Cast<APaddle>(control0->GetPawn());
		paddle0->SetStartingPosition(FVector(-480.0f, 0.0f, 0.0f));
		paddle0->GetRootComponent()->SetRelativeLocation(FVector(-480.0f, 0.0f, 0.0f));
		APaddleController* control1 = Cast<APaddleController>(UGameplayStatics::CreatePlayer(world, 1, true));
		APaddle* paddle1 = Cast<APaddle>(control1->GetPawn());
		paddle1->SetStartingPosition(FVector(480.0f, 0.0f, 0.0f));
		paddle1->GetRootComponent()->SetRelativeLocation(FVector(480.0f, 0.0f, 0.0f));
		ChoosePlayerStart(world->GetFirstPlayerController());		
		world->SpawnActor<ABall>(ABall::StaticClass());
	}
	Super::StartPlay();
}
