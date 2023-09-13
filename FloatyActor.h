// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include<iostream>
#include<cstdlib>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "FloatyActor.generated.h"


UCLASS()
class PROJECT0_API AFloatyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatyActor();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* OurVisibleComponent;
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* OurParticleComponent;
	UPROPERTY(EditAnywhere, Category="BobbingAndRotatingFactor")
	float factor = 20.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
