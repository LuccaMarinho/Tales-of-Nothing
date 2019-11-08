#include "pitfall_random.hpp"	

Pitfall_random::Pitfall_random(Player* p) : Basic_room(p){
}
void Pitfall_random::room_interaction(){
	short int random_num = (rand() % 4);
	std::string unlucky_class;
	if(random_num == 0){
		unlucky_class = "Lucky";
	}else if(random_num == 1){
		unlucky_class = "Warrior";
	}else if(random_num == 2){
		unlucky_class = "Mage";
	}else if(random_num == 3){
		unlucky_class = "Ranger";
	}
	if(this->player->get_r_class() == unlucky_class){
		this->room_version = 1;
		this->texts.push_back("\nYou see in a few steps a very rare and useful item.\n");
		this->print_texts();
	}else {
		this->room_version = 2;
		this->texts.push_back("\nYou have seen a very rare item in the left way,");
		this->texts.push_back("but it's obvious that it is a trap");
		this->texts.push_back("so you just continue to move on.\n");
		this->print_texts();
	} 
}

bool Pitfall_random::choosing_way(){
	if(this->room_version == 1){
		return false;
	}else{
		return true;
	}
}