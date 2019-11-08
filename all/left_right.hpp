#ifndef LEFT_RIGHT_H
#define LEFT_RIGHT_H

#include "basic_room.hpp"

class Left_right : public Basic_room {

public:

	Left_right(Player* p);

	void room_interaction() override;
	
};

#endif