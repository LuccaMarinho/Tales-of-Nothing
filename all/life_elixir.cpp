 #include "life_elixir.hpp"

Life_elixir::Life_elixir(Player* p) : Basic_room(p){
	this->texts.push_back("\nYou have found a life elixir!");
	this->texts.push_back("You drink from the elixir.");
	this->texts.push_back("Your HP have been fully restored.\n");			
}
void Life_elixir::room_interaction() {
	this->attribute = this->player->get_init_hp();
	this->print_texts();
	this->player->set_hp(this->attribute);
	this->player->status();
}
