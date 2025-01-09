#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false; // Tick 사용하지 않음
    CurrentPosition = FVector2D(0, 0);    // 시작 위치 (0, 0)
    TotalDistance = 0.0f;                 // 총 이동 거리 초기화
    EventCount = 0;                       // 총 이벤트 발생 횟수 초기화
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    Move(); // 엑터 스폰 시 10번 이동 시작
}

int32 AMyActor::RandomStep()
{
    return FMath::RandRange(0, 1); // 0 또는 1을 랜덤 반환
}

bool AMyActor::RandomEvent()
{
    return FMath::RandRange(0, 1) == 1; // 50% 확률로 true 또는 false 반환
}

float AMyActor::CalculateDistance(const FVector2D& Start, const FVector2D& End)
{
    return FMath::Sqrt(FMath::Pow(End.X - Start.X, 2) + FMath::Pow(End.Y - Start.Y, 2));
}

void AMyActor::Move()
{
    FVector2D PreviousPosition = CurrentPosition;

    UE_LOG(LogTemp, Warning, TEXT("Starting position: (%d, %d)"),
        static_cast<int32>(CurrentPosition.X),
        static_cast<int32>(CurrentPosition.Y));

    for (int32 i = 0; i < 10; ++i)
    {
        int32 StepX = RandomStep(); // x축 이동 거리
        int32 StepY = RandomStep(); // y축 이동 거리

        CurrentPosition.X += StepX;
        CurrentPosition.Y += StepY;

        // 현재 스텝에서 이동 거리 계산
        float Distance = CalculateDistance(PreviousPosition, CurrentPosition);
        TotalDistance += Distance;

        // 이벤트 발생 여부 확인
        bool bEventOccurred = RandomEvent();
        if (bEventOccurred)
        {
            ++EventCount;
        }

        // 좌표 및 이동 거리, 이벤트 여부 출력
        UE_LOG(LogTemp, Warning, TEXT("Step %d: Current position: (%d, %d), Distance: %.2f, Event: %s"),
            i + 1,
            static_cast<int32>(CurrentPosition.X),
            static_cast<int32>(CurrentPosition.Y),
            Distance,
            bEventOccurred ? TEXT("Occurred") : TEXT("Not Occurred"));

        PreviousPosition = CurrentPosition; // 이전 위치 업데이트
    }

    // 최종 결과 출력
    UE_LOG(LogTemp, Warning, TEXT("Total distance: %.2f"), TotalDistance);
    UE_LOG(LogTemp, Warning, TEXT("Total events occurred: %d"), EventCount);
}
