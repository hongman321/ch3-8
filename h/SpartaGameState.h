// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpartaGameState.generated.h"

/**
 *
 */
UCLASS()
class HONG_API ASpartaGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	ASpartaGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	float LevelDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevels;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames;

	// Ÿ�̸� �ڵ�
	FTimerHandle LevelTimerHandle;
	FTimerHandle SpawnTimerHandle; //7�ʸ��� ������ �߰� ���� Ÿ�̸�
	FTimerHandle HUDUpdateTimerHandle;
	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	// ���� ���� ���� �Լ�
	void StartLevel();
	void OnCoinCollected();
	void OnLevelTimeUp();
	void EndLevel();
	void UpdateHUD();
	// ������ ���� �Լ�
	void SpawnItems(int32 ItemToSpawn, const TArray<AActor*>& FoundVolumes);
	void SpawnAdditionalItems();
};
