#ifndef EVENTBATTLE_H
#define EVENTBATTLE_H

#include "battle_room.hpp"
#include "event.hpp"
#include <utility>


class Event_battle:public Event{
	public:
		Event_battle(short x);
		~Event_battle();

};
#endif
