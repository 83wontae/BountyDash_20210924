// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BountyDash.h"
#include "Components/StaticMeshComponent.h"
#include "BountyDashObject.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class BOUNTYDASH_API ACoin : public ABountyDashObject
{
	GENERATED_BODY()

public:
	ACoin();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void MyOnActorBeginOverlap(AActor* OverlappedActor, AActor* otherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

public:
	bool BeingPulled;
};
