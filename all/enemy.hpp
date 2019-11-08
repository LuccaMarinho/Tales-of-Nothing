#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "dice.hpp"

class Enemy {

	protected:
		Dice roll;
		std::string name;
		std::string race;
		short level;
		short d_xp;
		short hp;
		short ac;	
		std::string attacks[3];
		short e_taunt;
		short dodge_fail;
		short potion_fail;
		short run_fail;

	public:
		Enemy();
	
		virtual ~Enemy(); 
	
		void set_hp(short hp);

		short get_dice(short roll);
		std::string get_name();
		short get_d_xp();
		short get_hp();
		short get_ac();
		short get_e_taunt();
		short get_dodge_fail();
		short get_potion_fail();
		short get_run_fail();

		void status();

		virtual short e_damage();

		short p_fail(short how_bad);
};

#endif
