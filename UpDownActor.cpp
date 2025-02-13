

#include "UpDownActor.h"

AUpDownActor::AUpDownActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void AUpDownActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

}

void AUpDownActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedTime += DeltaTime * MoveSpeed;

	float Offset = FMath::Sin(ElapsedTime) * MaxRange;
	FVector NewLocation = StartLocation + FVector(0, 0, Offset);

	SetActorLocation(NewLocation);
}

