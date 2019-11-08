#include "player.hpp"
#define max_hp 40

Player::Player(std::string name){
	this->_name = name;
	this->_r_class = "";
	this->_level = 1;
	this->_xp = 0;
	this->_hp = 0;
	this->_init_hp = 0;
	this->_ac = 0;
	this->_potions = 0;
	this->_potion_heal = 5;
	this->_dodge_buff = 0;
	this->_dodge_hability = 0;
	this->_attacks[0] = "N/A";
	this->_attacks[1] = "N/A";
	this->_attacks[2] = "N/A";
	this->_m_attack = "N/A";
	this->_next_level = (300 * _level) - _xp;
	this->dark = false;
}

Player::~Player(){}

void Player::set_r_class(std::string r_class){
	this->_r_class = r_class;
}

void Player::set_level(short level){
	this->_level = level;
}

void Player::set_xp(short xp){
	this->_xp = xp;
}

void Player::set_hp(short hp){
	this->_hp = hp;
}

void Player::set_init_hp(short init_hp){
	this->_init_hp = init_hp;
}

void Player::set_ac(short ac){
	this->_ac = ac;
}

void Player::set_potions(short potions){
	this->_potions = potions;
}

void Player::set_dodge_buff(short dodge_buff){
	this->_dodge_buff = dodge_buff;
}

void Player::set_dodge_hability(short dodge_hability){
	this->_dodge_hability = dodge_hability;
}

void Player::set_attack(std::string attack, short num){
	this->_attacks[num] = attack;
}

void Player::set_m_attack(std::string attack){
	this->_m_attack = attack;
}

void Player::set_next_level(short next_level){
	this->_next_level = next_level;
}

short Player::get_dice(short roll){
	return this->_roll.roll_dice(roll);
}

std::string Player::get_r_class(){
	return this->_r_class;
}

short Player::get_level(){
	return this->_level;
}

short Player::get_xp(){
	return this->_xp;
}

short Player::get_hp(){
	return this->_hp;
}

short Player::get_init_hp(){
	return this->_init_hp;
}

short Player::get_ac(){
	return this->_ac;
}

short Player::get_potions(){
	return this->_potions;
}

short Player::get_dodge_buff(){
	return this->_dodge_buff;
}

short Player::get_dodge_hability(){
	return this->_dodge_hability;
}

std::string Player::get_m_attack(){
	return this->_m_attack;
}
std::string Player::get_attack(short num){
	return this->_attacks[num];
}

short Player::get_next_level(){
	return this->_next_level;
}

void Player::status(){
	if (_next_level <= 0)
		level_up();
	std::cout << std::endl << "Player Status" << std::endl;
	std::cout << "Name: " << _name << "  Class: " << _r_class << std::endl;
	std::cout << "level: " << _level << "  HP: " << _hp << "  AC: " << _ac <<  "  XP: " << _xp << "  Next level: +" << _next_level << " XP" << std::endl;
	std::cout << "Attacks: " << _attacks[0] << " | " << _attacks[1] << " | " << _attacks[2] << "  Potions: " << _potions << "  Potion Heal: +" << _potion_heal << std::endl;
	std::cout << "Dodge hability: " << _dodge_hability << "  Dodge Buff: +" << _dodge_buff << std::endl << std::endl;
}

short Player::p_damage(){
	return 0;
}

void Player::level_up(){}

void Player::p_potion_heal(){
	if(_potions > 0){
		if(_hp + _potion_heal > _init_hp)
			_hp = _init_hp;
		else
			_hp += _potion_heal;

		_potions -= 1;
		std::cout << "You healed +" << _potion_heal << "HP, you have " << _potions << " Potions left!" << std::endl;	
		std::cout << "Your life: " << _hp << std::endl << std::endl;
	}
	else
		std::cout << "You have no potions left!" << std::endl;
}

short Player::p_decision(){
		std::string decision;

	while(true){

		std::string decisions[] = {"What do you wanna do?", "[1]" + _attacks[0], "  [2]" + _attacks[1], "  [3]" + _attacks[2], "  [4]Dodge", "  [5]Potion", "  [6]Run"};
		std::cout << decisions[1] << decisions[2] << decisions[3] << decisions[4] << decisions[5] << decisions[6] << std::endl;
		std::cout << decisions[0] << " ";
	
		try{

			std::cin >> decision;
			std::cout << std::endl;

			if((decision >= "a" && decision <= "z") || (decision >= "A" && decision <= "Z")){
				throw std::invalid_argument("Invalid character!");
			}

			else if((decision >= "!" && decision <= "/") || (decision >= ":" && decision <= "@"))
				throw std::invalid_argument("Invalid character!");

			else if((decision >= "[" && decision <= "`") || (decision >= "{" && decision <= "_"))
				throw std::invalid_argument("Invalid character!");

			else if((atoi(decision.c_str()) <= 0) || (atoi(decision.c_str()) >= 7)){
				throw std::invalid_argument("Invalid number!");;
			}

			else if(true)
				break;

		}

		catch(std::invalid_argument& ia){
			std::cout << ia.what() << std::endl << std::endl;
		} 
	}

	return (atoi(decision.c_str()));
}


short Player::d_damage(short how_good){
	switch(how_good){
		case 0:
			return _roll.roll_dice(4);
			break;

		case 1:
			return _roll.roll_dice(6);
			break;

		case 2:
			return _roll.roll_dice(8);
			break;

		case 3:
			return _roll.roll_dice(10);
			break;

		case 4:
			return _roll.roll_dice(12);
			break;

		case 5:
			return _roll.roll_dice(16);
			break;

		case 6:
			return _roll.roll_dice(20);
			break;

		default:
			return 0;
			break;
	}
}

void Player::p_modify_hp(short m_hp){
	try{
		if((int(m_hp) >= int(':') && int(m_hp) <= int('~')))
			throw std::invalid_argument("Invalid character!");

		if(std::abs(m_hp) > max_hp)
			throw std::invalid_argument("Invalid number!");
		}
		
	catch(std::invalid_argument& ia){
		m_hp = 0;
		std::cout << ia.what() << std::endl << std::endl;
	}

	if(this->_hp == this->_init_hp)
		m_hp = 0;

	if(m_hp < 0 && std::abs(m_hp) >= this->_hp)
		this->_hp = 0;
	else
		this->_hp += m_hp;
}
