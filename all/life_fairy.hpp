#ifndef LIFE_FAIRY_H
#define LIFE_FAIRY_H

#include "basic_room.hpp"

class Life_fairy : public Basic_room {

public:

	Life_fairy(Player* p);

	void room_interaction() override;

};

#endif