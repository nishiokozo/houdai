// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
//
#include "actorBullet.generated.h"

UCLASS()
class HOUDAI_API AactorBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AactorBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sphere collision component (Sphere collision コンポーネント)
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* pCollision;

    //Projectile movement component. (Projectile Movement コンポーネント)
    UPROPERTY(VisibleAnywhere, Category = Movement)
    UProjectileMovementComponent* pMovement;

	// Function that initializes the projectile's velocity in the shoot direction. (発射方向に発射物のべロシティを初期化する関数)
	void FireInDirection(const FVector& ShootDirection);

	// Function that is called when the projectile hits something. (発射物が何かにぶつかると呼び出される関数)
	UFUNCTION()
	void callback_OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

};
