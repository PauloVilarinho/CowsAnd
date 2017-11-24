#pragma once
#include <string>
using int32 = int;
using FString = std::string; 

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetMyCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value.
	bool CheckGuessValidity(FString);//TODO make a more rich return value.

	// counts bulls and cows and increment turns # assuming valid guess
	
	FBullCowCount SubmitGuess(FString);
private:
	// see constructor for initialisation
	int32 MyMaxTries ;
	int32 MyCurrentTry ;
	FString MyHiddenWord ;
	
};