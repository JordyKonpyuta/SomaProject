// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "InteractObject.generated.h"

UCLASS()
class SOMAPROJECT_API AInteractObject : public AActor, public IInteractInterface
{
	GENERATED_BODY()

	UENUM(BlueprintType)
	enum EObjectType
	{
		Drawer UMETA(DisplayName="Drawer"),
		Cupboard UMETA(DisplayName="Cupboard"),
		Note UMETA(DisplayName="Note")
	};

	UPROPERTY(EditAnywhere, Category="Mesh")
	UStaticMeshComponent* Mesh_Drawer;
	UPROPERTY(EditAnywhere, Category="Mesh")
	UStaticMeshComponent* Mesh_Cupboard_RightDoor;
	UPROPERTY(EditAnywhere, Category="Mesh")
	UStaticMeshComponent* Mesh_Cupboard_LeftDoor;
	UPROPERTY(EditAnywhere, Category="Mesh")
	UStaticMeshComponent* Mesh_Note;

	UPROPERTY(EditAnywhere, BlueprintCallable, Category="Enum")
	TEnumAsByte<EObjectType> ObjectType;

	
public:	
	// Sets default values for this actor's properties
	AInteractObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool EventInteract_Implementation() override;

};
