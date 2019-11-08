#ifndef MAGE_H
#define MAGE_H

#include "player.hpp"

class Mage : public Player{
	public:
		Mage(std::string name);
		
		short p_damage() override;

		void level_up() override;
};

#endif