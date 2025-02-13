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

	// Tick 함수를 켜줍니다.
	PrimaryActorTick.bCanEverTick = true;
	// 기본 회전 속도 (1초에 90도 회전)
	RotationSpeed = 90.0f;
	MoveSpeed = 500.0f;
}

void AItem1::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	SetActorRotation(FRotator(0.0f, 45.0f, 0.0f));
	// 블루프린트에서 구현한 함수를 C++에서 호출함
	OnItemPickedUp();
}

void AItem1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// RotationSpeed가 0이 아니라면 회전 처리
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		// 초당 RotationSpeed만큼, 한 프레임당 (RotationSpeed * DeltaTime)만큼 회전
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	FVector CurrentLocation = GetActorLocation();
	float MaxX = StartLocation.X + 2200.0f;
	float MinX = StartLocation.X;
	// 이동 방향에 따라 X 값 변경
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

	// 변경된 위치 적용
	SetActorLocation(CurrentLocation);
}

// BlueprintCallable 함수 구현
void AItem1::ResetActorPosition()
{
	// (0, 0, 0) 위치로 되돌립니다.
	SetActorLocation(FVector::ZeroVector);
}

float AItem1::GetRotationSpeed() const
{
	return RotationSpeed;
}