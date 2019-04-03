#include <iostream>
#include <string>
#include "FBullCowGame.h"

//headers
void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORLD_LENGHT = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I'm thinking off?\n";
	return;
}

std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	//get a guess from the player
	std::cout << "\nTry "<< CurrentTry <<". Enter your guess: \n";
	std::string Guess = "";
	getline(std::cin, Guess);

	return Guess;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	for (int count = 1; count <= MaxTries; count++) {
		std::string Guess = GetGuess();
		//repeat the guess back to them
		std::cout << "Your guess was: " + Guess + "\n";
	}

	//TODO add a game summary.
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}