#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//All values initialized to 0. Struct member variables are public.
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	
	void Reset();// TODO make a more rich return value.
	FBullCowCount SubmitGuess(FString);

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	//se constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};