#ifndef QUIZ_ROOM_H
#define QUIZ_ROOM_H

#include "basic_room.hpp"

class Quiz_room : public Basic_room {

public:

	Quiz_room(Player* p,short version);

	void room_interaction() override;

	bool choosing_way() override;
	
};

#endif