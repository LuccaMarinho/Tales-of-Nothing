#include "abism_death_room.hpp"

Abism_death_room::Abism_death_room(Player* p) : Basic_room(p){
	this->texts.push_back("\nRunning from the enemies, in a moment of inattention");
	this->texts.push_back("you have slipped into a abism and DIED after the falling.\n");
}
void Abism_death_room::room_interaction(){
	this->print_texts();
	this->finish_game();
}
