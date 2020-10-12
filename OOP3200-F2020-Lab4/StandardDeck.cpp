/*
	Author: Domenic Catalano & Duy Tan Vu
	Date: Sunday, October 11, 2020
*/

#include "StandardDeck.h"

#include <ctime>
#include <iostream>

// Definition for the StandardDeck default contructor. It will set a member PlayingCard pointer to 0 (null).
// Then it will call the Initialize method
StandardDeck::StandardDeck()
{
	// Sets myDeck pointer to null (0) then calls the Initialize() method
	myDeck = nullptr;
	Initialize();
}

//  Definiton for the StandardDeck destructor. This will delete the array of cards
StandardDeck::~StandardDeck()
{
	// If the member pointer is not equal to zero, delete it
	if (myDeck != nullptr)
		delete[] myDeck;

	// Empty the array of cards
	myDeck = 0;
}

// Copy constructor copies the contents of the default contructor
StandardDeck::StandardDeck(const StandardDeck& other_deck)
{
	this->size = other_deck.size;
	this->myDeck = new PlayingCard[size];

	for (int i = 0; i < size; ++i)
	{
		this->myDeck[i] = other_deck.myDeck[i];
	}

	std::cout << "A deck has been copied.\n";
}

// Assignment operator overload
StandardDeck& StandardDeck::operator=(const StandardDeck& other_deck)
{
	this->size = other_deck.size;
	this->myDeck = new PlayingCard[size];

	for (int i = 0; i < size; ++i)
	{
		this->myDeck[i] = other_deck.myDeck[i];
	}
	return(*this);
}

// Definition for the CardsRemaining method. 
int StandardDeck::CardsRemaining()
{
	// Returns the current size of the deck
	return size;
}

// Definition for the DrawNextCard method. This will display the card on the top of the deck to the user
// then it will move every element of the array up one
PlayingCard StandardDeck::DrawNextCard()
{
	// Draws the card from the top of the deck
	PlayingCard firstCard = myDeck[0];

	// Removes the card from the deck and resizes the array
	RemoveCard(0);

	// Return the removed card
	return firstCard;
}

// Definition for the DrawRandomCard() method. This will return a random element of the myDeck array
PlayingCard StandardDeck::DrawRandomCard()
{
	int randomIndex = rand() % size;				// Selects a random number based off the size of the deck

	PlayingCard randomCard = myDeck[randomIndex];	// Takes the randomly selected card and sets it to the randomCard variable

	// Removed the random card from the deck and resizes the array
	RemoveCard(randomIndex);

	// Return the card of the randomly selected card
	return randomCard;
}

// Definition for the Shuffle() method. This will shuffle the contents of the array
void StandardDeck::Shuffle()
{
	// Seeds the random number
	srand(time(0));

	// Runs from index 0 to the maximum size of the array and swaps index positions
	for (int i = 0; i < size; i++)
	{
		// Random for remaining positions. 
		int r = i + (rand() % (size - i));

		std::swap(myDeck[i], myDeck[r]);
	}

	std::cout << "A shuffle has occured.\n";
}

// This method is used in conjuction with the RemoveCard() method. This simply resizes the array after a card has been removed
void StandardDeck::ResizeDeck(int newDeckSize)
{
	// Create a temp array to hold old array elements
	PlayingCard* newArray = new PlayingCard[newDeckSize];

	// Loop through the old array up until the new array maximum index 
	for (int i = 0; i < newDeckSize; ++i)
	{
		newArray[i] = myDeck[i];
	}

	// Reset the size of the new deck
	size = newDeckSize;

	// Delete old deck and assign new array to myDeck
	delete[] myDeck;
	myDeck = newArray;
}

// This method is used in conjuction with the ResizeDeck() method. This will shift the elements over, remove a card, resize the array, and then return the
// removed card to the user
void StandardDeck::RemoveCard(int cardIndex)
{
	// Move elements over to the left
	for (int i = cardIndex; i < size; i++)
	{
		myDeck[i] = myDeck[i + 1];
	}

	// Resize the array to accurately reflect the amount of cards remaining in the deck
	ResizeDeck(size - 1);
}

// Definition for the Initalize() method. This method will create and array and populate it with the 52 unique cards of a standard
// playing deck
void StandardDeck::Initialize()
{
	// Sets the size of the deck based off how many suits and ranks are in the PlayingCard.cpp
	int sizeOfDeck = PlayingCard::SUITS * PlayingCard::RANKS;	// (i.e. 13 x 4 = 52 cards)

	// If the pointer is not null, delete myDeck
	if (myDeck != nullptr)
		delete[] myDeck;

	// Create a new array utiizing the sizeOfDeck variable
	myDeck = new PlayingCard[sizeOfDeck];
	size = sizeOfDeck;

	// Populate the deck with every suit and rank
	for (int suit = 0, counter = 0; suit < PlayingCard::SUITS; ++suit)
	{
		for (int rank = 0; rank < PlayingCard::RANKS; ++rank)
		{
			// Sets the current index to a suit and rank and then increments the counter
			myDeck[counter].SetSuit(suit);
			myDeck[counter++].SetRank(1 + rank);
		}
	}
	std::cout << "A new deck has been successfully initialized.\n";
}
