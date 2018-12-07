// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	RootComponent = mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (cubeMesh.Succeeded())
	{
		mesh->SetStaticMesh(cubeMesh.Object);
	}
	mesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	mesh->SetSimulatePhysics(true);
	mesh->SetEnableGravity(false);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

