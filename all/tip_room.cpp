#include "tip_room.hpp"

Tip_room::Tip_room(Player* p, short version) : Basic_room(p) {
	if(version == 1){
		this->texts.push_back("\nBe careful in your next choice!");
		this->texts.push_back("Those who only choice right will sometime die.\n");						
	}else if(version == 2){
		this->texts.push_back("\nIf you prefer to flee and never fight,");
		this->texts.push_back("than choose right after the next battle and");
		this->texts.push_back(" you may be able to end it.\n");	
	}else if(version == 3){
		this->texts.push_back("\nVanderlei: If you flee in your next batlle,");
		this->texts.push_back("you will find a incredible treasure!\n");
	}else if(version == 4){
		this->texts.push_back("\nIf you want to know more about the truth,");
		this->texts.push_back("than choose right in the next possibility.\n");			
	}else {
		this->texts.push_back("\nNo tip for you.\n");
	}
}
void Tip_room::room_interaction() {
	this->print_texts();
}