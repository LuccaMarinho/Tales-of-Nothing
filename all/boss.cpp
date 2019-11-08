#include "boss.hpp"

Boss::Boss(){
	this->name = "LAB99EX99";
	this->race = "Robot VPL";
	this->level = 4;
	this->d_xp = 600;
	this->hp = 50;
	this->ac = 13;
	this->attacks[0] = "Hello World!";
	this->attacks[1] = "Valgrind";
	this->attacks[2] = "Round Robin";
	this->e_taunt = 21;
	this->dodge_fail = 0;
	this->potion_fail = 0;
	this->run_fail = 0;
}

Boss::Boss(short level){
	this->name = "Ruckus";
	this->race = "Robot X";
	this->level = level;
	this->d_xp = 750;
	this->hp = 75;
	this->ac = 14;
	this->attacks[0] = "Miniguns";
	this->attacks[1] = "Missile Launcher";
	this->attacks[2] = "Hexa Fire";
	this->e_taunt = 21;
	this->dodge_fail = 1;
	this->potion_fail = 1;
	this->run_fail = 1;
}

Boss::Boss(short level, short d_xp){
	this->name = "Kunlun";
	this->race = "King Robot";
	this->level = level;
	this->d_xp = d_xp;
	this->hp = 100;
	this->ac = 13;
	this->attacks[0] = "Dúwù";
	this->attacks[1] = "Gùdìng";
	this->attacks[2] = "Kāihuā";
	this->e_taunt = 21;
	this->dodge_fail = 2;
	this->potion_fail = 4;
	this->run_fail = 0;
}

short Boss::e_damage(){
	short damage;
	if(level == 4){
		if (hp >= 35){
			damage = get_dice(4);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp > 5){
			damage = get_dice(10);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp <= 5){
			damage = get_dice(20);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}

	else if(level == 5){
		if (hp >= 40){
			damage = get_dice(4) + get_dice(4) + get_dice(4);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp > 5){
			damage = get_dice(8) + get_dice(8) + get_dice(8);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp <= 5){
			damage = get_dice(10) + get_dice(10) + get_dice(10) + get_dice(4);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}

	else if(level == 7){
		if (hp >= 55){
			damage = get_dice(6) + get_dice(6) + get_dice(6);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp > 10){
			damage = get_dice(8) + get_dice(8) + get_dice(8) + get_dice(8) + get_dice(8);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else if (hp <= 10){
			damage = get_dice(10) + get_dice(10) + get_dice(10) + get_dice(10) + get_dice(10);
			std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}

	return 0;
}