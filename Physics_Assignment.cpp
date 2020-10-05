// Fill out your copyright notice in the Description page of Project Settings.


#include "Physics_Assignment.h"

// Sets default values
APhysics_Assignment::APhysics_Assignment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	//Starting velocity
	Movement->InitialSpeed = 10.0f;
	//Disable gravity
	Movement->ProjectileGravityScale = 0;
	angularVelocity.Y = 50;
	acceleration.X = 0.5;
}

// Called when the game starts or when spawned
void APhysics_Assignment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysics_Assignment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Anglular Velocity coordinates
	FQuat angVel(0, angularVelocity.X, angularVelocity.Y, angularVelocity.Z);
	//Linera motion
	position += velocity * DeltaTime + acceleration.X * DeltaTime * DeltaTime;
	velocity += acceleration * DeltaTime;
	//Rotational motion
	orientaion += (angVel * orientaion * (DeltaTime / 2));
	orientaion.Normalize();
	angVel = orientaion;
	APhysics_Assignment::SetActorRotation(orientaion);

}

