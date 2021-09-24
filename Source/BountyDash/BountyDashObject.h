// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BountyDash.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "BountyDashObject.generated.h"

UCLASS()
class BOUNTYDASH_API ABountyDashObject : public AActor
{
	GENERATED_BODY()
	
public:
	float KillPoint;

public:	
	// Sets default values for this actor's properties
	ABountyDashObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetKillPoint(float point);
	float GetKillPoint();

protected:
	UFUNCTION()
	virtual void MyOnActorBeginOverlap(AActor* OverlappedActor, AActor* otherActor);

	UFUNCTION()
	virtual void MyOnActorEndOverlap(AActor* OverlappedActor, AActor* otherActor);

	UPROPERTY(EditAnywhere)
	USphereComponent* Collider;

public:	

};
