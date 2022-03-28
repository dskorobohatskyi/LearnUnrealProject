// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryHubActor.h"

// Sets default values
AGeometryHubActor::AGeometryHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();

    SpawnInDefaultWay();
    SpawnInDefferedWay();
}

void AGeometryHubActor::SpawnInDefaultWay()
{
    UWorld* World = GetWorld();
    if (World == nullptr)
    {
        return;
    }
    const int8 FiguresAmount = 9;
    for (size_t i = 0; i < FiguresAmount; i++)
    {
        const FVector Position = FVector(0, 300.f * i, 300.f);
        // The cubes are black by default
        ABaseGeometryActor* Geometry = World->SpawnActor<ABaseGeometryActor>(GeometryClass, Position, FRotator::ZeroRotator);
        if (Geometry)
        {
            Geometry->GeometryData.MoveType = FMath::RandBool() ? EMovementType::Sin : EMovementType::Static;
        }
    }
}

void AGeometryHubActor::SpawnInDefferedWay()
{
    UWorld* World = GetWorld();
    if (World == nullptr)
    {
        return;
    }

    const int8 FiguresAmount = 9;
    // Spawning with additional data
    for (size_t i = 0; i < FiguresAmount; i++)
    {
        const FTransform Transform = FTransform(FVector(0, 300.f * i, 700.f));
        // The cubes are black by default
        ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(GeometryClass, Transform);
        if (Geometry)
        {
            Geometry->GeometryData.Color = FLinearColor::Red;
            Geometry->FinishSpawning(Transform);
        }
    }
}

// Called every frame
void AGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

