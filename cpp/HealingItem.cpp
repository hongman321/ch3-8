#include "HealingItem.h"
#include "SpartaCharacter.h"
AHealingItem::AHealingItem()
{
    HealAmount = 20.0f;
    ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
    if (Activator && Activator->ActorHasTag("Player"))
    {
        if (ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(Activator))
        {
            // ĳ������ ü���� ȸ��
            PlayerCharacter->AddHealth(HealAmount);
        }
        DestroyItem();
    }
}