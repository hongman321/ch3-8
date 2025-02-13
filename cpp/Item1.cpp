#include "Item1.h"

AItem1::AItem1()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	// Tick �Լ��� ���ݴϴ�.
	PrimaryActorTick.bCanEverTick = true;
	// �⺻ ȸ�� �ӵ� (1�ʿ� 90�� ȸ��)
	RotationSpeed = 90.0f;
	MoveSpeed = 500.0f;
}

void AItem1::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	SetActorRotation(FRotator(0.0f, 45.0f, 0.0f));
	// �������Ʈ���� ������ �Լ��� C++���� ȣ����
	OnItemPickedUp();
}

void AItem1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// RotationSpeed�� 0�� �ƴ϶�� ȸ�� ó��
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		// �ʴ� RotationSpeed��ŭ, �� �����Ӵ� (RotationSpeed * DeltaTime)��ŭ ȸ��
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	FVector CurrentLocation = GetActorLocation();
	float MaxX = StartLocation.X + 2200.0f;
	float MinX = StartLocation.X;
	// �̵� ���⿡ ���� X �� ����
	if (bMovingForward)
	{
		CurrentLocation.X += MoveSpeed * DeltaTime;
		if (CurrentLocation.X >= MaxX)
		{
			bMovingForward = false;
		}
	}
	else
	{
		CurrentLocation.X -= MoveSpeed * DeltaTime;
		if (CurrentLocation.X <= MinX)
		{
			bMovingForward = true;
		}
	}

	// ����� ��ġ ����
	SetActorLocation(CurrentLocation);
}

// BlueprintCallable �Լ� ����
void AItem1::ResetActorPosition()
{
	// (0, 0, 0) ��ġ�� �ǵ����ϴ�.
	SetActorLocation(FVector::ZeroVector);
}

float AItem1::GetRotationSpeed() const
{
	return RotationSpeed;
}