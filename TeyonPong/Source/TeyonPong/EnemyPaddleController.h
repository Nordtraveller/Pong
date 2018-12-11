// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Ball.h"
#include "Paddle.h"
#include "EnemyPaddleController.generated.h"

/**
 * 
 */
UCLASS()
class TEYONPONG_API AEnemyPaddleController : public AAIController
{
	GENERATED_BODY()
	
private:
	APaddle* paddle;
	ABall* ball;

public:
	virtual void Tick(float DeltaTime) override;

	void Move(float axisValue);

	void FindBall();

	bool haveBall = false;
};
