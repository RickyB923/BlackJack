#ifndef DECK_H
#define DECK_H

#include "hand.h"
#include "Player.h"

class Deck : public Hand
{
public:
	Deck();

	virtual ~Deck();

	void Populate();

	void Shuffle();

	void Deal(Hand& aHand);
};

#endif