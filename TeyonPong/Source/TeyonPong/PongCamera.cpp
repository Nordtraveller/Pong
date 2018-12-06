// Fill out your copyright notice in the Description page of Project Settings.

#include "PongCamera.h"

APongCamera::APongCamera(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	UCameraComponent* camera = GetCameraComponent();

	camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	camera->SetRelativeLocation(FVector(0.0f, 1000.0f, 0.0f));
	camera->OrthoWidth = 1024;
	camera->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	camera->SetAbsolute(true, true, true);

}

FVector2D APongCamera::GetViewDimensions()
{
	UCameraComponent* Camera = GetCameraComponent();
	FVector2D dimensions;

	dimensions.X = Camera->OrthoWidth;
	dimensions.Y = 1 / (Camera->AspectRatio / Camera->OrthoWidth);

	return dimensions;
}
