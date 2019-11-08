#ifndef TIP_ROOM_H
#define TIP_ROOM_H

#include "basic_room.hpp"

class Tip_room : public Basic_room {

public:

	Tip_room(Player* p, short version);
	
	void room_interaction() override;

};

#endif