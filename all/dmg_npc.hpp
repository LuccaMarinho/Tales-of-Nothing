#ifndef DMG_NPC_H
#define DMG_NPC_H

#include "basic_room.hpp"

class Dmg_npc : public Basic_room {

public:

	Dmg_npc(Player* p, bool version);

	void room_interaction() override;
	
};

#endif