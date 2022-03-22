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
	void ActRoll();

	UFUNCTION()
	void Sit();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool rollAble;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool sitAble;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float sprintSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float walkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool sprintAble;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float maxStamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float currentStamina;

	UFUNCTION(BlueprintCallable)
	float GetMaxStamina();

	UFUNCTION(BlueprintCallable)
	float GetCurrentStamina();

private:

protected:
	void Sprint();
	void StopSprinting();

	void ConsumeStamina();

	//
	void RecoverStamina();

	FTimerHandle consumeTH;
	FTimerHandle recoverTH;
	int callStaminaCount;

	//
	FTimerHandle waitHandle;
	int waitCount;
};
