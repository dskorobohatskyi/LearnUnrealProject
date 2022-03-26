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
	UPROPERTY(EditAnywhere, Category = "Weapon")
	int WeaponsNum = 1;
	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	int KillsNum = 32;
	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 100.f;

	UPROPERTY(EditAnywhere, Category = "Health")
	bool IsDead = false;
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool HasWeapon = true;

};
