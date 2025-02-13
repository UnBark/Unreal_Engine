#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationgActor.generated.h"

UCLASS()
class SPARTAPROJECT_API ARotationgActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationgActor();

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed = 50.0f;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

};
