// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

UCLASS()
class TEYONPONG_API AGoal : public AActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:	
	AGoal();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere)
	int playerdId;

	virtual void Tick(float DeltaTime) override;

};
