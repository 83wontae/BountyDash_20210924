// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BountyDash.h"
#include "BountyDashObject.h"
#include "PowerUpObject.h"
#include "BountyDashPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class BOUNTYDASH_API ABountyDashPowerUp : public ABountyDashObject
{
	GENERATED_BODY()
	
public:
	ABountyDashPowerUp();
protected:
	virtual void MyOnActorBeginOverlap(AActor* OverlappedActor, AActor* otherActor) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

private:
	class UPowerUpObject* PowerUp;
};
