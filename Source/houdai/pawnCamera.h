// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine.h"
#include "actorBullet.h"
#include "GameFramework/PlayerInput.h"
//
#include "pawnCamera.generated.h"

UCLASS()
class HOUDAI_API ApawnCamera : public APawn
{
	GENERATED_BODY()

public:
	ApawnCamera();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	float	m_valPadAnalogLX;
	float	m_valPadAnalogLY;
	float	m_valPadAnalogL2;
	bool	m_valPadTriggerL1;
	bool	m_valPadTriggerL2;

	float	m_valPadAnalogRX;
	float	m_valPadAnalogRY;
	float	m_valPadAnalogR2;
	bool	m_valPadTriggerR1;
	bool	m_valPadTriggerR2;

	void	funcPadAnalogLX( float val );
	void	funcPadAnalogLY( float val );
	void	funcPadAnalogL2( float val );
	void	funcPadTriggerL1();
	void	funcPadTriggerL2();

	void	funcPadAnalogRX( float val );
	void	funcPadAnalogRY( float val );
	void	funcPadAnalogR2( float val );
	void	funcPadTriggerR1();
	void	funcPadTriggerR2();


	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
    UCameraComponent* m_pCamera;

/*
	UFUNCTION(BlueprintCallable, Category = "fps")
	void MoveFB(float Value);
	UFUNCTION(BlueprintCallable, Category = "fps")
	void MoveRL(float Value);
	UFUNCTION(BlueprintCallable, Category = "fps")
	void MoveUD(float Value);
	UFUNCTION(BlueprintCallable, Category = "fps")
	void TurnUD(float Value);
	UFUNCTION(BlueprintCallable, Category = "fps")
	void TurnRL(float Value);
*/
public:
	void reqInput( float valRX, float valRY, float valLX, float valLY,  float valR2,  float valL2, bool flgR1, bool flgR2, bool flgR3, bool flgL1, bool flgL2, bool flgL3 );

	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	UStaticMeshComponent*	pCompMesh1;

};
