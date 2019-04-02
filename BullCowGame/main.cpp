#include <iostream>
#include <string>
using namespace std;

//headers
void PrintIntro();
void PlayGame();
string GetGuess();
constexpr int WORLD_LENGHT = 5;

//app entry point
int main() {
	PrintIntro();

	PlayGame();

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