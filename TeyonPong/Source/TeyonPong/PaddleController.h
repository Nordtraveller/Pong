// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddleController.generated.h"

/**
 * 
 */
UCLASS()
class TEYONPONG_API APaddleController : public APlayerController
{
	GENERATED_BODY()

private:
	
public:
	APaddleController(const FObjectInitializer& ObjectInitializer);

	void SetupInputComponent() override;

	void Move(float axisValue);
};
