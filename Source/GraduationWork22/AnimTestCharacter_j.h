// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimTestCharacter_j.generated.h"

UENUM(BlueprintType)
enum class EMoveMode : uint8
{
	normal,
	QuarterViewMode UMETA(DisplayName = "QuarterViewMode"),
	SideViewMode UMETA(DisplayName = "SideViewMode"),
	TopViewMode UMETA(DisplayName = "TopViewMode"),
	BackViewMode UMETA(DisplayName = "BackViewMode")
};

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* CameraSpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly)
	class USoundBase* SB_Jump;

public:

	UFUNCTION()
	void MoveForward(float value);
	
	UFUNCTION()
	void MoveRight(float value);
	
	UFUNCTION()
	void StartJump();
	
	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void Sit();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsIncreaseStamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsDeath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool rollAble;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool sitAble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsLadder2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool climbable2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPushing2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isInSwamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInCutScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsLoading;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float swampWalkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float swampSprintSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float sprintSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float walkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
	float pushSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Jump")
	float swampjumpZvelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement: Jump")
	float jumpZvelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool sprintAble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int playerHp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float maxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMoveMode currentMoveMode;

	UFUNCTION(BlueprintCallable)
	float GetMaxStamina();

	UFUNCTION(BlueprintCallable)
	float GetCurrentStamina();

	UFUNCTION(BlueprintCallable)
	void SetSwarmpMode(bool state);
protected:
	// 달리기 관련
	UFUNCTION()
	void Sprint();

	UFUNCTION()
	void StopSprinting();

	// 스테미너 관련
	UFUNCTION()
	void ConsumeStamina();

	UFUNCTION()
	void RecoverStamina();

	UPROPERTY()
	FTimerHandle consumeTH;
	
	UPROPERTY()
	FTimerHandle recoverTH;
	
	UPROPERTY()
	int callStaminaCount;

	
	// 스테미너 모두 소진 시 활용
	UPROPERTY()
	FTimerHandle waitHandle;
	
	UPROPERTY()
	int waitCount;
};
