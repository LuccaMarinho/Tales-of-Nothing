#ifndef EVENTINTERACTION_H
#define EVENTINTERACTION_H

#include "event.hpp"
#include "basic_room.hpp"
#include "pitfall_random.hpp"
#include "abism_death_room.hpp"
#include "dmg_npc.hpp"
#include "mimic_death_room.hpp"
#include "life_elixir.hpp"
#include "life_fairy.hpp"
#include "life_potion.hpp"
#include "history_room.hpp"
#include "left_right.hpp"
#include "quiz_room.hpp"
#include "tip_room.hpp"
#include "xp_room.hpp"

class Event_interaction:public Event{
	public:
		Event_interaction(short x);
		~Event_interaction();

};
#endif