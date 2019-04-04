#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//All values initialized to 0. Struct member variables are public.
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();// TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.
	BullCowCount SubmitGuess(FString);

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	//se constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};