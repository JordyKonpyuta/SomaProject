// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "Interact_Drawer.generated.h"

UCLASS()
class SOMAPROJECT_API AInteract_Drawer : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteract_Drawer();

	FVector Origin = GetActorLocation();
	FVector MaxDistance = GetActorLocation()+GetActorForwardVector()*200;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EventInteract_Implementation() override;
	void GetInteractAxis(FVector2d MovementAxis);

};
