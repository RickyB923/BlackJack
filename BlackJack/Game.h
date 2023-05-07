#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"

class Game
{
	public:
		Game();

		~Game();

		void Play();

	private:
		Deck _deck;
};
#endif