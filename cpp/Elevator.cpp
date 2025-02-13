


#include "Elevator.h"

AElevator::AElevator()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 500.0f;
	StartLocation = GetActorLocation();

}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	float MaxZ = StartLocation.Z + 280.0f;
	float MinZ = StartLocation.Z;
	// 이동 방향에 따라 Z 값 변경
	if (bMovingUp)
	{
		CurrentLocation.Z += MoveSpeed * DeltaTime;
		if (CurrentLocation.Z >= MaxZ)
		{
			bMovingUp = false;
		}
	}
	else
	{
		CurrentLocation.Z -= MoveSpeed * DeltaTime;
		if (CurrentLocation.Z <= MinZ)
		{
			bMovingUp = true;
		}
	}

	// 변경된 위치 적용
	SetActorLocation(CurrentLocation);
}

