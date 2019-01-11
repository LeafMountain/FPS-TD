#include "FGGameMode.h"
#include "Kismet/GameplayStatics.h"

void AFGGameMode::BeginPlay()
{
	// Set LifeCurrent to LifeMax to start with full health
	LifeCurrent = LifeMax;
	CurrentTime = MaxTimer;
}

void AFGGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AdjustTimer(-DeltaSeconds * TimerTimeScale);

	// Check if game is over
	if (LifeCurrent <= 0)
	{
		// Lose
		UE_LOG(LogTemp, Warning, TEXT("You LOSE!!"));
		ResetGame();
	}
	else if (CurrentTime <= 0)
	{
		// Win
		UE_LOG(LogTemp, Warning, TEXT("You WIN!! :D"));
		ResetGame();
	}
}

void AFGGameMode::ReduceLife()
{
	SetLife(GetCurrentLife() - 1);
	UE_LOG(LogTemp, Warning, TEXT("Current health set to %i"), GetCurrentLife());
}

void AFGGameMode::AddLife()
{
	SetLife(GetCurrentLife() + 1);
}

void AFGGameMode::SetLife(int Value)
{
	LifeCurrent = FMath::Clamp(Value, 0, LifeMax);
}

int AFGGameMode::GetCurrentLife()
{
	return LifeCurrent;
}

void AFGGameMode::ResetGame()
{
	ResetTimer();
	LifeCurrent = LifeMax;
	UGameplayStatics::OpenLevel(GetWorld(), "?Restart");
}

FText AFGGameMode::GetLifeUI()
{
	return FText::FromString(FString::FromInt(LifeCurrent));
}

FText AFGGameMode::GetTimeUI()
{
	return FText::FromString(FString::FromInt((int)CurrentTime));
}

void AFGGameMode::ResetTimer()
{
	CurrentTime = MaxTimer;
}

float AFGGameMode::GetTimeLeft()
{
	return CurrentTime;
}

void AFGGameMode::PauseToggle()
{
	// Pause game
	GetWorld()->GetFirstPlayerController()->SetPause(!GetWorld()->GetFirstPlayerController()->IsPaused());
}

void AFGGameMode::SetTimer(float Seconds)
{
	CurrentTime = Seconds;
}

void AFGGameMode::AdjustTimer(float Seconds)
{
	CurrentTime = FMath::Clamp(CurrentTime + Seconds, (float)0, MaxTimer);
}

void AFGGameMode::PauseTimer()
{
	SetTimerTimeScale(0);
}

void AFGGameMode::ResumeTimer()
{
	SetTimerTimeScale(1);
}

void AFGGameMode::SetTimerTimeScale(float Value)
{
	TimerTimeScale = Value;
}

float AFGGameMode::GetTimeLeftPercentage()
{
	return CurrentTime / MaxTimer;
}
