#ifndef LIFE_ELIXIR_H
#define LIFE_ELIXIR_H

#include "basic_room.hpp"

class Life_elixir : public Basic_room {

public:

	Life_elixir(Player* p);

	void room_interaction() override;

};

#endif