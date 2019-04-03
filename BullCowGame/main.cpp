#include <iostream>
#include <string>
using namespace std;

//headers
void PrintIntro();
void PlayGame();
string GetGuess();
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
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I'm thinking off?\n";
	return;
}

string GetGuess() {
	//get a guess from the player
	cout << "\nEnter your guess: \n";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

void PlayGame()
{
	for (int count = 1; count <= WORLD_LENGHT; count++) {
		string Guess = GetGuess();
		//repeat the guess back to them
		cout << "Your guess was: " + Guess + "\n";
	}
}

bool AskToPlayAgain() {
	cout << "Do you want to play again? (y/n) ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}