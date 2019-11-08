#include "mimic_death_room.hpp"

Mimic_death_room::Mimic_death_room(Player* p) : Basic_room(p){
	this->texts.push_back("\nYou have found a treasure chest!");
	this->texts.push_back("You tried to open it...");
	this->texts.push_back("but instantaneously it's opened by it self and attacked you!");	
	this->texts.push_back("You have been killed by a Mimic.\n");
}

void Mimic_death_room::room_interaction(){
	this->print_texts();
	this->finish_game();
}