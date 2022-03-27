// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"

#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Static,
	Sin
};

USTRUCT(BlueprintType)
struct FGeometryData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Amplitude = 50.f;
    UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 0.5f;
    UPROPERTY(EditAnywhere, Category = "Movement")
	EMovementType MoveType = EMovementType::Static;

	UPROPERTY(EditAnywhere, Category = "Design")
	FLinearColor Color = FLinearColor::Black;

    UPROPERTY(EditAnywhere, Category = "Design")
	float ChangeColorTimeRate = 3.0f;
};


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

	void SetColor(const FLinearColor& color);

private:
	void LogCharacterictics() const;
	void CustomLogCharacterictics() const;

	void MakeSomeTransformations();

	void HandleMovement();

	void OnChangeColorTimerFired();

public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere, Category = "Geometry Data")
	FGeometryData GeometryData;

protected:
	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsNum = 1;
	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	int32 KillsNum = 32;
	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 100.f;

	UPROPERTY(EditAnywhere, Category = "Health")
	bool IsDead = false;
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool HasWeapon = true;

	FRotator InitialRotation;

	FTimerHandle ChangeColorTimer;
	UPROPERTY(VisibleAnywhere, Category = "Color")
	int32 MaxChangesCount = 5;

	int32 CurrentChangesCount = 0;
};
