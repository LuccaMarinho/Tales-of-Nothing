#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.hpp"

class Warrior : public Player{
	public:
		Warrior(std::string name);

		short p_damage() override;

		void level_up() override;
};
#endif