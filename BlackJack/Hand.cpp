#include "hand.h"

Hand::Hand()
{
	_cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	_cards.push_back(pCard);
}

void Hand::Clear()
{
	vector<Card*>::iterator iter = _cards.begin();

	for (iter = _cards.begin(); iter != _cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	_cards.clear();
}

int Hand::GetTotal() const
{
	if (_cards.empty())
	{
		return 0;
	}

	if(_cards[0]->GetValue() == 0)
	{
		return 0;
	}
	int total = 0;
	vector<Card*>::const_iterator iter;

	for (iter = _cards.begin(); iter != _cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}


	bool containsAce = false;
	for (iter = _cards.begin(); iter != _cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	if (containsAce && total <= 11)
	{
		total += 10;
	}


	return total;
}