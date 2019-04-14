// Fill out your copyright notice in the Description page of Project Settings.

#include "houdaiGameModeBase.h"


#include "pawnCamera.h"
#include "ctrlInput.h"




//------------------------------------------------------------------------------
AhoudaiGameModeBase::AhoudaiGameModeBase()
//------------------------------------------------------------------------------
{
	PrimaryActorTick.bCanEverTick = true;

	//	TSubclassOf<class AfpsProjectile> m_classProjectile;

	DefaultPawnClass = ApawnCamera::StaticClass();
	PlayerControllerClass = ActrlInput::StaticClass();



}

//------------------------------------------------------------------------------
void AhoudaiGameModeBase::StartPlay()
//------------------------------------------------------------------------------
{
	Super::StartPlay();

	if(GEngine)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("" + FString::Printf(TEXT("[%s]"), *this->GetName())));
	}
	else
	{
		ensureAlwaysMsgf(false,TEXT("%s"),*FString(TEXT("error Hello World, this is FPSGameMode!")).GetCharArray().GetData());
	}
	if (GetWorld())
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("" + FString::Printf(TEXT("GetWorld[%s]"), *this->GetName())));
	}
	else
	{
		ensureAlwaysMsgf(false, TEXT("%s"), *FString(TEXT("error GetWorld")).GetCharArray().GetData());
	}




}

float	g_time_prev = 0;
float	g_time_base = 0;
int		g_cntRoute = 0;
float	g_timeRoute[100];
char	g_charRoute[100];



//------------------------------------------------------------------------------
void AhoudaiGameModeBase::Tick(float DeltaTime)
//------------------------------------------------------------------------------
{
	{
		//測定表示
		extern	float	g_time_base;
		extern int g_cntRoute;extern float g_timeRoute[];extern char g_charRoute[];
//		GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Yellow,TEXT("--"));
//		float t = g_time_prev - g_time_base;
		for(int i = 0 ; i < g_cntRoute ; i++)
		{
			float t = g_timeRoute[i] - g_time_base;
//			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString::Printf(TEXT("tick%d>%-6.1fms %c"),i,(t * 1000),g_charRoute[i]));
		}
		//測定開始
		g_cntRoute = 0;
		extern float g_time_prev;g_time_prev = g_time_base;
		extern float g_time_base;g_time_base = GetWorld()->GetTimeSeconds();
	}
	extern int g_cntRoute;extern float g_timeRoute[];extern char g_charRoute[];if(g_cntRoute < 10) { g_timeRoute[g_cntRoute] = GetWorld()->GetTimeSeconds();g_charRoute[g_cntRoute++] = 'B'; }

	//----



}
