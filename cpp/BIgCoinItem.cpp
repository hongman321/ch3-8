#include "BigCoinItem.h"

ABIgCoinItem::ABIgCoinItem()
{
    // ���� CoinItem�� PointValue�� 50���� �����
    PointValue = 50;
    ItemType = "BigCoin";
}

void ABIgCoinItem::ActivateItem(AActor* Activator)
{
    // �θ��� �⺻ ���� ȹ�� ���� ���
    Super::ActivateItem(Activator);

    // �� ���θ��� �߰� ����(����Ʈ, ���� ��� ��)�� ���⼭ �߰��� �� ����
}