#include "FBullCowGame.h"
#include <map>
#define Tmap std::map

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetMyCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetMyHiddenWordLenth() const {return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const { return bGameWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if ( !IsIsogram(Guess) )//if the guess isnt an isogram
	{
		return EGuessStatus::Not_isogram; //TODO write function
	}	
	else if ( !IsLowerCase(Guess) )//if the guess isn't all lower case
	{
		return EGuessStatus::Not_Lowercase; //TODO write function
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
	const FString HIDDEN_WORD = "planet";
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
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++; //increment bulls
				}
				else 
				{
					BullCowCount.Cows++; //increment cows 
				}
			}
				
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameWon = true;
	}
	else
	{
		bGameWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	// treat 0 and 1 letter words as lower case
	if (Word.length() <= 1) { return true; }
	
	for (auto Letter : Word) // for all letters of the word
	{
		if (Letter !=  tolower(Letter) ) // if not lower case
		{
			return false;
		}
	}//if all lower case
	return true;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }
	
	Tmap<char, bool> LetterSeen;// setup our map
	for (auto Letter : Word)//for all letters of the word
	{	
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {//if the letter is in the map
			return false;//we do NOT have an isogram
		} else {
			LetterSeen[Letter] = true;// add the letter to the map as seen
		}
	}



	return true;
}
