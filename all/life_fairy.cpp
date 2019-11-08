#include "life_fairy.hpp"

Life_fairy::Life_fairy(Player* p) : Basic_room(p) {
	this->texts.push_back("\nCongratulations for your effort.!");
	this->texts.push_back("Accept this little help!");
	this->texts.push_back("Your HP have been restored a little.\n");			
	this->set_attribute(5);	
}
void Life_fairy::room_interaction(){
	this->print_texts();
	this->player->p_modify_hp(this->attribute);
	this->player->status();
}
