// Fill out your copyright notice in the Description page of Project Settings.

#include "Paddle.h"
#include "PaddleController.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/Components/InputComponent.h"
#include "CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	mesh->SetRelativeLocation(startingPosition);
	Super::BeginPlay();	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APaddle::Move(float axisValue)
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, *FString("Input " + FString::FromInt((int)axisValue)));
	mesh->SetPhysicsLinearVelocity(FVector(0.0f, 0.0f, axisValue * 200.0f));
}

void APaddle::SetStartingPosition(FVector vec)
{
	startingPosition = vec;
}

