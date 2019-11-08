#ifndef LUCKY_h
#define LUCKY_h

#include "player.hpp"

class Lucky : public Player{
	public:
		Lucky(std::string name);

		short p_damage() override;

		void level_up() override;
};

#endif