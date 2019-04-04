#pragma once
#include <string>

using FString = std::string;

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();// TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.
	// TODO provide a method for counting bulls & cows, and increase try #.


// ^^ Please try and ignore this and focus on the interface above ^^
private:
	//se constructor for initialization
	int MyCurrentTry;
	int MyMaxTries;
};