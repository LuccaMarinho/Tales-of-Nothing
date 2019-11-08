#ifndef RANGER_H
#define RANGER_H

#include "player.hpp"

class Ranger : public Player{
	public:
		Ranger(std::string name);
		
		short p_damage() override;

		void level_up() override;
};

#endif