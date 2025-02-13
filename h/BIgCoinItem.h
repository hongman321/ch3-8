// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoinItem.h"
#include "BIgCoinItem.generated.h"

/**
 *
 */
UCLASS()
class HONG_API ABIgCoinItem : public ACoinItem
{
	GENERATED_BODY()
public:
	ABIgCoinItem();
	virtual void ActivateItem(AActor* Activator) override;

};
