#include "Player.h"

int UPlayer::GetScore() const {
	return CurrentScore;
}

void UPlayer::AddScore(const int value) {
	CurrentScore += value;
}