// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestCharacter_K.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
AMyTestCharacter_K::AMyTestCharacter_K()
{
	//ī�޶� ������ ����
	CameraBoom = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("cameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 800.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;


}