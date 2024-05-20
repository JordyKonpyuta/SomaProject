// Fill out your copyright notice in the Description page of Project Settings.


#include "SomaProject/Public/InteractObject.h"

#include "Kismet/GameplayStatics.h"
#include "SomaProject/SomaProjectCharacter.h"

// Sets default values
AInteractObject::AInteractObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void AInteractObject::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInteractObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractObject::EventInteract_Implementation()
{
	if (ASomaProjectCharacter* PlayerRef = Cast<ASomaProjectCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0)))
	{
		PlayerRef->PhysicsHandlerComp->GrabComponentAtLocation(Mesh, "None", GetActorLocation());
	}
}

