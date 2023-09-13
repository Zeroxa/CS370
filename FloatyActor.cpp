// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatyActor.h"

// Sets default values
AFloatyActor::AFloatyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	OurVisibleComponent->SetupAttachment(RootComponent);
	OurParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("VisualParticle"));
	OurParticleComponent ->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFloatyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatyActor::Tick(float DeltaTime)
{
	int random = rand() % 10;
	srand((unsigned) time(NULL));
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation(); // Get Current location of the actor
    FRotator NewRotation = GetActorRotation(); // Get Current rotation of the actor
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Z += DeltaHeight * factor*random;//Scale our height by a factor of 20
	NewLocation.X += DeltaHeight * factor*random;
	NewLocation.Y += DeltaHeight * factor*random;
    float DeltaRotation = DeltaTime * factor*3;    //Rotate by 20 degrees per second
    NewRotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(NewLocation, NewRotation);

	if (GEngine)

	{

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Location: %f,%f,%f"), NewLocation.X, NewLocation.Y, NewLocation.Z));

	}

}

