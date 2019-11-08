#include "enemy.hpp"

Enemy::Enemy(){
	this->name = "";
	this->race = "";
	this->level = 0;
	this->d_xp = 0;
	this->hp = 0;
	this->ac = 0;
	this->attacks[0] = "";
	this->attacks[1] = "";
	this->attacks[2] = "";
	this->e_taunt = 0;
	this->dodge_fail = 0;
	this->potion_fail = 0;
	this->run_fail = 0;
}

Enemy::~Enemy(){}

void Enemy::set_hp(short hp){
	this->hp = hp;
}

short Enemy::get_dice(short roll){
	return this->roll.roll_dice(roll);
}

std::string Enemy::get_name(){
	return this->name;
}

short Enemy::get_d_xp(){
	return this->d_xp;
}

short Enemy::get_hp(){
	return this->hp;
}

short Enemy::get_ac(){
	return this->ac;
}

short Enemy::get_e_taunt(){
	return this->e_taunt;
}

short Enemy::get_dodge_fail(){
	return this->dodge_fail;
}

short Enemy::get_potion_fail(){
	return this->potion_fail;
}

short Enemy::get_run_fail(){
	return this->run_fail;
}

void Enemy::status(){
	std::cout << std::endl << "Enemy Status" << std::endl;
	std::cout << "Name: " << name << "  Race: " << race << std::endl;
	std::cout << "Level: " << level << "  HP: " << hp << "  AC: " << ac <<  "  Death XP: +" << d_xp << std::endl;
	std::cout << "Attacks: " << attacks[0] << " | " << attacks[1] << " | " << attacks[2]  << std::endl << std::endl;
}

short Enemy::e_damage(){
	return 0;
}

short Enemy::p_fail(short how_bad){
	switch(how_bad){
		case 0:
			return roll.roll_dice(4);
			break;

		case 1:
			return roll.roll_dice(6);
			break;

		case 2:
			return roll.roll_dice(8);
			break;

		case 3:
			return roll.roll_dice(10);
			break;

		case 4:
			return roll.roll_dice(12);
			break;

		case 5:
			return roll.roll_dice(16);
			break;

		case 6:
			return roll.roll_dice(20);
			break;

		default:
			return 0;
			break;
	}
}
