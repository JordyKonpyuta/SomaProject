// Fill out your copyright notice in the Description page of Project Settings.


#include "Interact_Drawer.h"

#include "Kismet/GameplayStatics.h"
#include "SomaProject/SomaProjectCharacter.h"

// Sets default values
AInteract_Drawer::AInteract_Drawer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void AInteract_Drawer::BeginPlay()
{
	Super::BeginPlay();
	Origin = GetActorLocation();
	
}

// Called every frame
void AInteract_Drawer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetInteractAxis(Cast<ASomaProjectCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0))->InteractVector);
}

void AInteract_Drawer::EventInteract_Implementation()
{
	Cast<ASomaProjectCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0))->IsInteracting = true;
}

void AInteract_Drawer::GetInteractAxis(FVector MovementAxis)
{
	if (Cast<ASomaProjectCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0))->IsInteracting == true)
	{
		FVector NewLocation = GetActorLocation()+GetActorForwardVector()*(MovementAxis*5);
		NewLocation.Z = GetActorLocation().Z;
		
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("%s"), *NewLocation.ToString()));
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), ClampVector(NewLocation, Origin, GetActorLocation()+GetActorForwardVector()*(MovementAxis*20)), 1.0f,2.0f));
	}
}

