#ifndef MIMIC_DEATH_ROOM_H
#define MIMIC_DEATH_ROOM_H

#include "basic_room.hpp"

class Mimic_death_room : public Basic_room {

public:

	Mimic_death_room(Player* p);

	void room_interaction() override;
	
};

#endif