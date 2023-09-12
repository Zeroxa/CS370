#include "MyDynamicPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyDynamicPawn::AMyDynamicPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	RootComponent = OurVisibleComponent; // Set the Mesh component as the RootComponent

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(RootComponent); // Attach the camera component to our root component (which is the mesh)
	OurCamera->SetRelativeLocation(FVector(-500.0f, 0.0f, 350.0f)); // Set a default position for the camera
	OurCamera->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f)); // Set a default rotation for the camera

	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	RootComponent = OurVisibleComponent;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(RootComponent);
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

}

// Called to bind functionality to input
void AMyDynamicPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
