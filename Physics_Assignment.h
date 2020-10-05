// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Math/Rotator.h"
#include "Math/Vector.h"
#include "Math/Quat.h"
#include "Physics_Assignment.generated.h"

UCLASS()
class PHYSICS_ENGINE_API APhysics_Assignment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysics_Assignment();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* Movement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector position;
	FVector rotation;
	FVector acceleration;
	FVector velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector angularVelocity;
	FQuat orientaion;
};
