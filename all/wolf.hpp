#ifndef WOLF_H
#define WOLF_H

#include "enemy.hpp"

class Wolf: public Enemy{
	public:
		Wolf();

		short e_damage() override;
};

#endif