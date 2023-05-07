/*
=========================================================
Blackjack in C++
Made with Visual Studio 2010
File:card.h
=========================================================
*/

/*
====================================
Defining header
====================================
*/

#ifndef CARD_H
#define CARD_H

/*
=======================================
Included files
=======================================
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

/*
=================================================
Card Class
=================================================
*/
class Card
{
public:
	enum rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};

	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	friend ostream& operator << (ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	/*
	================================
	Returns the value of a card
	================================
	*/
	int GetValue() const;

	/*
	============================================================
	Flips a card; if face up, becomes face down and vice versa
	============================================================
	*/
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

#endif