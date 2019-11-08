#ifndef HISTORY_ROOM_H
#define HISTORY_ROOM_H

#include "basic_room.hpp"

class History_room : public Basic_room {

public:

	History_room(Player* p);
	
	void room_interaction() override;
	
};

#endif