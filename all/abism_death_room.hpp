#ifndef ABISM_DEATH_ROOM_H
#define ABISM_DEATH_ROOM_H

#include "basic_room.hpp"

class Abism_death_room : public Basic_room {

public:

	Abism_death_room(Player* p);

	void room_interaction() override;
	
};

#endif