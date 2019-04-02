#include <iostream>
#include <string>
using namespace std;

//headers
void PrintIntro();
void PlayGame();
string GetGuessAndPrintBack();
constexpr int WORLD_LENGHT = 5;

//app entry point
int main() {
	PrintIntro();

	PlayGame();

	return 0;
}

void PlayGame()
{
	for (int count = 1; count <= WORLD_LENGHT; count++) {
		GetGuessAndPrintBack();
	}
}

void PrintIntro() {
	//introduce the game
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I'm thinking off?\n";
	return;
}

string GetGuessAndPrintBack() {
	//get a guess from the player
	cout << "\nEnter your guess: \n";
	string Guess = "";
	getline(cin, Guess);

	//repeat the guess back to them
	cout<< "Your guess was: " + Guess + "\n";

	return Guess;
}