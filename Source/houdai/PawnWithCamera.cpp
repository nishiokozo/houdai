// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnWithCamera.h"

// Sets default values
APawnWithCamera::APawnWithCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components (コンポーネントを作成)
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	m_pSpringarm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	m_pSpringarm->SetupAttachment(RootComponent);
	m_pSpringarm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	m_pSpringarm->TargetArmLength = 400.f;
	m_pSpringarm->bEnableCameraLag = true;
	m_pSpringarm->CameraLagSpeed = 3.0f;

	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	m_pCamera->SetupAttachment(m_pSpringarm, USpringArmComponent::SocketName);

	//Take control of the default Player (デフォルトプレイヤーをコントロール)
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APawnWithCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnWithCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		if (bZoomingIn)
		{
			ZoomFactor += DeltaTime / 0.5f;         //Zoom in over half a second
		}
		else
		{
			ZoomFactor -= DeltaTime / 0.25f;        //Zoom out over a quarter of a second
		}
		ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);
		//Blend our camera's FOV and our SpringArm's length based on ZoomFactor
		m_pCamera->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, ZoomFactor);
		m_pSpringarm->TargetArmLength = FMath::Lerp<float>(400.0f, 300.0f, ZoomFactor);
	}

	//Rotate our actor's yaw, which will turn our camera because we're attached to it
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.X;
		SetActorRotation(NewRotation);
	}

	//Rotate our camera's pitch, but limit it so we're always looking downward
	{
		FRotator NewRotation = m_pSpringarm->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.Y, -80.0f, -15.0f);
		m_pSpringarm->SetWorldRotation(NewRotation);
	}

	//Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!MovementInput.IsZero())
		{
			//Scale our movement input axis values by 100 units per second
//			MovementInput = MovementInput.SafeNormal() * 100.0f;
//			MovementInput = MovementInput.Normalize() * 100.0f;
			MovementInput = MovementInput.GetSafeNormal() * 100.0f;

			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime;
			NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
			SetActorLocation(NewLocation);
		}
	}

}


// Called to bind functionality to input
void APawnWithCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Hook up events for "ZoomIn"
InputComponent->BindAction("ActZoomIn", IE_Pressed, this, &APawnWithCamera::ZoomIn);
InputComponent->BindAction("ActZoomIn", IE_Released, this, &APawnWithCamera::ZoomOut);

//Hook up every-frame handling for our four axes
InputComponent->BindAxis("ActMoveFB", this, &APawnWithCamera::MoveForward);
InputComponent->BindAxis("ActMoveRL", this, &APawnWithCamera::MoveRight);
InputComponent->BindAxis("ActLookUD", this, &APawnWithCamera::PitchCamera);
InputComponent->BindAxis("ActLookRL", this, &APawnWithCamera::YawCamera);
}

//Input functions
void APawnWithCamera::MoveForward(float AxisValue)
{
    MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APawnWithCamera::MoveRight(float AxisValue)
{
    MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APawnWithCamera::PitchCamera(float AxisValue)
{
    CameraInput.Y = -AxisValue;
}

void APawnWithCamera::YawCamera(float AxisValue)
{
    CameraInput.X = AxisValue;
}

void APawnWithCamera::ZoomIn()
{
    bZoomingIn = true;
}

void APawnWithCamera::ZoomOut()
{
    bZoomingIn = false;
}
