#ifndef BASIC_ROOM_H
#define BASIC_ROOM_H

#include "player.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <exception>

class Basic_room {

protected:

	bool end_game;
	short id;
	short attribute;
	short room_version;
	std::vector<std::string> texts;
	std::pair<short, short>next_turn;
	Player* player;
	static short history_version;

	void print_texts();
	void finish_game();

public:

	Basic_room(Player* p);

	virtual ~Basic_room();

	Player* get_player();
	std::pair <short, short> get_next_turn();
	bool get_end_game();
	short get_id();
	short get_attribute();


	void set_player(Player *p);
	void set_next_turn(short left, short right);
	void set_id(short x);
	void set_attribute(short x);

	virtual void room_interaction(){};

	virtual bool choosing_way();
};

#endif
