#ifndef LIFE_POTION_H
#define LIFE_POTION_H

#include "basic_room.hpp"


class Life_potion : public Basic_room {

public:


	Life_potion(Player* p);

	void room_interaction() override;

};

#endif