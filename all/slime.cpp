#include "slime.hpp"

Slime::Slime(short level){
	this->name = "Lǐ Sī";
	this->race = "Slime";
	this->level = level;
	this->d_xp = 150;
	this->hp = 12;
	this->ac = 13;
	this->attacks[0] = "Poing";
	this->attacks[1] = "Bubble Shot";
	this->attacks[2] = "Predator";
	this->e_taunt = 10;
	this->dodge_fail = 0;
	this->potion_fail = 0;
	this->run_fail = 0;
}

Slime::Slime(short level, short d_xp){
	this->name = "Rimuru Tempest";
	this->race = "Ancient Slime";
	this->level = level;
	this->d_xp = d_xp;
	this->hp = 28;
	this->ac = 15;
	this->attacks[0] = "Water Blade";
	this->attacks[1] = "Dissolve";
	this->attacks[2] = "Predator";
	this->e_taunt = 12;
	this->dodge_fail = 1;
	this->potion_fail = 2;
	this->run_fail = 3;
}

short Slime::e_damage(){
	short damage;
	if(level == 1){
		if (hp >= 8){
			damage = get_dice(4);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp >= 4){
			damage = get_dice(6);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp < 3){
			damage = get_dice(10);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}

	else if(level == 4){
		if (hp >= 18){
			damage = get_dice(4) + get_dice(4);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp >= 5){
			damage = get_dice(6) + get_dice(6);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp < 5){
			damage = get_dice(8) + get_dice(8);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}

	return 0;
}