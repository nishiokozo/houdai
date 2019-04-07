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

	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
	int32 CountdownTime;

	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	UTextRenderComponent* m_pText;

void UpdateTimerDisplay();


void AdvanceTimer();

void CountdownHasFinished();

FTimerHandle CountdownTimerHandle;
};
