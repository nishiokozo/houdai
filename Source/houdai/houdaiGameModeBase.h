// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//
#include "houdaiGameModeBase.generated.h"

/*
extern	float	g_time_prev = 0;
extern	float	g_time_base = 0;
extern	int		g_cntRoute = 0;
extern	float	g_timeRoute[100];
extern	char	g_charRoute[100];
*/
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
