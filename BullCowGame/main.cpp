/* This is the console executable, that makes use of the BullCow class. 
This acts as a view in a MVC patter, and is responsible for all user interaction. 
For game logic see the FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//headers
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;//instantiate a new game.

//app entry point
int main() {
	do {
		system("CLS");
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

void PrintIntro() {
	//introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking off?\n";
	return;
}

// loop continuouslly until the user gives a valid guess
FText GetValidGuess() {
	//get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "\nTry "<< CurrentTry <<". Enter your guess: \n";
	FText Guess = "";
	getline(std::cin, Guess);

	EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

	switch (Status)
	{
	case EGuessStatus::OK:
		break;
	case EGuessStatus::Not_Isogram:
		break;
	case EGuessStatus::Wrong_Lenght:
		std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
		break;
	case EGuessStatus::Not_Lowercase:
		break;
	default:
		return Guess;
	}
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 count = 1; count <= MaxTries; count++) { // TODO change from FOR to WHILE loop when validating tries
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	//TODO add a game summary.
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}