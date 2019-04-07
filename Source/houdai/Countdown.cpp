// Fill out your copyright notice in the Description page of Project Settings.

#include "Countdown.h"

//------------------------------------------------------------------------------
ACountdown::ACountdown()
//------------------------------------------------------------------------------
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = false;	//タイマー割り込みを使うのでtickは不要
	
	m_pText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	m_pText->SetHorizontalAlignment(EHTA_Center);
	m_pText->SetWorldSize(150.0f);
	RootComponent = m_pText;

	CountdownTime = 3;


}

//------------------------------------------------------------------------------
void ACountdown::BeginPlay()
//------------------------------------------------------------------------------
{
	Super::BeginPlay();

	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);	
}

//------------------------------------------------------------------------------
void ACountdown::Tick(float DeltaTime)
//------------------------------------------------------------------------------
{
	Super::Tick(DeltaTime);

}

//------------------------------------------------------------------------------
void ACountdown::UpdateTimerDisplay()
//------------------------------------------------------------------------------
{
    m_pText->SetText(FText::FromString(FString::FromInt(FMath::Max(CountdownTime, 0))));
}

//------------------------------------------------------------------------------
void ACountdown::AdvanceTimer()
//------------------------------------------------------------------------------
{
    --CountdownTime;
    UpdateTimerDisplay();
    if (CountdownTime < 1)
    {
        //カウントダウンを終了したのでタイマーの実行を停止します。
        GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
        CountdownHasFinished();
    }
}

//------------------------------------------------------------------------------
void ACountdown::CountdownHasFinished()
//------------------------------------------------------------------------------
{
    //特別な読み出しに変更
	const FString	str = FString(TEXT("Start!"));
	m_pText->SetText(FText::FromString(str));
}