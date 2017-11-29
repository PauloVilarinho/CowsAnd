#include "FBullCowGame.h"


int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetMyCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetMyHiddenWordLenth() const {return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const { return bGameWon; }

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
	bGameWon = false;
	const FString HIDDEN_WORD = "piroca";
	MyHiddenWord = HIDDEN_WORD;
	constexpr int32 MY_MAX_TRIES = 8;
	MyMaxTries = MY_MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

// receives a Valid guess, increments turn, and return count 
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	//loop through all letters int the Hidden word
	int32 WordLength = MyHiddenWord.length();//assuming same length as guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		//compare letter against the Guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
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
	if (BullCowCount.Bulls = WordLength)
	{
		bGameWon = true;
	}
	else
	{
		bGameWon = false;
	}
	return BullCowCount;
}
