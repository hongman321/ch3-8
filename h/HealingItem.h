// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "HealingItem.generated.h"

/**
 *
 */
UCLASS()
class HONG_API AHealingItem : public ABaseItem
{
	GENERATED_BODY()
public:
	AHealingItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
	float HealAmount;
	virtual void ActivateItem(AActor* Activator) override;
};
