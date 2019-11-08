#ifndef SKELETON_H
#define SKELETON_H

#include "enemy.hpp"

class Skeleton: public Enemy{
	public:
		Skeleton();

		short e_damage() override;
};

#endif