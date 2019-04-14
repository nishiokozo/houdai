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


	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowLU;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowLD;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowLR;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowLL;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowL1;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowL2;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowL3;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowRU;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowRD;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowRR;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowRL;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowR1;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowR2;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowR3;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	nowSE;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
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

	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevLU;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevLD;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevLR;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevLL;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevL1;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevL2;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevL3;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevRU;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevRD;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevRR;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevRL;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevR1;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevR2;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevR3;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevSE;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		bool	prevST;



	void GetAllActorsOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors);

	UPROPERTY()	//	ガベージコレクション用に必要なのだとか
	TArray<AActor*>	tblActor;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
	int				idxActor;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
	bool			isCamera;

//	UStaticMeshComponent*	pCompMesh1;
//	InfInput	infCtrlInput;


//////// 測定用 ////////
private:
/*
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		float	g_time_prev;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		float	g_time_base;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		int		g_cntRoute;
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		float	g_timeRoute[100];
	UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
		int		g_charRoute[100];
*/
	//UPROPERTY()	//	ガベージコレクション用に必要なのだとか、ポインタでなくてもインスタンス複製時の挙動が変わるのだとか。
//		std::mt19937	rnd;

	void flush();
	void mark(char c);

		
};

