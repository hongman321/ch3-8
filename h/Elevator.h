// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Elevator.generated.h"

UCLASS()
class HONG_API AElevator : public AActor
{
	GENERATED_BODY()

public:

	AElevator();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float MoveSpeed;
	FVector StartLocation;
	virtual void BeginPlay() override;
	bool bMovingUp;
public:

	virtual void Tick(float DeltaTime) override;

};
