// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

// Creation of custom log category
DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, Display, All)


// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	LogCharacterictics();
	CustomLogCharacterictics();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::LogCharacterictics() const
{
	UE_LOG(LogTemp, Verbose, TEXT("Smth boolean - %d"), false);
	UE_LOG(LogTemp, Warning, TEXT("Smth integer - %i"), -2);
	UE_LOG(LogTemp, Display, TEXT("Smth float - %.2f"), PI);

	UE_LOG(LogTemp, Error, TEXT("There's error - %s"), TEXT("You are fucked"));
}

void ABaseGeometryActor::CustomLogCharacterictics() const
{
    UE_LOG(LogBaseGeometry, Display, TEXT("Just a test"));
    UE_LOG(LogBaseGeometry, Error, TEXT("Just a error test"));

	UE_LOG(LogBaseGeometry, Display, TEXT("My Name is %s"), *GetName());

	FString Name = "Dima";
	FString Stat = FString::Printf(TEXT("The name - %s; Health - %.2f"), *Name, Health);
	UE_LOG(LogBaseGeometry, Warning, TEXT(" == %s =="), *Stat);


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Stat);
}

