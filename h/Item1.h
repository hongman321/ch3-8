#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item1.generated.h"

UCLASS()
class HONG_API AItem1 : public AActor
{
	GENERATED_BODY()

public:
	AItem1();

protected:
	// Root Scene Component, �����Ϳ��� �� ���� �ְ� ���� �Ұ�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	// Static Mesh, �����Ϳ� Blueprint���� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	// ȸ�� �ӵ�, Ŭ���� �⺻���� ���� ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

	// �̵� �ӵ� �߰�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float MoveSpeed;

	FVector StartLocation;

	// �̵� ������ ��Ÿ���� �÷���
	bool bMovingForward;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// �Լ��� �������Ʈ���� ȣ�� �����ϵ��� ����
	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	// �������Ʈ���� ���� ��ȯ�ϵ��� ����
	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;

	// C++���� ȣ������� ������ �������Ʈ���� ����
	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUp();
};