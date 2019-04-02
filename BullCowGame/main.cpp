#include <iostream>
#include <string>
using namespace std;

void PrintIntro() {
	//introduce the game
	constexpr int WORLD_LENGHT = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I'm thinking off?\n";
	return;
}

int main() {

	PrintIntro();

	//get a guess from the player
	cout << "\nEnter your guess: \n";
	string Guess = "";
	getline(cin, Guess);

	//repeat the guess back to them
	cout << "Your guess was: " << Guess << "\n";

	//get a guess from the player
	cout << "\nEnter your guess: \n";
	getline(cin, Guess);

	//repeat the guess back to them
	cout << "Your guess was: " << Guess << "\n";

	return 0;
}