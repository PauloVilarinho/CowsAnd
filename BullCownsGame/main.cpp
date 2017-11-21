#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Introduce the Game
	constexpr int WORD_LENGTH = 5; 
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking off?\n";
	cout << endl;

	// get a guess from the player 
	string Guess = "";
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	// return the guess to the player
	cout << "Your guess was: " << Guess << endl;
	
	// get a guess from the player 
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	// return the guess to the player
	cout << "Your guess was: " << Guess << endl;


	
	return 0; 
}	