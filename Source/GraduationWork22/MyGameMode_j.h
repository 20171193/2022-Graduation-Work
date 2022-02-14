// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode_j.generated.h"

/**
 * 
 */
UCLASS()
class GRADUATIONWORK22_API AMyGameMode_j : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay()override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	UUserWidget* CurrentWidget;


	// 타입을 UUserWidget으로 제한
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	TSubclassOf<UUserWidget> HUDWidget;
};
