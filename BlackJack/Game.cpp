#include "game.h"
#include "player.h"
#include "card.h"

Game::Game()
{
	srand(time(0));
	_deck.Populate();
	_deck.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{
	Player player;
	Player house;
	int numberOfHands = 0;
	while (numberOfHands < 100)
	{
		_deck.Deal(player.hand);
		_deck.Deal(player.hand);
		_deck.Deal(house.hand);
		_deck.Deal(house.hand);


		while (!player.IsBusted(player.hand) && !player.IsStaying(player.hand))
		{
			if (player.CheckIfHitting(player.hand))
			{
				_deck.Deal(player.hand);
			}
		}

		if (player.IsBusted(player.hand))
		{
			cout << "Player has busted at " << player.hand.GetTotal() << endl;
			cout << "The House wins" << endl;
		}
		else
		{
			while (!house.IsBusted(house.hand) && !house.IsStaying(house.hand))
			{
				if (house.CheckIfHitting(house.hand))
				{
					_deck.Deal(house.hand);
				}
			}
			if (house.IsBusted(house.hand))
			{
				cout << "Dealer has busted at " << house.hand.GetTotal() << endl;
				cout << "The Player wins" << endl;

			}
			else
			{
				if (house.IsStaying(house.hand) && player.IsStaying(player.hand))
				{
					cout << "Player has " << player.hand.GetTotal() << ", Dealer has " << house.hand.GetTotal() << endl;
					if (player.hand.GetTotal() > house.hand.GetTotal())
					{
						cout << "The Player wins" << endl;
					}
					else if (player.hand.GetTotal() == house.hand.GetTotal())
					{
						cout << "It's a tie!" << endl;
					}
					else if (player.hand.GetTotal() < house.hand.GetTotal())
					{
						cout << "The House wins" << endl;
					}
				}
			}
		}
		player.hand.Clear();
		house.hand.Clear();
		_deck.Populate();
		_deck.Shuffle();
		numberOfHands++;
		cout << "Hands played: " << numberOfHands << endl;
		cout << "" << endl;
	}
}