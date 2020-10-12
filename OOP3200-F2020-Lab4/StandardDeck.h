/** OOP3200. F2020. StandardDeck.h
 *
 *  In this lab you will create your own collection class called StandardDeck, which
 *	will 'contain' objects of the PlayingCard class.  The intent of the class is to
 *	represent a standard deck of 52 cards that might be useful in a card game type
 *	application.
 *
 *	@author		Thom MacDonald
 *	@author		Tom Tsiliopoulos
 *	@version	2020.10
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/
/*
    Author: Domenic Catalano & Duy Tan Vu
    Date: Sunday, October 11, 2020
*/

#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include "PlayingCard.h"


class StandardDeck
{
public:
    // Initialization:
    StandardDeck();                                                 // Default contstructor

    // Rule of three:
    ~StandardDeck();                                                // Destructor
    StandardDeck(const StandardDeck& other_deck);                   // Copy constructor
    StandardDeck& operator=(const StandardDeck& other_deck);        // Overloaded assignment operator

    virtual void Initialize();                                      // Method to initialize the deck
    int CardsRemaining();                                           // Method to display how many cards are remaining
    PlayingCard DrawNextCard();                                     // Method to display first card from the top of the deck
    PlayingCard DrawRandomCard();                                   // Method to select a random card from the deck
    void Shuffle();                                                 // Method to shuffle the deck
    void RemoveCard(int cardIndex);                                 // Method to remove a card from the deck
    void ResizeDeck(int newDeckSize);                               // Method to resize the deck array

private:
    PlayingCard* myDeck;            // Allocated space for the deck
    int size;			            // the size of standard deck vector
};

#endif /* defined (__STANDARD_DECK__) */

