// Fill out your copyright notice in the Description page of Project Settings.


#include "SomaProject/Public/InteractObject.h"

// Sets default values
AInteractObject::AInteractObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh_Drawer = CreateDefaultSubobject<UStaticMeshComponent>("Drawer");
	Mesh_Cupboard_RightDoor = CreateDefaultSubobject<UStaticMeshComponent>("Cupboard_RightDoor");
	Mesh_Cupboard_LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>("Cupboard_LeftDoor");
	Mesh_Note = CreateDefaultSubobject<UStaticMeshComponent>("Note");

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

bool AInteractObject::EventInteract_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("COUCOU"));
	return true;
}

