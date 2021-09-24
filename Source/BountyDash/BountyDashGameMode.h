// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BountyDash.h"
#include "GameFramework/GameMode.h"
#include "BountyDashGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOUNTYDASH_API ABountyDashGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	UPROPERTY()
	float gameSpeed;

	UPROPERTY()
	int32 gameLevel;

public:
	ABountyDashGameMode();

	void CharScoreUp(unsigned int charScore);

	UFUNCTION()
	float GetInGameSpeed();

	UFUNCTION()
	float GetGameSpeed();

	UFUNCTION()
	float GetGameLevel();

	void ReduceGameSpeed();

	UFUNCTION()
	virtual void Tick(float DeltaSeconds) override;

	float GetRunTime();

	UFUNCTION()
	bool GetGameOver();

	UFUNCTION()
	void GameOver();

	UFUNCTION()
	void SetGamePaused(bool gamePaused);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 numCoinsForSpeedIncrease;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 gameSpeedIncrease;

	UPROPERTY()
	float RunTime;

	UPROPERTY()
	bool bGameOver;

	UPROPERTY()
	bool startGameOverCount;

	UPROPERTY()
	float timeTillGameOver;

	UPROPERTY()
	float gameOverTimer;
};
