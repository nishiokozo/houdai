// Fill out your copyright notice in the Description page of Project Settings.

#include "pawnCamera.h"

// Sets default values
//------------------------------------------------------------------------------
ApawnCamera::ApawnCamera()
//------------------------------------------------------------------------------
{
	PrimaryActorTick.bCanEverTick = true;
	if( GEngine )
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("start Camera"));
	}

	//カメラの生成　＆　アタッチ
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera(master)"));
	m_pCamera->SetupAttachment(RootComponent);


}

//------------------------------------------------------------------------------
void ApawnCamera::BeginPlay()
//------------------------------------------------------------------------------
{
	Super::BeginPlay();
	
}

//------------------------------------------------------------------------------
void ApawnCamera::Tick(float DeltaTime)
//------------------------------------------------------------------------------
{
	Super::Tick(DeltaTime);
extern int g_cntRoute;extern float g_timeRoute[];extern char g_charRoute[];if ( g_cntRoute <10 ) {g_timeRoute[g_cntRoute]=GetWorld()->GetTimeSeconds();g_charRoute[g_cntRoute++]='C';}

	{
		static float	prev =0;
		float now = 	GetWorld()->GetTimeSeconds();
		float s = 	prev - now;
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DeltaTime val"+FString::Printf(TEXT(" %f %f"),DeltaTime,s ) ));
		prev = now;
	}


}
//------------------------------------------------------------------------------
void ApawnCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)	//UPawn以上でないと
//------------------------------------------------------------------------------
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);


}


//------------------------------------------------------------------------------
void ApawnCamera::reqInput( float valRX, float valRY, float valLX, float valLY,  float valR2,  float valL2, bool flgR1, bool flgR2, bool flgR3, bool flgL1, bool flgL2, bool flgL3 )
//------------------------------------------------------------------------------
{

	#define	RATE	8.0f

	// move fb
	{

		FQuat	q = GetActorTransform().GetRotation();
		FVector l = GetActorTransform().GetLocation();
		FVector t = GetActorTransform().GetTranslation();


		FVector v = GetActorLocation();
		v += GetActorForwardVector() * (valR2-valL2)*RATE;
		SetActorLocation(v);

	}


	// move rl
	{

		FVector v = GetActorLocation();
		v += GetActorRightVector() * valLX*RATE ;
		SetActorLocation(v);

	}

	//move ud
	{

		FVector v = GetActorLocation();
		v += GetActorUpVector() * valLY*RATE ;
		SetActorLocation(v);

	}

	//turn ud
	{

		FQuat	q = GetActorTransform().GetRotation();
		FVector l = GetActorTransform().GetLocation();
		FVector t = GetActorTransform().GetTranslation();



		FRotator r = GetActorRotation();
		r.Pitch -= valRY;
		SetActorRotation(r);
	
	}

	//turn rl
	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("mx"+FString::Printf(TEXT(" %f"),Value ) ));

		FRotator r = GetActorRotation();
		r.Yaw += valRX;
		SetActorRotation(r);
	
	}
}

