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

	// 타이머 핸들
	FTimerHandle LevelTimerHandle;
	FTimerHandle SpawnTimerHandle; //7초마다 아이템 추가 스폰 타이머
	FTimerHandle HUDUpdateTimerHandle;
	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	// 게임 진행 관련 함수
	void StartLevel();
	void OnCoinCollected();
	void OnLevelTimeUp();
	void EndLevel();
	void UpdateHUD();
	// 아이템 스폰 함수
	void SpawnItems(int32 ItemToSpawn, const TArray<AActor*>& FoundVolumes);
	void SpawnAdditionalItems();
};
