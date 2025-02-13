#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedTime += DeltaTime * MoveSpeed;

	float Offset = FMath::Sin(ElapsedTime) * MaxRange;
	FVector NewLocation = StartLocation + FVector(Offset, 0, 0);

	SetActorLocation(NewLocation);

}

