#include "FBullCowGame.h"


int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetMyCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetMyHiddenWordLenth() const {return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)//if the guess isnt an isogram
	{
		return EGuessStatus::Not_isogram;
	}	
	else if (false)//if the guess isn't all lower case
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetMyHiddenWordLenth() )// if the guess length is wrong
	{
		return EGuessStatus::Incorect_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "piroca";
	MyHiddenWord = HIDDEN_WORD;
	constexpr int32 MY_MAX_TRIES = 8;
	MyMaxTries = MY_MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

// receives a Valid guess, increments turn, and return count 
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	
	//increment turn number
	MyCurrentTry++;
	//setup return value
	FBullCowCount BullCowCount;
	//loop through all letters
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		//compare letter against the hidden words
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++; //increment bulls
				}
				else {
					BullCowCount.Cows++; //increment cows 
				}
			}
				
		}
	}
	return BullCowCount;
}
