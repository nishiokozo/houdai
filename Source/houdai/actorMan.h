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
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	UStaticMeshComponent*	pCompBody;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	UStaticMeshComponent*	pCompLegL1;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	UStaticMeshComponent*	pCompLegL2;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	UStaticMeshComponent*	pCompLegR1;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	UStaticMeshComponent*	pCompLegR2;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
