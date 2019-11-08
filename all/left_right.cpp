 #include "left_right.hpp"

Left_right::Left_right(Player* p) : Basic_room(p) {
	this->texts.push_back("\nYou found yourself at a crossroads.");
	this->texts.push_back("Which side will you go to ?");
}
void Left_right::room_interaction(){
	this->print_texts();
}
