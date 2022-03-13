// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BAI_K.generated.h"


UCLASS()
class GRADUATIONWORK22_API ABAI_K : public AAIController
{
	GENERATED_BODY()
	
public:
	ABAI_K();
//	virtual void OnPossess(APawn* InPawn) override;

	void RunAI();
	void StopAI();

private:
	UPROPERTY()
		class UBehaviorTree* BTAsset;

	UPROPERTY()
		class UBlackboardData* BBAsset;
};
