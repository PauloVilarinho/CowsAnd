#include "FBullCowGame.h"


int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetMyCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	constexpr int32 MY_MAX_TRIES = 8;
	MyMaxTries = MY_MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
// receives a Valid guess, increments turn, and return count 
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	
	//increment turn number
	MyCurrentTry++;
	//setup return value
	FBullCowCount BullCowCount;
	//loop through all letters
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		//compare letter against the hidden words
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			//if they match then
			if (Guess[i] == MyHiddenWord[j]) {
				BullCowCount.Bulls++; //increment bulls
			}
			else {
				BullCowCount.Cows++; //increment cows 
			}
				
				
		}
	}
	return BullCowCount;
}
