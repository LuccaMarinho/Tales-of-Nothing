#include "life_potion.hpp"

Life_potion::Life_potion(Player* p) : Basic_room(p) {
	this->texts.push_back("\nYou have found a potion in a treasure chest!");
	this->texts.push_back("You have obtained a potion.\n");
	this->set_attribute(10);
}
void Life_potion::room_interaction(){
	this->print_texts();
	bool select = false;
	std::string answer;
	std::cout << "\nDo you want to use the potion ?" << std::endl;
	std::cout << " (yes)-> y or (no)-> n" << std::endl;
	while(!select){
		try{
			std::cin >> answer;
			if(answer == "y" || answer == "Y"){
				select = true;
				this->player->p_modify_hp(this->attribute);
				this->player->status();
			}else if(answer == "n" || answer == "N"){
				select = true;
				this->player->set_potions(this->player->get_potions()+1);
			}else {
				throw std::exception();
			}
		}catch(std::exception& e){
			std::cout << "\nInvalid choice. Please press:" << std::endl;
			std::cout << " (yes)-> y or (no)-> n\n" << std::endl;
		}
	}		
}
