// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
//
#include "actorMarker.generated.h"

UCLASS()
class HOUDAI_API AactorMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AactorMarker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	USphereComponent* pCollision;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	UProjectileMovementComponent* pMovement;

};
