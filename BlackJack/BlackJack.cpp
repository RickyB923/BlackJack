#include "card.h"
#include "deck.h"
#include "game.h"
#include "hand.h"
#include "player.h"
#include <iostream>


int main()
{
	Game newGame;
	newGame.Play();
	cout << "Press Enter to close the application..." << endl;
	getchar();
	return 0;
}