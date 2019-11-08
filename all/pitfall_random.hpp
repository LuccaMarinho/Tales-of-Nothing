#ifndef PITFALL_RANDOM_H
#define PITFALL_RANDOM_H

#include "basic_room.hpp"

class Pitfall_random : public Basic_room {

public:

	Pitfall_random(Player* p);

	void room_interaction() override;

	bool choosing_way() override;

};

#endif