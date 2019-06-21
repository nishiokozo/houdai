// Fill out your copyright notice in the Description page of Project Settings.

#include "ctrlInput.h"


//------------------------------------------------------------------------------
void ActrlInput::GetAllActorsOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors)
//------------------------------------------------------------------------------
{
	QUICK_SCOPE_CYCLE_COUNTER(UGameplayStatics_GetAllActorsOfClass);
	OutActors.Reset();

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	// We do nothing if no is class provided, rather than giving ALL actors!
	if (ActorClass && World)
	{
		for(TActorIterator<AActor> It(World, ActorClass); It; ++It)
		{
			AActor* Actor = *It;
			if(!Actor->IsPendingKill())
			{
				OutActors.Add(Actor);
			}
		}
	}

//	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

}
extern	float	g_time_prev;
extern	float	g_time_base;
extern	int		g_cntRoute;
extern	float	g_timeRoute[];
extern	char	g_charRoute[];


//------------------------------------------------------------------------------
void ActrlInput::flush()
//------------------------------------------------------------------------------
{
	//測定表示
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Yellow,TEXT("--"));
//	float t = g_time_prev - g_time_base;
	for(int i = 0 ; i < g_cntRoute ; i++)
	{
		float t = g_timeRoute[i] - g_time_base;
		GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString::Printf(TEXT("tick%d>%-6.1fms %c"),i,(t * 1000),g_charRoute[i]));
	}
	//測定開始
	g_cntRoute = 0;
	g_time_prev = g_time_base;
	g_time_base = GetWorld()->GetTimeSeconds();

}

//------------------------------------------------------------------------------
void ActrlInput::mark(char c)
//------------------------------------------------------------------------------
{
	if(g_cntRoute < 10)
	{
		g_timeRoute[g_cntRoute] = GetWorld()->GetTimeSeconds();g_charRoute[g_cntRoute++] = c;
	}
}


//------------------------------------------------------------------------------
ActrlInput::ActrlInput()
//------------------------------------------------------------------------------
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("'R'to SPawn")));

	g_time_prev = 0;
	g_time_base = 0;
	g_cntRoute = 0;

}

static	bool flgOnece = false;
//------------------------------------------------------------------------------
void ActrlInput::BeginPlay()
//------------------------------------------------------------------------------
{
	idxActor = 0;
	flgOnece = false;

}

//------------------------------------------------------------------------------
void ActrlInput::Tick( float DeltaTime )
//------------------------------------------------------------------------------
{
	Super::Tick(DeltaTime);
	extern int g_cntRoute; extern float g_timeRoute[]; extern char g_charRoute[]; if (g_cntRoute < 10) { g_timeRoute[g_cntRoute] = GetWorld()->GetTimeSeconds(); g_charRoute[g_cntRoute++] = 'I'; }

	if (!GetWorld())
	{
		ensureAlwaysMsgf(false, TEXT("%s"), *FString(TEXT("error GetWorld")).GetCharArray().GetData());
	}

	if (flgOnece == false)
	{
		flgOnece = true;
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Actor" + FString::Printf(TEXT(">spawn"))));
		float x = 0;
		float y = 0;
		FTransform pos = FTransform(FRotator(0, 0, 0), FVector(x, y, 500));
		UWorld* pWorld = GetWorld();
		if (pWorld)
		{
			FActorSpawnParameters param;
			param.Owner = this;
			param.Instigator = Instigator;
			AactorHoudai* p = pWorld->SpawnActor<AactorHoudai>(AactorHoudai::StaticClass(), pos, param);
		}
		else
		{
			ensureAlwaysMsgf(false, TEXT("%s"), *FString(TEXT("error GetWorld 2")).GetCharArray().GetData());
		}

	}
	



	// アクターリストを作成
	GetAllActorsOfClass(GetWorld(), AactorHoudai::StaticClass(), tblActor);
	if ( idxActor >= tblActor.Num() )
	{
		idxActor = 0;
	}







/*
		for ( auto a: tblActor )
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("name>"+ a->GetName()  ) );
		}
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("num>%d"),tblActor.Num() ) );
*/

/*
	PlayerInput
	// ActionMappingsをループ
	for ( FInputActionKeyMapping map: PlayerInput->ActionMappings )
	{
		FString str = map.ActionName.GetPlainNameString();
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT(">"+ str  ) );
	}
	for ( FInputAxisKeyMapping map: PlayerInput->AxisMappings )
	{
		FString str = map.AxisName.GetPlainNameString();
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT(">"+ str  ) );
	}
	
*/
/*
	if  ( PlayerInput->IsPressed(EKeys::T) )
	{
		GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,TEXT("ctrl delta" + FString::Printf(TEXT(">spawn"))));
		FTransform trans = RootComponent->GetComponentTransform();
		{
			FActorSpawnParameters inf;
			inf.Owner = this;
			inf.Instigator = Instigator;
			AactorMarker* p = GetWorld()->SpawnActor<AactorMarker>(AactorMarker::StaticClass(),trans,inf);

		}
	}

*/


/*
	// spawnアクター
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Spawn"));
	UWorld* pWorld = GetWorld();
	if (pWorld)
	{
		FTransform pos = pCompGun->GetComponentTransform();
		{
			FActorSpawnParameters inf;
			inf.Owner = this;
			inf.Instigator = Instigator;
			AactorBullet* p = pWorld->SpawnActor<AactorBullet>(classBullet, pos, inf);
			p->FireInDirection(pos.GetRotation().GetAxisZ());
		}
	}
*/


	float mx = PlayerInput->GetKeyValue(EKeys::MouseX);
	float my = PlayerInput->GetKeyValue(EKeys::MouseY);
	bool	ml = PlayerInput->IsPressed(EKeys::LeftMouseButton);
	bool	mm = PlayerInput->IsPressed(EKeys::MiddleMouseButton);
	bool	mr = PlayerInput->IsPressed(EKeys::RightMouseButton);
	bool	mU= PlayerInput->IsPressed(EKeys::W);
	bool	mD= PlayerInput->IsPressed(EKeys::S);
	bool	mR= PlayerInput->IsPressed(EKeys::D);
	bool	mL= PlayerInput->IsPressed(EKeys::A);

	nowLU	= PlayerInput->IsPressed(EKeys::Gamepad_DPad_Up);
	nowLD	= PlayerInput->IsPressed(EKeys::Gamepad_DPad_Down);
	nowLR	= PlayerInput->IsPressed(EKeys::Gamepad_DPad_Right);
	nowLL	= PlayerInput->IsPressed(EKeys::Gamepad_DPad_Left);
	nowL1	= PlayerInput->IsPressed(EKeys::Gamepad_LeftShoulder);
	nowL2	= PlayerInput->IsPressed(EKeys::Gamepad_LeftTrigger);
	nowL3	= PlayerInput->IsPressed(EKeys::Gamepad_LeftThumbstick);
	nowSE	= PlayerInput->IsPressed(EKeys::Gamepad_Special_Left);

	nowRU	= PlayerInput->IsPressed(EKeys::Gamepad_FaceButton_Top);
	nowRD	= PlayerInput->IsPressed(EKeys::Gamepad_FaceButton_Bottom);
	nowRR	= PlayerInput->IsPressed(EKeys::Gamepad_FaceButton_Right);
	nowRL	= PlayerInput->IsPressed(EKeys::Gamepad_FaceButton_Left);
	nowR1	= PlayerInput->IsPressed(EKeys::Gamepad_RightShoulder);
	nowR2	= PlayerInput->IsPressed(EKeys::Gamepad_RightTrigger);
	nowR3	= PlayerInput->IsPressed(EKeys::Gamepad_RightThumbstick);
	nowST	= PlayerInput->IsPressed(EKeys::Gamepad_Special_Right);

	nowR1  |= mr;
	nowR2  |= ml;
	nowR3  |= mm;



	downLU =  ( !prevLU && nowLU ) ;
	downLD =  ( !prevLD && nowLD ) ;
	downLR =  ( !prevLR && nowLR ) ;
	downLL =  ( !prevLL && nowLL ) ;
	downL1 =  ( !prevL1 && nowL1 ) ;
	downL2 =  ( !prevL2 && nowL2 ) ;
	downL3 =  ( !prevL3 && nowL3 ) ;
	downRU =  ( !prevRU && nowRU ) ;
	downRD =  ( !prevRD && nowRD ) ;
	downRR =  ( !prevRR && nowRR ) ;
	downRL =  ( !prevRL && nowRL ) ;
	downR1 =  ( !prevR1 && nowR1 ) ;
	downR2 =  ( !prevR2 && nowR2 ) ;
	downR3 =  ( !prevR3 && nowR3 ) ;
	downSE =  ( !prevSE && nowSE ) ;
	downST =  ( !prevST && nowST ) ;
		
	prevLU	= nowLU;
	prevLD	= nowLD;
	prevLR	= nowLR;
	prevLL	= nowLL;
	prevL1	= nowL1;
	prevL2	= nowL2;
	prevL3	= nowL3;
	prevSE	= nowSE;

	prevRU	= nowRU;
	prevRD	= nowRD;
	prevRR	= nowRR;
	prevRL	= nowRL;
	prevR1	= nowR1;
	prevR2	= nowR2;
	prevR3	= nowR3;
	prevST	= nowST;


	analogLX	= PlayerInput->GetKeyValue(EKeys::Gamepad_LeftX);
	analogLY	= PlayerInput->GetKeyValue(EKeys::Gamepad_LeftY);
	analogL2	= PlayerInput->GetKeyValue(EKeys::Gamepad_LeftTriggerAxis);

	analogRX	= PlayerInput->GetKeyValue(EKeys::Gamepad_RightX);
	analogRY	= PlayerInput->GetKeyValue(EKeys::Gamepad_RightY);
	analogR2	= PlayerInput->GetKeyValue(EKeys::Gamepad_RightTriggerAxis);

	analogLX	+= ((mL?-1.0f:0.0f)+(mR?1.0f:0.0f));
	analogLY	+= ((mD?-1.0f:0.0f)+(mU?1.0f:0.0f));
	analogRX	+= mx;
	analogRY	-= my;



	//カメラ操作切り替え
	if ( downRU )
	{
		isCamera = !isCamera;
	}
	//操作アクター切り替え
	if ( downRL )
	{
		idxActor++;
		if ( idxActor >= tblActor.Num() ) idxActor = 0;
	}

	//移動カメラ
	if ( isCamera )
	{
		ApawnCamera*	a = (ApawnCamera*)GetPawnOrSpectator();
		a->reqInput(  analogRX,  analogRY,  analogLX,  analogLY,   analogR2,   analogL2,  downR1,  downR2,  downR3,  downL1,  downL2,  downL3 );
	}
	//移動アクター
	else
	{
		if ( tblActor.Num() )
		{
			AactorHoudai*	a = (AactorHoudai*)tblActor[idxActor];
			a->reqInput(  analogRX,  analogRY,  analogLX,  analogLY,   analogR2,   analogL2,  downR1,  downR2,  downR3,  downL1,  downL2,  downL3 );
		}
	}


	if ( PlayerInput->WasJustPressed(EKeys::I))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("num " + FString::Printf(TEXT("%d"),tblActor.Num())));
	
	}
//発生
//	if (PlayerInput->IsPressed(EKeys::R))
	//if (PlayerInput->WasJustPressed(EKeys::R))
	if ( downL1  || PlayerInput->WasJustPressed(EKeys::R) || PlayerInput->IsPressed(EKeys::T))
	for ( int i = 0 ; i < 100 ; i++ )
	{
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Actor" + FString::Printf(TEXT(">spawn"))));
		float x = FMath::RandRange(-1200, 1200);
		float y = FMath::RandRange(-1200, 1200);
		float z = FMath::RandRange(500, 2000);
		float rz = FMath::RandRange(0, 360);
		FTransform pos = FTransform(FRotator(0, rz, 0), FVector(x, y, z));
		UWorld* pWorld = GetWorld();
		if (pWorld)
		{
			FActorSpawnParameters param;
			param.Owner = this;
			param.Instigator = Instigator;
			AactorHoudai* p = pWorld->SpawnActor<AactorHoudai>(AactorHoudai::StaticClass(), pos, param);
		}
	}

	{
		static float	prev =0;
		float now = 	GetWorld()->GetTimeSeconds();
		float s = 	prev - now;
//			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("ctrl delta"+FString::Printf(TEXT(" %f %f"),DeltaTime,s ) ));
//			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("mouse button"+FString::Printf(TEXT(" %d %d %d"),ml,mm,mr) ));
		prev = now;
	}

	//--- ポーズ
	#if ( UE_BUILD_SHIPPING )
#else
	// デバッグ機能：GamePause中はKeyBindが働かないのでTick内に書く
	if ( IsValid( GEngine ) )
	{
		bool bStep = PlayerInput->IsPressed(EKeys::Comma);
		Debug_bStepKeyHi = (bStep && !Debug_bStepKeyPrev);
		Debug_bStepKeyPrev = bStep;

		// デバッグ機能：コマ送り	
		if ( Debug_bStepKeyHi )
		{
			Debug_bInStep = true;
		}
		if ( Debug_bInStep )
		{
			if ( UGameplayStatics::IsGamePaused( this ))
			{
				UGameplayStatics::SetGamePaused( this, false );
			}
			else
			{
				GEngine->AddOnScreenDebugMessage( -1, 5.0f, FColor::Green, TEXT("Pause(,) exit(.)"));
				UGameplayStatics::SetGamePaused( this, true );
				Debug_bInStep = false;
			}
		}

		// デバッグ機能：コマ送り解除
		if ( PlayerInput->IsPressed(EKeys::Period) )
		{
			UGameplayStatics::SetGamePaused( this, false );
			Debug_bInStep = false;
		}

	}
#endif



}

