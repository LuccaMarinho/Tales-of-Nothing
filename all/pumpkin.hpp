#ifndef PUMPKIN_H
#define PUMPKIN_H

#include "enemy.hpp"

class Pumpkin: public Enemy{
	public:
		Pumpkin(short level);
		Pumpkin(short level, short d_xp);

		short e_damage() override;
};

#endif