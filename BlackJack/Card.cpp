/*
=========================================================
Blackjack in C++
Made By Sahil Bora
Made with Visual Studio 2010
File:card.cpp
=========================================================
*/

#include "card.h"

/*
==================================================
Card Constructor
==================================================
*/

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

/*
=========================================
Get the value of the card
=========================================
*/

int Card::GetValue() const
{
	/*
	==========================================
	If a card is face down, its value is 0
	==========================================
	*/
	int value = 0;
	if (m_IsFaceUp)
	{
		/*
		========================================
		Value is number showing on card
		========================================
		*/
		value = m_Rank;

		/*
		=======================================
		Value is 10 for face cards
		=======================================
		*/
		if (value > 10)
			value = 10;
	}
	return value;
}

/*
==================================================
Flip the card
==================================================
*/
void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}