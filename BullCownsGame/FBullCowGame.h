#pragma once
#include <string>
class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int GetMaxTries() const;
	int GetMyCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value.
	bool CheckGuessValidity(std::string);//TODO make a more rich return value.
	

private:
	// see constructor for initialisation
	int MyMaxTries ;
	int MyCurrentTry ;
};