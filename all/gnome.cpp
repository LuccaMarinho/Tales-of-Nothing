#include "gnome.hpp"

Gnome::Gnome(){
	this->name = "Saint Patrick";
	this->race = "Gnome";
	this->level = 3;
	this->d_xp = 600;
	this->hp = 15;
	this->ac = 17;
	this->attacks[0] = "Under Kick";
	this->attacks[1] = "Under Punch";
	this->attacks[2] = "Nutcracker";
	this->e_taunt = 10;
	this->dodge_fail = 1;
	this->potion_fail = 1;
	this->run_fail = 1;
}

short Gnome::e_damage(){
	short damage;
	short attack = get_dice(8);
		if (attack < 4){
			damage = get_dice(4);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (attack >= 4 && attack <= 6){
			damage = get_dice(4);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (attack >= 7){
			damage = get_dice(6);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

	return 0;
}
