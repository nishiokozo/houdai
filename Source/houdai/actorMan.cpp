// Fill out your copyright notice in the Description page of Project Settings.

#include "actorMan.h"

//------------------------------------------------------------------------------
AactorMan::AactorMan()
//------------------------------------------------------------------------------
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//body
	{
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentationMan"));
		pCompBody= p;
		p->SetupAttachment(pCompMesh1);

		ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smBox"));
		if(mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
		}
		//
//		p->SetSimulatePhysics(true);
		p->SetRelativeLocation(FVector(0.0f,0.0f,-150.0f));
		p->SetWorldScale3D(FVector(0.4f,0.6f,0.2f));
	}

	//L1
	{
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentationManL1"));
		pCompLegL1 = p;
		p->SetupAttachment(pCompBody);

		ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smBox"));
		if(mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
		}
		//
//		p->SetSimulatePhysics(true);
		p->SetRelativeLocation(FVector(0.0f,60.0f,-210));
		p->SetWorldScale3D(FVector(0.3f,0.3f,0.2f));
	}

	//R1
	{
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentationManR1"));
		pCompLegR1 = p;
		p->SetupAttachment(pCompBody);

		ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smBox"));
		if(mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
		}
		//
//		p->SetSimulatePhysics(true);
		p->SetRelativeLocation(FVector(0.0f,-60.0f,-210));
		p->SetWorldScale3D(FVector(0.3f,0.3f,0.2f));
	}

	//L2
	{
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentationManL2"));
		pCompLegL2 = p;
		p->SetupAttachment(pCompLegL1);

		ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smBox"));
		if(mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
		}
		//
//		p->SetSimulatePhysics(true);
		p->SetRelativeLocation(FVector(0.0f,0.0f,-220.0f));
		p->SetWorldScale3D(FVector(0.3f,0.3f,0.2f));
	}

	//R2
	{
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentationManR2"));
		pCompLegR2 = p;
		p->SetupAttachment(pCompLegR1);

		ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smBox"));
		if(mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
		}
		//
//		p->SetSimulatePhysics(true);
		p->SetRelativeLocation(FVector(0.0f,0.0f,-220.0f));
		p->SetWorldScale3D(FVector(0.3f,0.3f,0.2f));
	}


}

//------------------------------------------------------------------------------
void AactorMan::BeginPlay()
//------------------------------------------------------------------------------
{
	Super::BeginPlay();
	
}

//------------------------------------------------------------------------------
void AactorMan::Tick(float DeltaTime)
//------------------------------------------------------------------------------
{
	Super::Tick(DeltaTime);
	extern int g_cntRoute;extern float g_timeRoute[];extern char g_charRoute[];if(g_cntRoute < 10) { g_timeRoute[g_cntRoute] = GetWorld()->GetTimeSeconds();g_charRoute[g_cntRoute++] = 'm'; }

}

