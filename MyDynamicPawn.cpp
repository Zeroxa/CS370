// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDynamicPawn.h"

// Sets default values
AMyDynamicPawn::AMyDynamicPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	OurVisibleComponent->SetupAttachment(RootComponent);

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera -> SetupAttachment(RootComponent);

	OurCamera->SetRelativeLocation(FVector(-500.0f, 0.0f, 350.0f));
	OurCamera->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

	bGrowing = true;
	bZooming = true;
	zoomRate = 40.0f;

}

// Called when the game starts or when spawned
void AMyDynamicPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyDynamicPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float CurrentScale = OurVisibleComponent->GetComponentScale().X;

	if (bGrowing)
	{
		CurrentScale += DeltaTime;
	}
	else
	{
		CurrentScale -= (DeltaTime * 0.5f);
	}

	CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 3.0f);
	OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));

	FVector camLocation = OurCamera->GetRelativeTransform().GetLocation();
	FVector objLocation = OurVisibleComponent->GetRelativeTransform().GetLocation();
	FVector direction = (camLocation - objLocation).GetSafeNormal();

	float zoomDistance = zoomRate * DeltaTime;
    
	float distance = (camLocation - objLocation).Size();
	float minDistance = 250.0f;
	float maxDistance = 1000.0f;
	distance = FMath::Clamp(distance, minDistance, maxDistance);

	// Check if camera is too close or too far before updating its location
	if ((bZooming && distance > minDistance) || (!bZooming && distance < maxDistance))
	{
		if (bZooming)
		{
			camLocation -= direction * zoomDistance; // Zoom in
		}
		else
		{
			camLocation += direction * zoomDistance; // Zoom out
		}
	}

	OurCamera->SetRelativeLocation(camLocation);
    
	// Display messages
	FString DebugStringGrowing = "Growing: " + FString(bGrowing ? "True" : "False") + ", Scale: " + FString::SanitizeFloat(CurrentScale);
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Yellow, DebugStringGrowing);

	FString DebugStringZooming = "Zooming In: " + FString(bZooming ? "True" : "False") + ", Zoom Rate: " + FString::SanitizeFloat(zoomRate);
	GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Green, DebugStringZooming);

	FString DebugStringDistance = "Distance from Actor: " + FString::SanitizeFloat(distance);
	GEngine->AddOnScreenDebugMessage(3, 5.0f, FColor::White, DebugStringDistance);
}


// Called to bind functionality to input
void AMyDynamicPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

