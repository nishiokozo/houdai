// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
//
#include "Countdown.generated.h"

UCLASS()
class HOUDAI_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
	int32 CountdownTime;

	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	UTextRenderComponent* m_pText;

void UpdateTimerDisplay();


void AdvanceTimer();

void CountdownHasFinished();

FTimerHandle CountdownTimerHandle;
};
