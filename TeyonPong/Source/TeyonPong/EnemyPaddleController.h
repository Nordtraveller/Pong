// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyPaddleController.generated.h"

/**
 * 
 */
UCLASS()
class TEYONPONG_API AEnemyPaddleController : public AAIController
{
	GENERATED_BODY()
	
public:
	void Move(float axisValue);

	bool haveBall = false;
};
