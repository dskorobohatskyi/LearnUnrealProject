// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGeometryActor.generated.h"

UCLASS()
class FIRSTPROJECT_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void LogCharacterictics() const;
	void CustomLogCharacterictics() const;


protected:
	int WeaponsNum = 1;
	int KillsNum = 32;
	float Health = 100.f;

	bool IsDead = false;
	bool HasWeapon = true;

};
