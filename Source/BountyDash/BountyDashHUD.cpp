// Fill out your copyright notice in the Description page of Project Settings.


#include "BountyDashHUD.h"
#include "BountyDashGameMode.h"
#include "BountyDashCharacter.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"

ABountyDashHUD::ABountyDashHUD()
{
	static ConstructorHelpers::FObjectFinder<UFont> OurHudFont(TEXT("/Game/BountyDash/BountyDashFont.BountyDashFont"));
	HUDFont = OurHudFont.Object;
}

void ABountyDashHUD::DrawHUD()
{
	Super::DrawHUD();

	FVector2D ScreenDimensins = FVector2D(Canvas->SizeX, Canvas->SizeY);

	ABountyDashCharacter* DashCharacter = Cast<ABountyDashCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	ABountyDashGameMode* DashGameMode = GetCustomGameMode<ABountyDashGameMode>(GetWorld());

	if (DashCharacter)
	{
		FString HUDString = FString::Printf(TEXT("Score: %d Runtime: %.4f CanSmash: %d"), DashCharacter->GetScore(), DashGameMode->GetRunTime(), DashCharacter->IsCanSmash());

		DrawText(HUDString, FColor::Yellow, 50, 50, HUDFont);
	}

	if (DashGameMode->GetGameOver())
	{
		FVector2D GameOverSize;
		GetTextSize(TEXT("GAME OVER!!! Press R to Restart!"), GameOverSize.X, GameOverSize.Y, HUDFont);

		DrawText(TEXT("GAME OVER!!! Press R to Restart!"), FColor::Yellow, (ScreenDimensins.X - GameOverSize.X) / 2.0f, (ScreenDimensins.Y - GameOverSize.Y) / 2.0f, HUDFont);

		DashGameMode->SetGamePaused(true);
	}
}
