#include "wolf.hpp"

Wolf::Wolf(){
	this->name = "Fenrir";
	this->race = "Wolf";
	this->level = 3;
	this->d_xp = 450;
	this->hp = 25;
	this->ac = 15;
	this->attacks[0] = "Bite";
	this->attacks[1] = "Swipe";
	this->attacks[2] = "Deadly Roar";
	this->e_taunt = 15;
	this->dodge_fail = 1;
	this->potion_fail = 0;
	this->run_fail = 3;
}

short Wolf::e_damage(){
	short damage;
	short attack = get_dice(4);
	if(hp > 10){
		if (attack != 2){
			damage = get_dice(12);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (attack == 2){
			damage = get_dice(4) + get_dice(4) + get_dice(4);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}

	else{
		damage = get_dice(6) + get_dice(4) + get_dice(4);
		std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
		return damage;
	}

	return 0;
}
