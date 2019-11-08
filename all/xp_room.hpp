#ifndef XP_ROOM_H
#define XP_ROOM_H

#include "basic_room.hpp"

class Xp_room : public Basic_room {

public:

	Xp_room(Player* p);
	
	void room_interaction() override;

};

#endif