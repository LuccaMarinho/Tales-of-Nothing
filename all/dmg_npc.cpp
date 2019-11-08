#include "dmg_npc.hpp"

Dmg_npc::Dmg_npc(Player* p, bool version) : Basic_room(p){
	if(version == true){
		this->set_attribute(-5);
		this->texts.push_back("\nYou have successfully runned from the enemies,");
		this->texts.push_back("but right after that someone threw a rock on your head.\n");
		this->room_version = 1;
	}else{
		this->set_attribute(-5);
		this->texts.push_back("\nBut when you tried to pick it,"); 
		this->texts.push_back("you have been hited by a pitfall.\n");
		this->room_version = 0;			
	}
}
void Dmg_npc::room_interaction(){
	this->print_texts();
	this->player->p_modify_hp(this->attribute);
	if(this->player->get_hp() <= 0){
		std::cout << "The damage was critical and you ended up dying.\n" << std::endl;
		this->finish_game();
	}else if(this->room_version == 1){
		std::cout << "Your head have blooded a little," << std::endl;
		std::cout << "but this is not enough to stop you!\n" << std::endl;
		this->player->status();
	}else if(this->room_version == 0){
		std::cout << "Luckily you were able to break free" << std::endl;
		std::cout << "from the trap!\n" << std::endl;
		this->player->status();
	}else {
		std::cout << "Even with that, you seems to still be able to continue.\n" << std::endl;
		this->player->status();
	}
}
