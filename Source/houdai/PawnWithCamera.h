// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine.h"
//
#include "PawnWithCamera.generated.h"

UCLASS()
class HOUDAI_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnWithCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	protected:
    UPROPERTY(EditAnywhere)
    USpringArmComponent* m_pSpringarm;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
    UCameraComponent* m_pCamera;

	//Input variables
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
	FVector2D MovementInput;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
	FVector2D CameraInput;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
	float ZoomFactor;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
	bool bZoomingIn;

	//Input functions
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);
	void ZoomIn();
	void ZoomOut();
};
