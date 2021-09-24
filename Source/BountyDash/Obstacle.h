// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BountyDash.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DestructibleComponent.h"
#include "BountyDashObject.h"
#include "Obstacle.generated.h"

UCLASS()
class BOUNTYDASH_API AObstacle : public ABountyDashObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	UDestructibleComponent* GetDestructable();

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDestructibleComponent* Mesh;
};
