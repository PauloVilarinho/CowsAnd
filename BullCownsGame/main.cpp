#include <iostream>
#include <string>
#include "FBullCowGame.h"





void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // game instance

// Entry point of for our aplication
int main()
{
	bool bPlayAgain = false;
	do
	{
		int MaxTries = BCGame.GetMaxTries();

		PrintIntro();
		// Setting the  number of loops
		PlayGame();
		bPlayAgain=AskToPlayAgain();
	} while (bPlayAgain);
	return 0; // Exit Game 
}



void PrintIntro()
{
	// Introduce the Game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking off?\n";
	std::cout << std::endl;
	return ;
}

void PlayGame()
{
	BCGame.Reset();

	 int MaxTries = BCGame.GetMaxTries();
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "your guess was:" << Guess<<std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() 
{
	// get a guess from the player 
	int CurrentTry = BCGame.GetMyCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry <<  ". Enter your Guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::string response = "";
	std::getline(std::cin, response);
	bool PlayAgain = (response[0] == 'y') || (response[0] == 'Y');
	return PlayAgain;
}
