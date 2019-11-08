#include "room.hpp"

Room::Room(Player *player, Enemy *enemy, short id){
	this->_type = Type::BATTLE;
	this->_battle = new Battle_room(player, enemy);
	this->_battle->set_id(id);
	this->_interaction = nullptr;
	switch(id){
		case 28:
			this->_battle->set_next_turn(12,16);
			break;
		case 29:
			this->_battle->set_next_turn(0,1);
			break;
		case 30:
			this->_battle->set_next_turn(10,19);
			break;
		case 31:
			this->_battle->set_next_turn(33,20);
			break;
		case 32:
			this->_battle->set_next_turn(23,33);
			break;
		case 33:
			this->_battle->set_next_turn(5,5);
			break;
		case 34:
			this->_battle->set_next_turn(15,6);
			break;
		case 35:
			this->_battle->set_next_turn(50,50);
			break;
		case 36:
			this->_battle->set_next_turn(24,24);
			break;
		case 37:
			this->_battle->set_next_turn(50,50);
			break;
		case 38:
			this->_battle->set_next_turn(24,24);
			break;
		default:
			this->_battle->set_next_turn(50,50);
			break;
	}
}
Room::Room(Basic_room *basic){
	this->_type = Type::INTERACTION;
	this->_interaction = basic;
	this->_battle = nullptr;
}
Room::~Room(){
	if(this->_type == Type::BATTLE)
		delete this->_battle;
	else if(this->_type == Type::INTERACTION)
		delete this->_interaction;
}

boost::variant< Battle_room*, Basic_room*> Room::get_room(){
	if(this->_battle != nullptr){
		return this->_battle;
	}
	return this->_interaction;
}

Type Room::get_type(){
	return this->_type;
}
