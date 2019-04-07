// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "actorBullet.h"
#include "Engine.h"
//
#include "actorHoudai.generated.h"

UCLASS()
class HOUDAI_API AactorHoudai : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AactorHoudai();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



//	float m_timeShot;
//	float m_tarRot;

/*
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void reqFire( float speed );
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void reqTurnRL( float speed );
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void reqTurnUD( float speed );
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void reqMoveFB( float val );
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void reqMoveRL( float val );
*/
	// Gun muzzle's offset from the camera location. 
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//FVector m_posFire;

	// Projectile class to spawn. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
//	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
	TSubclassOf<class AactorBullet> classBullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UStaticMeshComponent*	pCompMesh1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UStaticMeshComponent*	pCompMesh2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USceneComponent*	pCompGun;
//	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = Gameplay)
//	USkeletalMeshComponent*	pCompSkeletalMesh;

//	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
//	FQuat	quatAim;
//	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
//	FQuat	quatDir;


	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void reqInput( float valRX, float valRY, float valLX, float valLY,  float valR2,  float valL2, bool flgR1, bool flgR2, bool flgR3, bool flgL1, bool flgL2, bool flgL3 );


	
};
