// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WriteActorLocationFunction.generated.h"

/**
 * 
 */
UCLASS()
class WRITEACTORLOCATION_API UWriteActorLocationFunction : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "kozo")
		static bool WriteLocation(AActor* Actor);
};
