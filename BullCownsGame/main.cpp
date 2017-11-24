/*this is the console executable, that makes use of the bullcow Class
This acts as the view in a MVC pattern, an is responsible for all user interactions.
For Game logic ser FBullCownGame Class.

*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"



using FText = std::string;
using int32 = int; 


void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // game instance

// Entry point32 of for our aplication
int main()
{
	//bool bPlayAgain = false;
	do
	{
		int32 MaxTries = BCGame.GetMaxTries();

		PrintIntro();
		// Setting the  number of loops
		PlayGame();
		
	} while (AskToPlayAgain());
	return 0; // Exit Game 
}




void PrintIntro()
{
	// Introduce the Game
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking off?\n";
	std::cout << std::endl;
	return ;
}

void PlayGame()
{
	BCGame.Reset();

	 int32 MaxTries = BCGame.GetMaxTries();
	 //loop for number of turns asking for guess
	 //TODO change from FOR to WHILE when we are validating tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO make loop check if valid

		//submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess); 
		//print number of cows and bulls 
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}

	// TODO summarise game 
}

FText GetGuess() 
{
	// get a guess from the player 
	int32 CurrentTry = BCGame.GetMyCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry <<  ". Enter your Guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText response = "";
	std::getline(std::cin, response);
	bool PlayAgain = (response[0] == 'y') || (response[0] == 'Y');
	return PlayAgain;
}
