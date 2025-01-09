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
    FVector2D CurrentPosition; // ���� ��ǥ (x, y)
    float TotalDistance;       // �� �̵� �Ÿ�
    int32 EventCount;          // �� �̺�Ʈ �߻� Ƚ��

    int32 RandomStep();        // 0 �Ǵ� 1�� �������� ��ȯ
    bool RandomEvent();        // 50% Ȯ���� �̺�Ʈ �߻� ���θ� ����
    void Move();               // 10ȸ ���� �̵�
    float CalculateDistance(const FVector2D& Start, const FVector2D& End); // �� �� ������ �Ÿ� ���
};
