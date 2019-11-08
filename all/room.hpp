#ifndef ROOM_H
#define ROOM_H

#include "battle_room.hpp"
#include "basic_room.hpp"
#include "enum_type.hpp"
#include "boost/variant/variant.hpp"   

class Room{
	private:
		Battle_room *_battle;
		Basic_room *_interaction;
		Type _type;
	public:
		Room(Player *player, Enemy *enemy, short id);
		Room(Basic_room *basic);
		~Room();
		boost::variant< Battle_room*, Basic_room*> get_room();
		Type get_type();
};

#endif

