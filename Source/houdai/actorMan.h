// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "actorHoudai.h"
#include "Engine.h"
//
#include "actorMan.generated.h"

UCLASS()
class HOUDAI_API AactorMan : public AactorHoudai
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AactorMan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	UStaticMeshComponent*	pCompBody;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	UStaticMeshComponent*	pCompLegL1;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	UStaticMeshComponent*	pCompLegL2;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	UStaticMeshComponent*	pCompLegR1;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	UStaticMeshComponent*	pCompLegR2;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
