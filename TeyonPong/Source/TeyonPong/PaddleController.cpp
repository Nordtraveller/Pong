// Fill out your copyright notice in the Description page of Project Settings.

#include "PaddleController.h"

APaddleController::APaddleController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void APaddleController::SetId(int i)
{
	id = i;
}

int APaddleController::GetId()
{
	return id;
}
