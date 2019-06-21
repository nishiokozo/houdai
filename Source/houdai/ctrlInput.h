// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine.h"
//
#include "actorHoudai.h"
#include "actorMarker.h"
#include "pawnCamera.h"
#include "houdaiGameModeBase.h"
//
#include "ctrlInput.generated.h"


UCLASS()
class HOUDAI_API ActrlInput: public APlayerController
{
	GENERATED_BODY()

	void BeginPlay();

	void Tick( float DeltaTime );

	//======================================================
	// �f�o�b�O�@�\�i�|�[�Y���R�}����j
	//======================================================
private:
	// �f�o�b�O�@�\�F�R�}����L�[�������ꂽ�u��
	bool	Debug_bStepKeyHi;
	// �f�o�b�O�@�\�F�R�}����L�[�̑O����
	bool	Debug_bStepKeyPrev;
	// �f�o�b�O�@�\�F�R�}���蒆�t���O
	bool	Debug_bInStep;


public:
	ActrlInput();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float	analogLX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float	analogLY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float	analogL2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float	analogRX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float	analogRY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float	analogR2;


	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowLU;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowLD;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowLR;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowLL;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowL1;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowL2;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowL3;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowRU;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowRD;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowRR;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowRL;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowR1;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowR2;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowR3;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowSE;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	nowST;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downLU;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downLD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downLR;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downLL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downL1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downL2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downL3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downRU;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downRD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downRR;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downRL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downR1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downR2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downR3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downSE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool	downST;

	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevLU;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevLD;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevLR;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevLL;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevL1;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevL2;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevL3;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevRU;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevRD;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevRR;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevRL;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevR1;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevR2;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevR3;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevSE;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		bool	prevST;



	void GetAllActorsOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors);

	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ�
	TArray<AActor*>	tblActor;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
	int				idxActor;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
	bool			isCamera;

//	UStaticMeshComponent*	pCompMesh1;
//	InfInput	infCtrlInput;


//////// ����p ////////
private:
/*
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		float	g_time_prev;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		float	g_time_base;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		int		g_cntRoute;
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		float	g_timeRoute[100];
	UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
		int		g_charRoute[100];
*/
	//UPROPERTY()	//	�K�x�[�W�R���N�V�����p�ɕK�v�Ȃ̂��Ƃ��A�|�C���^�łȂ��Ă��C���X�^���X�������̋������ς��̂��Ƃ��B
//		std::mt19937	rnd;

	void flush();
	void mark(char c);


		
};

