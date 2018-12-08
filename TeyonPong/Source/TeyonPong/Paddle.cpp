// Fill out your copyright notice in the Description page of Project Settings.

#include "Paddle.h"
#include "PaddleController.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	RootComponent = mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (cubeMesh.Succeeded())
	{
		mesh->SetStaticMesh(cubeMesh.Object);
	}
	mesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.5f));
	mesh->SetSimulatePhysics(true);
	mesh->SetEnableGravity(false);
	mesh->BodyInstance.bLockXRotation = true;
	mesh->BodyInstance.bLockYRotation = true;
	mesh->BodyInstance.bLockZRotation = true;
	mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void APaddle::BeginPlay()
{
	MoveToStartingPosition();
	Super::BeginPlay();	
}

void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APaddle::Move(float axisValue)
{
	FVector location = mesh->GetComponentLocation();
	if (axisValue != 0.0f)  GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("Move Paddle!"));
	if (location.Z > 220.0f)
	{
		mesh->SetRelativeLocation(FVector(location.X, 0.0f, 219.0f));
		mesh->SetPhysicsLinearVelocity(FVector(0.0f, 0.0f, 0.0f));
	}
	else if (location.Z < -220.0f)
	{
		mesh->SetRelativeLocation(FVector(location.X, 0.0f, -219.0f));
		mesh->SetPhysicsLinearVelocity(FVector(0.0f, 0.0f, 0.0f));
	}
	else
	{
		//mesh->SetRelativeLocation(FVector(location.X, 0.0f, location.Z + axisValue));
		mesh->SetPhysicsLinearVelocity(FVector(0.0f, 0.0f, axisValue * 200.0f));
		if (axisValue != 0.0f)  GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("Move Paddle kurwa!"));
	}
}

void APaddle::SetStartingPosition(FVector vec)
{
	startingPosition = vec;
}

void APaddle::MoveToStartingPosition()
{
	mesh->SetRelativeLocation(startingPosition);
}

UStaticMeshComponent * APaddle::GetMesh()
{
	return mesh;
}

