// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f);

	InitialDirection = FVector(0.0f, 0.0f, 0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	InitialForce = FVector(50000000.f, 0.0f, 0.0f);
	InitialTorque = FVector(50000000.f, 0.0f, 0.0f);

	RunningTime = 0.f;
	A = 0.f;
	B = 0.f;
	C = 0.f;
	D = 0.f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation = GetActorLocation();

	/* Rand (FRand, FRandRange) */
	float InitialX = FMath::FRandRange(-500.f, 500.f);
	float InitialY = FMath::FRandRange(-500.f, 500.f);
	float InitialZ = FMath::FRandRange(0.f, 500.f);
	InitialLocation.X = InitialX;
	InitialLocation.Y = InitialY;
	InitialLocation.Z = InitialZ;

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(InitialLocation);
	}

	/* World vs Local (Offset, Rotation) */
	// FHitResult HitResult;
	// FVector Offset = FVector(200.f,0.0f,0.0f);
	// AddActorLocalOffset(Offset, true, &HitResult);
	// AddActorWorldOffset(Offset, true, &HitResult);
	// FRotator Rotation = FRotator(30.f, 0.0f, 0.0f);
	// AddActorLocalRotation(Rotation);
	// AddActorWorldRotation(Rotation);

	/* force & Torque (Offset, Rotation) */
	// StaticMesh->AddForce(InitialForce);
	// StaticMesh->AddTorque(InitialTorque);

	BaseZLocation = PlacedLocation.Z;
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bShouldFloat)
	{
		/* Physics */
		// FHitResult HitResult;
		// AddActorLocalOffset(InitialDirection, true, &HitResult);
		// FVector HitLocation = HitResult.Location;

		/* Sine Function */
		FVector NewLocation = GetActorLocation();
		NewLocation.Z = BaseZLocation + A * FMath::Sin(B * RunningTime - C) + D;

		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;
	}
}

/**
 * [ 클래스 삭제 방법 ] 
 * 헤더파일, cpp 삭제
 * 바이너리파일 작제
 * generate
 */
