#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TEST_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

private:
    FVector2D CurrentPosition; // 현재 좌표 (x, y)
    float TotalDistance;       // 총 이동 거리
    int32 EventCount;          // 총 이벤트 발생 횟수

    int32 RandomStep();        // 0 또는 1을 랜덤으로 반환
    bool RandomEvent();        // 50% 확률로 이벤트 발생 여부를 결정
    void Move();               // 10회 랜덤 이동
    float CalculateDistance(const FVector2D& Start, const FVector2D& End); // 두 점 사이의 거리 계산
};
