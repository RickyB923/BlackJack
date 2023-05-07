#include "deck.h"

Deck::Deck()
{
	_cards.reserve(52);
	Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
	Clear();
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
		for (int r = Card::ACE; r <= Card::KING; ++r)
			Add(new Card(static_cast<Card::rank>(r),
				static_cast<Card::suit>(s)));
}

void Deck::Shuffle()
{
	random_shuffle(_cards.begin(), _cards.end());
}

void Deck::Deal(Hand& hand)
{
	if (!_cards.empty())
	{
		hand.Add(_cards.back());
		_cards.pop_back();
	}
	else
	{
		cout << "Out of cards. Unable to deal";
	}
}