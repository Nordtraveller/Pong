// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

UCLASS()
class TEYONPONG_API APaddle : public APawn
{
	GENERATED_BODY()

private:
	FVector startingPosition;

protected:
	virtual void BeginPlay() override;

public:	
	APaddle();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(float axisValue);

	void SetStartingPosition(FVector vec);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PaddleMesh")
	UStaticMeshComponent* mesh;

};
