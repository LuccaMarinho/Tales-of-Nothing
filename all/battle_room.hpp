#ifndef BATTLEROOM_H
#define BATTLEROOM_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <utility>
#include "enum_winner.hpp"
#include "lucky.hpp"
#include "mage.hpp"
#include "ranger.hpp"
#include "warrior.hpp"
#include "boss.hpp"
#include "gnome.hpp"
#include "skeleton.hpp"
#include "slime.hpp"
#include "pumpkin.hpp"
#include "wolf.hpp"


class Battle_room{
	private:
		int _id;
		bool _battle_on;
		bool _battle_run;
		bool _dodge;
		bool _won_game;
		int _current_decision;
		int _damage;
		Dice _dice;
		Player *_current_player;
		Enemy *_chosen_enemy;
		Winner _winner; 
		std::vector<std::string> _possible_decisions;
		std::pair<short, short> _next_turn;
		void define_attack(short i);
		void player_attacking();
		void enemy_attacking();
		bool stop_battle();
		void fill_possible_decisions(Player *player);
	public:
		Battle_room(Player *player, Enemy *enemy); 
		~Battle_room();
		void set_player(Player *p);
		void set_battle_on(bool value_battle);
		bool is_battle_on();
		void set_id(int x);
		int get_id();
		void set_next_turn(short left, short right);
		std::pair <short, short> get_next_turn();
		void run_battle();
		bool get_won_game();
		bool get_battle_run();

};

#endif