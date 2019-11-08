#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <exception>
#include "dice.hpp"

class Player{
	
	private:
		Dice _roll;
		std::string _name;
		std::string _r_class;
		short _level;
		short _xp;
		short _hp;
		short _init_hp;
		short _ac;
		short _potions;
		short _potion_heal;
		short _dodge_buff;	
		short _dodge_hability;
		std::string _attacks[3];
		std::string _m_attack;
		short _next_level;
		
	protected:
		bool dark;

	public:
		void set_r_class(std::string r_class);
		void set_level(short level);
		void set_xp(short xp);
		void set_hp(short hp);
		void set_init_hp(short init_hp);
		void set_ac(short ac);
		void set_potions(short potions);
		void set_dodge_buff(short dodge_buff);
		void set_dodge_hability(short dodge_hability);
		void set_attack(std::string attack, short num);
		void set_m_attack(std::string attack);
		void set_next_level(short next_level);

		short get_dice(short roll);
		std::string get_r_class();
		short get_level();
		short get_xp();
		short get_hp();
		short get_init_hp();
		short get_ac();
		short get_potions();
		short get_dodge_buff();
		short get_dodge_hability();
		std::string get_m_attack();
		std::string get_attack(short num);
		short get_next_level();

		Player(std::string name);

		virtual ~Player();
	
		void status();

		virtual short p_damage();

		virtual void level_up();

		void p_potion_heal();

		short p_decision();

		short d_damage(short how_good);

		void p_modify_hp(short m_hp);
};

#endif
