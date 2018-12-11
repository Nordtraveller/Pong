// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPaddle.h"
#include "EnemyPaddleController.h"

AEnemyPaddle::AEnemyPaddle() : Super()
{
	AIControllerClass = AEnemyPaddleController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}