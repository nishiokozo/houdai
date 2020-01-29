// Fill out your copyright notice in the Description page of Project Settings.

#include "WriteActorLocationFunction.h"

#include "Engine.h"
#include <string>
#include <fstream>

auto UWriteActorLocationFunction::WriteLocation(AActor* Actor) -> bool
{

	if (!Actor) return false;
	FString filepath_str = FPaths::ProjectLogDir() / "ActorLocation.txt";
	const std::string filepath(TCHAR_TO_UTF8(*filepath_str));

	FString label_str = Actor->GetActorLabel();
	const std::string label(TCHAR_TO_UTF8(*label_str));
	FVector location = Actor->GetActorLocation();

	std::ofstream ostr(filepath, std::ios::app);
	ostr << label << ":"
		<< location.X << ","
		<< location.Y << ","
		<< location.Z << std::endl;

	return true;
}
