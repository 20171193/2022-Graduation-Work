// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliBox.h"
#include "MyTestActor_E.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
AColliBox::AColliBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AColliBox::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AColliBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColliBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColliBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AMyTestActor_E::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch"));
	}
	/*FTimerHandle WaitHandle;
	float WaitTime;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			FIre();
		}), WaitTime, false);**/
}

void AColliBox::FIre()
{
	FVector BoxLocation = GetActorLocation();
	FRotator BoxRotation = GetActorRotation();

	FVector MuzzleLocation = BoxLocation + FTransform(BoxLocation).TransformVector(MuzzleOffset);
	FRotator MuzzleRotation = BoxRotation;

	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		AProjectile_E* Projectile = World->SpawnActor<AProjectile_E>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
		if (Projectile)
		{
			FVector LaunchDirection = MuzzleRotation.Vector();
			Projectile->FireInDirection(LaunchDirection);
		}
	}

}

