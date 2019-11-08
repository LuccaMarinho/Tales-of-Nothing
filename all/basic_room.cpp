#include "basic_room.hpp"

short Basic_room::history_version = 0;

Basic_room::Basic_room(Player* p){
	this->player = p;
	this->id = 0;
	this->attribute = 0;
	this->end_game = false;
}
Basic_room::~Basic_room(){}

bool Basic_room::get_end_game(){
	return this->end_game;
}
short Basic_room::get_id(){
	return this->id;
}
short Basic_room::get_attribute(){
	return this->attribute;
}
std::pair<short,short> Basic_room::get_next_turn(){
	return this->next_turn;
}
Player* Basic_room::get_player(){
	return this->player;
}
void Basic_room::set_next_turn(short left, short right){
	this->next_turn.first = left;
	this->next_turn.second = right;
}
void Basic_room::set_id(short x){
	this->id = x;
}
void Basic_room::set_attribute(short x){
	this->attribute = x;
}
void Basic_room::set_player(Player *p){
	this->player = p;
}
void Basic_room::finish_game(){
	this->end_game = true;
}

void Basic_room::print_texts(){
	for(unsigned int i =0; i<this->texts.size(); i++){	
		std::cout << texts[i] << std::endl;
	}
}

bool Basic_room::choosing_way(){
	std::string command;
	bool select = false;
	while(!select){
		try{
			std::cin >> command;
			if(command == "L" || command == "l"){
				select = true;
				return false;
			}else if(command == "R" || command == "r"){
				select = true;
				return true;
			}else {
				throw std::exception();
			}
		}
		catch(std::exception& e){
			std::cout << "\nInvalid choice. Please press:" << std::endl;
			std::cout << "(left)-> l or (right)-> r" << std::endl;
		}
	}
	
	return false;
}
