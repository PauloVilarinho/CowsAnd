#pragma once
#include <string>
using int32 = int;
using FString = std::string; 

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	Ok,
	Not_isogram,
	Incorect_Length,
	Not_Lowercase,
	Invalid_Input

};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetMyCurrentTry() const;
	int32 GetMyHiddenWordLenth() const; 
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity (FString) const;

	void Reset(); //TODO make a more rich return value.
	//TODO make a more rich return value.

	// counts bulls and cows and increment turns # assuming valid guess
	
	FBullCowCount SubmitGuess(FString);
private:
	// see constructor for initialisation
	int32 MyMaxTries ;
	int32 MyCurrentTry ;
	FString MyHiddenWord ;
	
};