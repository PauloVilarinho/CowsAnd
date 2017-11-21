#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();
// Entry point of for our aplication
int main()
{
	do
	{
		PrintIntro();
		// Setting the  number of loops
		PlayGame();
		AskToPlayAgain();
	} while (AskToPlayAgain);
	return 0; // Exit Game 
}



void PrintIntro()
{
	// Introduce the Game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking off?\n";
	cout << endl;
	return ;
}

void PlayGame()
{
	constexpr int NUMBER_OF_LOOPS = 5;
	for (int count = 1; count <= NUMBER_OF_LOOPS; count++)
	{
		string Guess = GetGuess();
		cout << "your guess was:" << Guess<<endl;
		cout << endl;
	}
}

string GetGuess() 
{
	// get a guess from the player 
	string Guess = "";
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?";
	string response = "";
	getline(cin, response);
	bool PlayAgain = (response[0] == 'y') || (response[0] == 'Y');
	return PlayAgain;
}
