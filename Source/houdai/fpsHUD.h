// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine.h"
//
#include "fpsHUD.generated.h"

/**
 * 
 */
UCLASS()
class HOUDAI_API AfpsHUD : public AHUD
{
	GENERATED_BODY()
protected:
    // This will be drawn at the center of the screen. (画面中央に描画) 
    UPROPERTY(EditDefaultsOnly)
    UTexture2D* CrosshairTexture;	

	public:
    // Primary draw call for the HUD. (HUD のプライマリ ドロー コール)
    virtual void DrawHUD() override;
};
