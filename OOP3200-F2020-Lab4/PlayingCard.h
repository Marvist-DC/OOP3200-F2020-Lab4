/** PlayingCard.h
 *
 *	This is a version of the PlayingCard class developed from OOP 2200.
 *
 *	@author		Thom MacDonald
 *	@author		Tom Tsiliopoulos
 *	@version	2020.10
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes.
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/


#pragma once
#ifndef __PLAYING_CARD__
#define __PLAYING_CARD__

#include <string>

class PlayingCard
{
public:
	/************************************************************************************
		 *	Static arrays of strings to represent the ranks and suits
		 ************************************************************************************/
	static const std::string CARD_RANK[]; // an array that holds the names of the ranks								
	static const std::string CARD_SUIT[]; // an array that holds the names of the suits
	static const int RANKS; // the number of ranks
	static const int SUITS; // the number of suits

	// by default, the card is a face up Ace of Hearts with a value of 1
	PlayingCard();

	// Parametrized constructors
	PlayingCard(const std::string& rank, const std::string& suit, int value = DEFAULT_VALUE_WANTED, bool face_up = true);
	PlayingCard(int rank_index, int suit_index, int value = DEFAULT_VALUE_WANTED, bool face_up = true);

	// Accessors		
	std::string GetRank() const { return CARD_RANK[myRankIndex]; } // gets rank name as a string
	std::string GetSuit() const { return CARD_SUIT[mySuitIndex]; } // gets suit name as a string
	int GetValue() const { return myValue; }   // gets the value of the card
	//string ToString() const; // convert the obj to a string.
	operator std::string() const; // convert the obj to a string.

	// Mutators
	void SetRank(int rank_index, bool update_value = true); // sets the rank by number
	void SetSuit(int suit_index); // sets the suit
	void SetRank(const std::string& rank, bool update_value = true); // sets the rank by number
	void SetSuit(const std::string& suit); // sets the suit
	void SetValue(int value = DEFAULT_VALUE_WANTED); // sets the value
	bool FlipCard() { return (IsFaceUp = !IsFaceUp); } // changes the face up state
													 // defined in-line
	//	Public member variables
	bool IsFaceUp; // true if face-up, false if face-down

private:

	int myRankIndex{}; // an int to represent the rank {1 - 13}
	int mySuitIndex{}; // an int to represent the suit (0 - 3}
	int myValue;   // an int to represent the 'value' of the card. 

	static const int DEFAULT_VALUE_WANTED = -999;

	// Private Methods - useful internally
	int GetDefaultValue() const; // gets the default value for the rank
};

#endif /* defined (__PLAYING_CARD__) */