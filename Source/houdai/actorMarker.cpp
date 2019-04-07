// Fill out your copyright notice in the Description page of Project Settings.

#include "actorMarker.h"

//------------------------------------------------------------------------------
AactorMarker::AactorMarker()
//------------------------------------------------------------------------------
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//コリジョンの生成
	pCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	pCollision->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
//	pCollision->OnComponentHit.AddDynamic(this,&AactorBullet::callback_OnHit);
	pCollision->InitSphereRadius(15.0f);
	RootComponent = pCollision;

	//ムーブメントの生成
	pMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("pMovement"));
	pMovement->SetUpdatedComponent(pCollision);
	pMovement->InitialSpeed = 1000.0f;
	pMovement->MaxSpeed = 1000.0f;
	pMovement->bRotationFollowsVelocity = true;
	pMovement->bShouldBounce = true;
	pMovement->Bounciness = 0.3f;

	//マーカーモデルの読み込み
	{
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
		p->SetupAttachment(pCollision);
		ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smCylinder"));
		if(mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
			p->SetRelativeLocation(FVector(0.0f,0.0f,0.0f));
			p->SetWorldScale3D(FVector(0.2f));
		}
	}

}

//------------------------------------------------------------------------------
void AactorMarker::BeginPlay()
//------------------------------------------------------------------------------
{
	Super::BeginPlay();
	
}

//------------------------------------------------------------------------------
void AactorMarker::Tick(float DeltaTime)
//------------------------------------------------------------------------------
{
	Super::Tick(DeltaTime);
	extern int g_cntRoute;extern float g_timeRoute[];extern char g_charRoute[];if(g_cntRoute < 10) { g_timeRoute[g_cntRoute] = GetWorld()->GetTimeSeconds();g_charRoute[g_cntRoute++] = 'p'; }

}

