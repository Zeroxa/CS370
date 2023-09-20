// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "MyDynamicPawn.generated.h"

UCLASS()
class PLAYINGWITHDELTATIME_API AMyDynamicPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyDynamicPawn();

	UPROPERTY(EditAnywhere, Category = "MyComponents")
	UStaticMeshComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere, Category = "MyCamera")
	UCameraComponent* OurCamera;

	UPROPERTY(EditAnywhere, Category = "Growth")
	bool bGrowing;

	UPROPERTY(EditAnywhere, Category = "CameraZoom")
	bool bZooming;

	UPROPERTY(EditAnywhere, Category = "CameraZoom", meta = (UIMin = "0.0", UIMax = "100.0"))
	float zoomRate;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
