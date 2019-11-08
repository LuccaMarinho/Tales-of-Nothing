#include "xp_room.hpp"

Xp_room::Xp_room(Player* p) : Basic_room(p) {
	this->texts.push_back("\nYou are not ready for the final challenge.");
	this->texts.push_back("I make you a little stronger!");
	this->texts.push_back("You leveled up\n!");
	this->set_attribute(300);
}
void Xp_room::room_interaction(){
	this->print_texts();
	this->player->set_xp(this->player->get_xp() + this->attribute);
	this->player->set_next_level(this->player->get_next_level() - this->player->get_xp());
	this->player->status();
}
