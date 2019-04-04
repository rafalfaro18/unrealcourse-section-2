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
FText GetGuess();
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

FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	//get a guess from the player
	std::cout << "\nTry "<< CurrentTry <<". Enter your guess: \n";
	FText Guess = "";
	getline(std::cin, Guess);

	return Guess;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// TODO change from FOR to WHILE loop when validating tries
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess(); // TODO loop-check valid guess

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}

	//TODO add a game summary.
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}