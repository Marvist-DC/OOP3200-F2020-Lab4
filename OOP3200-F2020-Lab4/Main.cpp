/*
	Author: Domenic Catalano & Duy Tan Vu
	Date: Sunday, October 11, 2020
*/

#include <ctime>
#include <iostream>
#include "StandardDeck.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator

	// create a deck and show the deck object as initialized
	StandardDeck newDeck;
	std::cout << "Number of cards remaining: " << newDeck.CardsRemaining() << std::endl;
	Pause();

	// Draw the next card and show it
	std::cout << "Your first card is: " << (std::string)newDeck.DrawNextCard() << std::endl;
	std::cout << "Number of cards remaining: " << newDeck.CardsRemaining() << std::endl << std::endl;

	// Draw a random card and show it
	std::cout << "Your random card is: " << (std::string)newDeck.DrawRandomCard() << std::endl;
	std::cout << "Number of cards remaining: " << newDeck.CardsRemaining() << std::endl << std::endl;

	// Shuffle the deck and show the result
	newDeck.Shuffle();
	std::cout << "The first card after shuffling is: " << (std::string)newDeck.DrawNextCard() << std::endl;
	std::cout << "Number of cards remaining: " << newDeck.CardsRemaining() << std::endl << std::endl;

	// Create a new deck using copy contructor
	StandardDeck secondDeck = StandardDeck(newDeck);
	std::cout << "The first card of the second deck is : " << (std::string)newDeck.DrawNextCard() << std::endl;
	std::cout << "Number of cards remaining in the second deck is: " << newDeck.CardsRemaining() << std::endl << std::endl;

	// Reset the deck and show the result
	newDeck.Initialize();
	std::cout << "Result after reset the deck: " << std::endl;
	std::cout << "Number of cards remaining: " << newDeck.CardsRemaining() << std::endl << std::endl;

	std::cout << "The first card of the deck is : " << (std::string)newDeck.DrawNextCard() << std::endl;
	std::cout << "Number of cards remaining: " << newDeck.CardsRemaining() << std::endl << std::endl;

	return 0;
}


