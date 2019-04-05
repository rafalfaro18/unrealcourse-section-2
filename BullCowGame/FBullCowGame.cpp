#pragma once
#include "FBullCowGame.h"
#include <map>

// make syntax Unreal like
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // this must be an Isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	// if the guess isn't all lowercase
	else if (!IsLowerCase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	// if the guess length is wrong
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Lenght;
	}
	else {
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	// loop all letters in the hidden word

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
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

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	// setup our map
	TMap<char, bool> LetterSeen;

	// loop all letters of the word
	for (auto Letter : Word) {
		Letter = tolower(Letter); // handle mixed case
		// if the letter is in the map
		if (LetterSeen[Letter]) {
			// we do NOT have an isogram
			return false;
		} else {
			// add the letter to the map as seen
			LetterSeen[Letter] = true;
		}
	}

	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word) {
		// if not a lowercase letter
		if (!islower(Letter)) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}
