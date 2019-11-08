#ifndef SLIME_H
#define SLIME_H

#include "enemy.hpp"

class Slime : public Enemy{
	public:
		Slime(short level);
		Slime(short level, short d_xp);

		short e_damage() override;
};

#endif