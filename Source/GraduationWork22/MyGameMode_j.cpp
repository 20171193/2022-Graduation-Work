// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode_j.h"
#include "Blueprint/UserWidget.h"

void AMyGameMode_j::BeginPlay()
{
	Super::BeginPlay();

	CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidget);
	CurrentWidget->AddToViewport();
}