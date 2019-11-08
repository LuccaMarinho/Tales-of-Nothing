#ifndef BOSS_H
#define BOSS_H

#include "enemy.hpp"

class Boss : public Enemy{
	public:
		Boss();
		Boss(short level);
		Boss(short level, short d_xp);

		short e_damage() override;
};

#endif