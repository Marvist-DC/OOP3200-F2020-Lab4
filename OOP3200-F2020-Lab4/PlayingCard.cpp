#include "PlayingCard.h"
#include <stdexcept>	// for invalid_argument

// Static data member initialization
const std::string PlayingCard::CARD_SUIT[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
const std::string PlayingCard::CARD_RANK[] = { "Not Used", "Ace", "Two", "Three", "Four", "Five",
								"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const int PlayingCard::RANKS = 13;
const int PlayingCard::SUITS = 4;

// Class definition section (method definitions)

/** Parametrized Constructor for PlayingCard class
 *  @param value
 *  @param	rank_index: int (a number between 1 and 13)
 *  @param	suit_index: int (a number between 0 and 3)
 *  @param	face_up: bool (true if face-up, false if not)
 *	@throws	out_of_range exception if rank or suit params are invalid
 */
PlayingCard::PlayingCard(const int rank_index, const int suit_index, const int value, const bool face_up)
{
	// Set the rank and suit with validation
	SetRank(rank_index);
	SetSuit(suit_index);
	if (value == DEFAULT_VALUE_WANTED)
	{
		myValue = GetDefaultValue();
	}
	else
	{
		myValue = value;
	}
	// set the face-up field
	IsFaceUp = face_up;
}

// Default Constructor
PlayingCard::PlayingCard() : IsFaceUp(true), myRankIndex(1), mySuitIndex(1), myValue(1)
{
}

/** Parametrized Constructor for PlayingCard class
 *  @param	rank: string
 *  @param	suit: string
 *  @param value
 *  @param	face_up: bool (true if face-up, false if not)
 *	@throws	out_of_range exception if rank or suit params are invalid
 */
PlayingCard::PlayingCard(const std::string& rank, const std::string& suit, const int value, const bool face_up)
{
	// Set the rank and suit with validation
	SetRank(rank);
	SetSuit(suit);
	if (value == DEFAULT_VALUE_WANTED)
	{
		myValue = GetDefaultValue();
	}
	else
	{
		myValue = value;
	}
	// set the face-up field
	IsFaceUp = face_up;
}

/** SetRank Method for PlayingCard class
 *	Sets the rank of this PlayingCard object.
 *  @param	rank_index: int
 *  @param  update_value: bool (defaults to true)
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetRank(const int rank_index, const bool update_value)
{
	// if the parameter is valid
	if (rank_index > 0 && rank_index <= RANKS) // simple range check
	{
		// set myRankIndex to the rankIndex parameter
		myRankIndex = rank_index;

		// if update value parameter is true   
		if (update_value)
		{
			// set myValue to the default value
			myValue = GetDefaultValue();
		}
	}
	else // rank parameter is not valid
	{
		// throw an appropriate exception
		throw std::invalid_argument(std::to_string(rank_index) + " is not a recognized playing card rank.");
	}
}

/** SetRank Method for PlayingCard class
 *	Sets the rank of this PlayingCard object.
 *  @param	rank: string
 *  @param  update_value: bool (defaults to true)
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetRank(const std::string& rank, const bool update_value)
{
	auto valid = false; // is the parameter a valid rank
	auto rank_index = 1; 	// holds the index of the rank in the rank array if valid

	// for each possible rank until we find a match
	while (!valid && rank_index <= RANKS)
	{
		if (rank == CARD_RANK[rank_index])
		{
			valid = true; // a match was found
		}
		else
		{
			rank_index++; // next index
		}
	}

	// if the parameter is valid
	if (valid)
	{
		// set myRankIndex to the rankIndex found
		myRankIndex = rank_index;

		// if update value parameter is true   
		if (update_value)
		{
			// set myValue to the default value
			myValue = GetDefaultValue();
		}
	}
	else // rank parameter is not valid
	{
		// throw an appropriate exception
		throw std::invalid_argument(rank + " is not a recognized playing card rank.");
	}
}

/** SetSuit Method for PlayingCard class
 *	Sets the suit of this PlayingCard object.
 *  @param	suit_index: int
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetSuit(const int suit_index)
{
	// if the suit parameter is valid
	if (suit_index >= 0 && suit_index < SUITS)
	{
		// set mySuitIndex to the parameter
		mySuitIndex = suit_index;
	}
	else // suit parameter is not valid
	{
		// throw an appropriate exception
		throw std::invalid_argument(std::to_string(suit_index) + " is not a recognized playing card suit.");
	}
}

/** SetSuit Method for PlayingCard class
 *	Sets the suit of this PlayingCard object.
 *  @param	suit: string
 *	@throws	invalid_argument exception if the param is invalid
 */
void PlayingCard::SetSuit(const std::string& suit)
{
	bool valid = false; // is the parameter a valid rank
	int suitIndex = 0; 	// holds the index of the suit in the suit array if valid	

	// for each possible suit until we find a match
	while (!valid && suitIndex < SUITS)
	{
		if (suit == CARD_SUIT[suitIndex])
		{
			valid = true; // a match was found
		}
		else
		{
			suitIndex++; // next index
		}
	}

	// if the suit parameter is one of the valid suits
	if (valid)
	{
		// set mySuitIndex to the suitIndex found
		mySuitIndex = suitIndex;
	}
	else // suit parameter is not valid
	{
		// throw an appropriate exception
		throw std::invalid_argument(suit + " is not a recognized playing card suit.");
	}
}

/** SetValue Method for PlayingCard class
 *	Sets the suit of this PlayingCard object.
 *  @param	value: int (defaults to -999)
 */
void PlayingCard::SetValue(const int value)
{
	// if the value parameter is -999 the likely cause is that it defaulted to -999
	if (value == DEFAULT_VALUE_WANTED)
	{
		// set myValue to the default value
		myValue = GetDefaultValue();
	}
	else // value was specified
	{
		// set myValue to the parameter
		myValue = value;
	}
}

/** string Method for PlayingCard class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
PlayingCard::operator std::string() const
{
	// declare an empty string
	std::string card_string;

	// if the card is face-up
	if (IsFaceUp)
	{
		// build a descriptive string from the obj state
		card_string = CARD_RANK[myRankIndex] + " of " + CARD_SUIT[mySuitIndex] + " (" + std::to_string(myValue) + ")";
	}
	else // card is face-down
	{
		// string indicates face-down
		card_string = "Face-Down";
	}
	// return the string
	return card_string;
}

/** GetDefaultValue Method for PlayingCard class
 *	Determines and returns the default value for the card based on its rank.
 *	@return	the default value for the card.
 */
int PlayingCard::GetDefaultValue() const
{
	// set default value to 10
	int defaultValue = 10; // Ten, Jack, King, Queen

	// if rank is Ace or One through Nine 
	if (myRankIndex < defaultValue)
	{
		defaultValue = myRankIndex; // update default value accordingly

	}

	// return default value
	return defaultValue;
}