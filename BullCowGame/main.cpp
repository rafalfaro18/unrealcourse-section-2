#include <iostream>
#include <string>

//headers
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
constexpr int WORLD_LENGHT = 5;

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
	std::cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I'm thinking off?\n";
	return;
}

std::string GetGuess() {
	//get a guess from the player
	std::cout << "\nEnter your guess: \n";
	std::string Guess = "";
	getline(std::cin, Guess);

	return Guess;
}

void PlayGame()
{
	for (int count = 1; count <= WORLD_LENGHT; count++) {
		std::string Guess = GetGuess();
		//repeat the guess back to them
		std::cout << "Your guess was: " + Guess + "\n";
	}
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}