// Fill out your copyright notice in the Description page of Project Settings.

#include "TeyonPongGameModeBase.h"
#include "Paddle.h"

ATeyonPongGameModeBase::ATeyonPongGameModeBase(const FObjectInitializer& ObjectInitializer)
{
	DefaultPawnClass = APaddle::StaticClass();
}

void ATeyonPongGameModeBase::StartPlay()
{

}
