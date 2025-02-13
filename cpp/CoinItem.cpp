#include "CoinItem.h"
#include "Engine/World.h"
#include "SpartaGameState.h"

ACoinItem::ACoinItem()
{
    // ���� �⺻���� 0���� ����
    PointValue = 0;
    ItemType = "DefaultCoin";
}

void ACoinItem::ActivateItem(AActor* Activator)
{
    // �÷��̾� �±� Ȯ��

    if (Activator && Activator->ActorHasTag("Player"))
    {
        if (UWorld* World = GetWorld())
        {
            if (ASpartaGameState* GameState = World->GetGameState<ASpartaGameState>())
            {
                GameState->AddScore(PointValue);
                GameState->OnCoinCollected();
            }
        }
        // �θ� Ŭ���� (BaseItem)�� ���ǵ� ������ �ı� �Լ� ȣ��
        DestroyItem();
    }
}