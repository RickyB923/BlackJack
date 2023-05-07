#include "player.h"
#include "hand.h"


Player::Player()
{}

Player::~Player()
{}

bool Player::IsBusted(Hand& hand)
{
	if (hand.GetTotal() > 21)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Player::CheckIfHitting(Hand& hand)
{
	if (hand.GetTotal() <= 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::IsStaying(Hand& hand)
{
	if (hand.GetTotal() > 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}