// Fill out your copyright notice in the Description page of Project Settings.

#include "actorHoudai.h"

//#include "UMGSequencePlayer.h"
//#include "UserWidget.h"

class UUMGSequencePlayer;
class UWidgetAnimation;
class UUserWidget;
#include <random>

//------------------------------------------------------------------------------
AactorHoudai::AactorHoudai() 
//------------------------------------------------------------------------------
{
//	UE_LOG(LogShaders, Error, );
	//FMsg::Logf_Internal(nullptr, 0, TEXT("AAA"), ELogVerbosity::Verbosity, TEXT("(%d)!"), g_cnt);

	/*
{
		FILE *fp;
		if (!fopen_s(&fp, "c:\\ue4log.txt", "a"))
		{
			fprintf(fp, "test\n");
			fclose (fp);
		}
	}
*/


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
//	if ( GEngine ) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("AactorHoudai"));
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT(""+FString::Printf(TEXT("[%s]"), *this->GetName())));


#if 0
	// UE4.21.2だと土台移動ができなくなる
	{
		USceneComponent* p = CreateDefaultSubobject<USceneComponent>(TEXT("RootUSceneComponent"));
		RootComponent = p;
	}
	//砲台モデル
	{	
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
		pCompMesh1 = p;
		p->SetupAttachment(RootComponent);
#else
	//砲台モデル
	{	
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
		pCompMesh1 = p;
//		p->SetupAttachment(RootComponent);
		RootComponent = p;
#endif
	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smBox"));
		if (mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
		}
		//
		p->SetSimulatePhysics(true);
		p->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		p->SetWorldScale3D(FVector(0.5f));
	}
	//砲モデル
	{	
		UStaticMeshComponent* p = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ssssVisualRepresentation2"));
		pCompMesh2 = p;
		p->SetupAttachment(pCompMesh1);

		ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Game/models/smCylinder"));
		if (mesh.Succeeded())
		{
			p->SetStaticMesh(mesh.Object);
		}
		else
		{
	//		ensureAlwaysMsgf( false, TEXT("%s"), *FString(TEXT("ensureAlways output  test kozo")).GetCharArray().GetData() );
		}

		p->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));
		p->SetRelativeRotation(FRotator(-70.f, 00.f, 0.f));
		p->SetWorldScale3D(FVector(0.3f,0.3f,0.8f));

	}

	//射出口
	{
		USceneComponent* p = CreateDefaultSubobject<USceneComponent>(TEXT("ssssVisualRepresentation3"));
		pCompGun = p;	//　あること前提、ないとハングアップ
		p->SetupAttachment(pCompMesh2);

		p->SetRelativeLocation(FVector(0.0f,0.0f,160.0f));
		p->SetWorldScale3D(FVector(1.0f));	// サイズを引き継がない
	}

	//射出機構
	classBullet= AactorBullet::StaticClass();	//	あること前提、ないとハングアップ

	{
	//	FRotator r = FRotator(-70.f, 00.f, 0.f);
		//quatAim = r.Quaternion();
	}
	//	pCompSkeletalMesh->SetAnimationMode()
/*
	if (RootComponent)
	{
		if( GEngine ) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("ok RootComponent"));
	}
	else
	{
		if( GEngine ) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("no RootComponent"));
	}
*/
}
//------------------------------------------------------------------------------
UStaticMeshComponent*	searchMeshComponentByName( UStaticMeshComponent* pParent, FString name )
//------------------------------------------------------------------------------
{	
	for ( int i = 0; i < pParent->GetNumChildrenComponents(); i++ )
	{
		UStaticMeshComponent* p = Cast<UStaticMeshComponent>(pParent->GetChildComponent(i));
		if ( IsValid( p )  ) 
		{
			if ( p->GetName() == name ) return p;

			p = searchMeshComponentByName( p, name );
			if ( IsValid( p )  ) return p;

		}
	}
	return 0;
}
//------------------------------------------------------------------------------
USceneComponent*	searchSceneComponentByName( USceneComponent* pParent, FString name )
//------------------------------------------------------------------------------
{
	for ( int i = 0; i < pParent->GetNumChildrenComponents(); i++ )
	{
		USceneComponent* p = pParent->GetChildComponent(i);
		if ( IsValid( p )  ) 
		{
			if ( p->GetName() == name ) return p;

			p = searchSceneComponentByName( p, name );
			if ( IsValid( p )  ) return p;

		}
	}
	return 0;
}
//------------------------------------------------------------------------------
void AactorHoudai::BeginPlay()
//------------------------------------------------------------------------------
{
	Super::BeginPlay();
	UStaticMeshComponent* pRoot= (UStaticMeshComponent*)GetRootComponent();

}

//------------------------------------------------------------------------------
void AactorHoudai::Tick(float DeltaTime)
//------------------------------------------------------------------------------
{

	Super::Tick(DeltaTime);
extern int g_cntRoute;extern float g_timeRoute[];extern char g_charRoute[];if ( g_cntRoute <10 ) {g_timeRoute[g_cntRoute]=GetWorld()->GetTimeSeconds();g_charRoute[g_cntRoute++]='h';}

}

//------------------------------------------------------------------------------
void AactorHoudai::reqInput( float valRX, float valRY, float valLX, float valLY,  float valR2,  float valL2, bool flgR1, bool flgR2, bool flgR3, bool flgL1, bool flgL2, bool flgL3 )
//------------------------------------------------------------------------------
{
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("valLX"+FString::Printf(TEXT(" %f %f"),valRX,valLX ) ));


	#define	RATE	2.0f;
	//move FB
	{
		FVector v = GetActorLocation();
		v += GetActorForwardVector() * valLY*RATE ;
		SetActorLocation(v);
	}
	//move RL
	{
		FVector v = GetActorLocation();
		v += GetActorRightVector() * valLX*RATE ;
		SetActorLocation(v);
	}
#if 1


	//turn RL
	{
		FQuat	q = GetActorRotation().Quaternion();
		FQuat	d = FRotator(0, valRX, 0).Quaternion();
		q *= d;
//		SetActorRotation(q); //AActor
		RootComponent->MoveComponent(FVector::ZeroVector, q, true); //SceneComponent
//		RootComponent->MoveComponentImpl(FVector::ZeroVector, q, true); //SceneComponent

//		RootComponent->MoveComponentImpl(FVector::ZeroVector, q, true );
//		bool USceneComponent::MoveComponentImpl(const FVector& Delta, const FQuat& NewRotation, bool bSweep, FHitResult* OutHit, EMoveComponentFlags MoveFlags, ETeleportType Teleport)
	//	virtual bool MoveComponentImpl(const FVector& Delta, const FQuat& NewRotation, bool bSweep, FHitResult* Hit = NULL, EMoveComponentFlags MoveFlags = MOVECOMP_NoFlags, ETeleportType Teleport = ETeleportType::None);

	}
	//turn UD
	{
		FQuat	q = pCompMesh2->K2_GetComponentRotation().Quaternion();
		FQuat	d = FRotator(-valRY, 0, 0).Quaternion();
		q *= d;
		pCompMesh2->SetWorldRotation(q);
	}
#else
	//turn RL
	{
		FRotator r = GetActorRotation();
		r.Yaw += valRX;
		SetActorRotation(r);
	}
	//turn UD
	{
		FRotator	r = pCompMesh2->K2_GetComponentRotation();
		r.Pitch -= valRY;
		pCompMesh2->SetWorldRotation(r);
	}
#endif

	// fire
	if ( flgR2 )
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("fire"));
		UWorld* pWorld = GetWorld();
		if (pWorld)
		{
			FTransform transGun = pCompGun->GetComponentTransform();
			{
				FActorSpawnParameters inf;
				inf.Owner = this;
				inf.Instigator = Instigator;
				AactorBullet* p = pWorld->SpawnActor<AactorBullet>(classBullet,transGun,inf);
				p->FireInDirection(transGun.GetRotation().GetAxisZ());
			}
		}
	}

}