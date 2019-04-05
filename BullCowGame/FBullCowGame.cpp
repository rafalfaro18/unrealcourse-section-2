#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	// if the guess isn't an isogram
	if (false) {
		return EWordStatus::Not_Isogram;
	}
	// if the guess isn't all lowercase
	else if (false) {
		return EWordStatus::Not_Lowercase;
	}
	// if the guess length is wrong
	else if (false) {
		return EWordStatus::Wrong_Lenght;
	}
	else {
		return EWordStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				// if they're in the same place
				if (MHWChar == GChar) {
					// increment bulls
					BullCowCount.Bulls++;
				} else {
					// increment cows
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
