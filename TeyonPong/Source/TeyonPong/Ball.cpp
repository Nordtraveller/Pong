// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine.h"
#include "Paddle.h"

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
	mesh->BodyInstance.bLockXRotation = true;
	mesh->BodyInstance.bLockYRotation = true;
	mesh->BodyInstance.bLockZRotation = true;

	mesh->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	mesh->SetPhysicsLinearVelocity(FVector(200.0f, 0.0f, 0.0f));
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	APaddle* paddle = Cast<APaddle>(OtherActor);
	if (paddle)
	{
		FVector velocity = mesh->GetPhysicsLinearVelocity();
		velocity.X = -velocity.X * bounceSpeedBoostMultiplier;
		velocity.Z = velocity.Z + paddle->GetMesh()->GetPhysicsLinearVelocity().Z;
		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString(velocity.ToString()));
		mesh->SetPhysicsLinearVelocity(velocity);
	}
	else
	{
		FVector velocity = mesh->GetPhysicsLinearVelocity();
		velocity.Z = -velocity.Z * bounceSpeedBoostMultiplier;
		mesh->SetPhysicsLinearVelocity(velocity);
	}

}

