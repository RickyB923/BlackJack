#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class Player 
	{
		public:
			Hand hand;
			Player();

			virtual ~Player();

			virtual bool IsBusted(Hand& hand);

			virtual bool CheckIfHitting(Hand& hand);
			
			virtual bool IsStaying(Hand& hand);
			
	};
#endif