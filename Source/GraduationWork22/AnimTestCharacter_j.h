// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimTestCharacter_j.generated.h"

UCLASS()
class GRADUATIONWORK22_API AAnimTestCharacter_j : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimTestCharacter_j();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* CameraSpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* CameraComponent;

	UFUNCTION()
	void MoveForward(float value);
	
	UFUNCTION()
	void MoveRight(float value);
	
	UFUNCTION()
	void StartJump();
	
	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void ActRoll(float value);

	UFUNCTION()
	void Sit();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool isSit;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float sprintSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float maxStamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float currentStamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool sprintAble;

private:

protected:
	void Sprint();
	void StopSprinting();

	void ConsumeStamina();

	// 탈진상태 회복모드 / 그 외 회복모드
	void RecoverStamina();

	FTimerHandle consumeTH;
	FTimerHandle recoverTH;
	int callStaminaCount;

	// 스테미너 모두 소진 시 활용
	FTimerHandle waitHandle;
	int waitCount;
};
