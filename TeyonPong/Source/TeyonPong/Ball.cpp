// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Paddle.h"
#include "Goal.h"
#include "TeyonPongGameModeBase.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	RootComponent = mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("StaticMesh'/Engine/EngineMeshes/Cube.Cube'"));
	if (cubeMesh.Succeeded()) mesh->SetStaticMesh(cubeMesh.Object);
	static ConstructorHelpers::FObjectFinder<UMaterial> material(TEXT("Material'/Game/MAT_White.MAT_White'"));
	if (material.Succeeded())
	{
		UMaterial* uMaterial = (UMaterial*)material.Object;
		UMaterialInstanceDynamic* materialInstance = UMaterialInstanceDynamic::Create(uMaterial, mesh);
		mesh->SetMaterial(0, materialInstance);
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
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::StartBall(float direction)
{
	mesh->SetPhysicsLinearVelocity(FVector(direction * 300.0f, 0.0f, 0.0f));
}

void ABall::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	APaddle* paddle = Cast<APaddle>(OtherActor);
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("Overlap!"));
	if (paddle)
	{
		FVector velocity = mesh->GetPhysicsLinearVelocity();
		velocity.X = -velocity.X * bounceSpeedBoostMultiplier;
		velocity.Z = velocity.Z + paddle->GetMesh()->GetPhysicsLinearVelocity().Z;
		mesh->SetPhysicsLinearVelocity(velocity);
	}
	else if (AGoal* goal = Cast<AGoal>(OtherActor))
	{
		Cast<ATeyonPongGameModeBase>(GetWorld()->GetAuthGameMode())->Goal(goal->playerdId);
	}
	else
	{
		FVector velocity = mesh->GetPhysicsLinearVelocity();
		velocity.Z = -velocity.Z * bounceSpeedBoostMultiplier;
		mesh->SetPhysicsLinearVelocity(velocity);
	}

}

