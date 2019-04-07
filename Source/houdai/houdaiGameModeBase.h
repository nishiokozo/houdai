// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//
#include "houdaiGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HOUDAI_API AhoudaiGameModeBase : public AGameModeBase//,UEngine
{
	GENERATED_BODY()

	AhoudaiGameModeBase();

	void StartPlay();

	void Tick(float DeltaTime);
	
};
