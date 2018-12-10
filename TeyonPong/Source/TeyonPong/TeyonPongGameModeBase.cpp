// Fill out your copyright notice in the Description page of Project Settings.

#include "TeyonPongGameModeBase.h"
#include "Paddle.h"
#include "PongCamera.h"
#include "PongGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Classes/BlueprintGameplayTagLibrary.h"
#include "Engine.h"

ATextRenderActor * ATeyonPongGameModeBase::SearchWithTag(FName tag)
{
	TActorIterator< ATextRenderActor > ActorItr = TActorIterator< ATextRenderActor >(GetWorld());

	while (ActorItr)
	{
		ATextRenderActor* actor = *ActorItr;
		TArray<UTextRenderComponent*> children;
		actor->GetComponents(children);
		for (int i = 0; i < children.Num(); i++)
		{
			if (children[i]->ComponentHasTag(tag))
			{
				ATextRenderActor* actor = *ActorItr;
				return actor;
			}
		}
		++ActorItr;
	}
	return nullptr;
}

FString ATeyonPongGameModeBase::TimeToString(float time)
{
	int32 minutes = time / 60;
	int32 seconds = (int)time % 60;
	if (seconds < 10) return FString(FString::FromInt(minutes) + ":0" + FString::FromInt(seconds));
	else return FString(FString::FromInt(minutes) + ":" + FString::FromInt(seconds));
}

ATeyonPongGameModeBase::ATeyonPongGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = APaddle::StaticClass();
	PlayerControllerClass = APaddleController::StaticClass();
}

void ATeyonPongGameModeBase::StartPlay()
{
	UWorld* const world = GetWorld();
	if (world)
	{
		control0 = Cast<APaddleController>(UGameplayStatics::GetPlayerController(world, 0));
		Cast<APaddle>(control0->GetPawn())->SetStartingPosition(FVector(480.0f, 0.0f, 0.0f));
		control1 = Cast<APaddleController>(UGameplayStatics::CreatePlayer(world, 1, true));
		Cast<APaddle>(control1->GetPawn())->SetStartingPosition(FVector(-480.0f, 0.0f, 0.0f));
		SpawnBall(FVector(480.0f, 0.0f, 0.0f));
		control0->haveBall = true;
		player0ScoreText = SearchWithTag("ScoreP0");
		player1ScoreText = SearchWithTag("ScoreP1");
		timeText = SearchWithTag("TimeText");
		pongGameInstance = Cast<UPongGameInstance>(world->GetGameInstance());
		roundTime = pongGameInstance->roundTime;
	}
	player0Score = 0;
	player1Score = 1;
	Super::StartPlay();
}

void ATeyonPongGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (roundTime < 0.0f || player0Score == pongGameInstance->maxScore || player1Score == pongGameInstance->maxScore)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "/Game/Maps/EndMenu");
	}
	roundTime -= DeltaTime;
	timeText->GetTextRender()->SetText(FText::FromString(TimeToString(roundTime)));
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
		SpawnBall(FVector(480.0f, 0.0f, 0.0f));
		control0->haveBall = true;
		player1Score++;
		player1ScoreText->GetTextRender()->SetText(FText::AsNumber(player1Score));
	}
	else
	{
		SpawnBall(FVector(-480.0f, 0.0f, 0.0f));
		control1->haveBall = true;
		player0Score++;
		player0ScoreText->GetTextRender()->SetText(FText::AsNumber(player0Score));
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
