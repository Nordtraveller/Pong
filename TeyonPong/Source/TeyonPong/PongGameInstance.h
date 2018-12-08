// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PongGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TEYONPONG_API UPongGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPongGameInstance(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pong)
		int numberOfPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pong)
		float roundTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pong)
		int maxScore;

};
