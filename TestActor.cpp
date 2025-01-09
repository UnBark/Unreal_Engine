#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false; // Tick ������� ����
    CurrentPosition = FVector2D(0, 0);    // ���� ��ġ (0, 0)
    TotalDistance = 0.0f;                 // �� �̵� �Ÿ� �ʱ�ȭ
    EventCount = 0;                       // �� �̺�Ʈ �߻� Ƚ�� �ʱ�ȭ
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    Move(); // ���� ���� �� 10�� �̵� ����
}

int32 AMyActor::RandomStep()
{
    return FMath::RandRange(0, 1); // 0 �Ǵ� 1�� ���� ��ȯ
}

bool AMyActor::RandomEvent()
{
    return FMath::RandRange(0, 1) == 1; // 50% Ȯ���� true �Ǵ� false ��ȯ
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
        int32 StepX = RandomStep(); // x�� �̵� �Ÿ�
        int32 StepY = RandomStep(); // y�� �̵� �Ÿ�

        CurrentPosition.X += StepX;
        CurrentPosition.Y += StepY;

        // ���� ���ܿ��� �̵� �Ÿ� ���
        float Distance = CalculateDistance(PreviousPosition, CurrentPosition);
        TotalDistance += Distance;

        // �̺�Ʈ �߻� ���� Ȯ��
        bool bEventOccurred = RandomEvent();
        if (bEventOccurred)
        {
            ++EventCount;
        }

        // ��ǥ �� �̵� �Ÿ�, �̺�Ʈ ���� ���
        UE_LOG(LogTemp, Warning, TEXT("Step %d: Current position: (%d, %d), Distance: %.2f, Event: %s"),
            i + 1,
            static_cast<int32>(CurrentPosition.X),
            static_cast<int32>(CurrentPosition.Y),
            Distance,
            bEventOccurred ? TEXT("Occurred") : TEXT("Not Occurred"));

        PreviousPosition = CurrentPosition; // ���� ��ġ ������Ʈ
    }

    // ���� ��� ���
    UE_LOG(LogTemp, Warning, TEXT("Total distance: %.2f"), TotalDistance);
    UE_LOG(LogTemp, Warning, TEXT("Total events occurred: %d"), EventCount);
}
