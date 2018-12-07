// Fill out your copyright notice in the Description page of Project Settings.

#include "TeyonPongGameModeBase.h"
#include "Paddle.h"
#include "PongCamera.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

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
		control0 = Cast<APaddleController>(UGameplayStatics::GetPlayerController(world, 0));
		Cast<APaddle>(control0->GetPawn())->SetStartingPosition(FVector(-480.0f, 0.0f, 0.0f));
		control1 = Cast<APaddleController>(UGameplayStatics::CreatePlayer(world, 1, true));
		Cast<APaddle>(control1->GetPawn())->SetStartingPosition(FVector(480.0f, 0.0f, 0.0f));
		SpawnBall(FVector(-480.0f, 0.0f, 0.0f));
		control0->haveBall = true;
	}
	Super::StartPlay();
}

ABall * ATeyonPongGameModeBase::GetBall()
{
	return ball;
}

void ATeyonPongGameModeBase::Goal(int playerId)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString("Goal " + FString::FromInt(playerId)));
	if (playerId == 0)
	{
		SpawnBall(FVector(-480.0f, 0.0f, 0.0f));
		control0->haveBall = true;
	}
	else
	{
		SpawnBall(FVector(480.0f, 0.0f, 0.0f));
		control1->haveBall = true;
	}
	Cast<APaddle>(control0->GetPawn())->MoveToStartingPosition();
	Cast<APaddle>(control1->GetPawn())->MoveToStartingPosition();
}

void ATeyonPongGameModeBase::SpawnBall(FVector position)
{
	if (ball)
	{
		ball->Destroy();
	}
	ball = GetWorld()->SpawnActor<ABall>(ABall::StaticClass());
	ball->GetRootComponent()->SetRelativeLocation(position);
}
