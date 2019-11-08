#ifndef EVENT_H
#define EVENT_H

#include "player.hpp"
#include "enemy.hpp"
#include "enum_type.hpp"
#include "room.hpp"
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cassert>
#include <exception>

class Event{
	private:
		bool _game_on;
		bool _won;
		std::pair<short, Type> _current_room;
		std::pair<short, Type> _next_room;
		std::pair<Room*, Room*> _next_class;

		std::vector<std::string> _messages;
		short valid_name(std::string s);
		
	protected:
		Player *selected_player;
		Room *room;
		
	public:
		Event();
		virtual ~Event();
		
		void set_player(Player*);
		Player* get_player();
		void set_game_on(bool value_game);
		bool get_game_on();
		void set_won(bool value_won);
		bool get_won();
		
		Room* return_room();
		void set_next_class(Room *left,Room *right);
		std::pair<Room*, Room*> get_next_class();

		void set_current_room(std::pair<short, Type> a);
		std::pair <short, Type> get_current_room();
		void set_next_room(std::pair<short, Type> a);
		std::pair <short, Type> get_next_room();

		void insert_message(std::string text);
		void get_messages(short i);

		void game_start();
		void pick_player();

};

#endif
