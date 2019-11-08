#include "pumpkin.hpp"

Pumpkin::Pumpkin(short level){
	this->name = "Halloween";
	this->race = "Pumpkin";
	this->level = level;
	this->d_xp = 300;
	this->hp = 27;
	this->ac = 9;
	this->attacks[0] = "Candy Bomb";
	this->attacks[1] = "Rotten Egg";
	this->attacks[2] = "Tricks or Treats";
	this->e_taunt = 12;
	this->dodge_fail = 1;
	this->potion_fail = 1;
	this->run_fail = 0;
}

Pumpkin::Pumpkin(short level, short d_xp){
	this->name = "Bomb King";
	this->race = "Pumpkin";
	this->level = level;
	this->d_xp = d_xp;
	this->hp = 45;
	this->ac = 11;
	this->attacks[0] = "Countdown";
	this->attacks[1] = "King Bomb";
	this->e_taunt = 15;
	this->dodge_fail = 4;
	this->potion_fail = 2;
	this->run_fail = 1;
}


short Pumpkin::e_damage(){
	short damage;
	if(level == 2){
		if (hp >= 16){
			damage = get_dice(4) + get_dice(4);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp >= 7){
			damage = get_dice(4) + get_dice(6);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp <= 6){
			damage = get_dice(12);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}

	if(level == 5){
		if (hp >= 11){
			damage = get_dice(6);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			std::cout << "Also, it lost 5 HP" << std::endl;
			hp -= 5;
			return damage;
		}

		else if (hp <= 10){
			damage = get_dice(4) + get_dice(4) + get_dice(4) + get_dice(4) + get_dice(4);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			std::cout <<  "Give your king a BIG hug!" << std::endl;
			hp = 0;
			return damage;
		}
	}

	return 0;
}
