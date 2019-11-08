#include "quiz_room.hpp"

Quiz_room::Quiz_room(Player* p, short version) : Basic_room(p) {
	this->room_version = version;		
	if(version == 1){
		this->texts.push_back("\n???: -Bipi-bopi! Activating systems!");
		this->texts.push_back("-System enabled!");
		this->texts.push_back("Hello living creature of the planet PDS2.2019 / 1 - bebop!");
		this->texts.push_back("I am the robot Lab99Ex99 model VPL - bebop!");
		this->texts.push_back("What brings you to me - bebop?");
	}else if(version == 2){
		this->texts.push_back("\nFairy: -Hear rumors that you can defeat the monsters,");
		this->texts.push_back("but ... why are you trying so hard?");
	}else if(version == 3){	
		this->texts.push_back("\nPumpkin 1: -The right way is the correct way!");	
		this->texts.push_back("Pumpkin 2: -The Pumpkin 1 never lies!");
		this->texts.push_back("Pumpkin 3: -Two of us are lying!");
		this->texts.push_back("Pumpkin 4: -Pumpkin 2 only speaks the truth!");
	}else {
		this->texts.push_back("\nLeft or Right ?");
	}

}

void Quiz_room::room_interaction(){
	this->print_texts();
}

bool Quiz_room::choosing_way(){
	std::string command;
	bool select = false;
	while(!select){
		if(this->room_version == 1){
			std::cout << "\n[Answer 1] = I came to eliminate you and the other monsters in this forest!" << std::endl;
			std::cout << "[Answer 2] = I have come to find out what is so scary to the locals!\n" << std::endl;
		}else if(this->room_version == 2){
			std::cout << "\n[Answer 1] = Since I am an adventurer, I came because they paid me." << std::endl;
			std::cout << "[Answer 2] = I am an adventurer, and adventurers save the day!\n" << std::endl;
		}else {
			std::cout << "\n[Answer L] = Take the path to the left." << std::endl;
			std::cout << "[Answer R] = Take the path to the right.\n" << std::endl;
		}
		try{
			std::cin >> command;				
			if(this->room_version == 1){
				if(command == "1"){
					select = true;
					std::cout << "\nLab99Ex99: -I understand - bebop!" << std::endl;
					std::cout << "-Self-defense system activated!" << std::endl;
					std::cout << "-DCC Laser Activate - bebop!" << std::endl;
					std::cout << "You were ELIMINATED and nothing changed.\n" << std::endl;
					return false;
				}else if(command == "2"){
					std::cout << "\nLab99Ex99: -Bugs on my hardware - bebop!" << std::endl;
					std::cout << "-It was not part of my contract to cause" << std::endl;
					std::cout << "any harm to your species - bebop!" << std::endl;
					std::cout << "-I'll deal with this exception right now - bebop!" << std::endl;
					std::cout << "Thanks for the alert - bebop!" << std::endl;
					std::cout << "So, Lab99Ex99 produced a light," << std::endl;
					std::cout << "all the monsters in the woods disappeared and he set off for the sky." << std::endl;
					std::cout << "Even confused, the adventurer returns to the village" << std::endl;
					std::cout << "and explains that everything is solved." << std::endl;
					std::cout << "He takes his reward, and leaves for his next adventure.\n" << std::endl;
					select = true;
					return true;
				}else {
					throw std::exception();
				}
			}else if(this->room_version == 2){
				if(command == "1"){
				std::cout << "\n-I understand .." << std::endl;
				std::cout << "-The monster is on the right.\n" << std::endl;
					select = true;
					return false;
				}else if(command == "2"){
				std::cout << "\n-Wow, adventurers look really cool." << std::endl;
				std::cout << "-The monster is on the left." << std::endl;
				std::cout << "-Good luck, adventurer!\n" << std::endl;	
					select = true;
					return true;
				}else {
					throw std::exception();
				}
			}else {
				if(command == "L" || command == "l"){
					select = true;
					return false;
				}else if(command == "R" || command == "r"){
					select = true;
					return true;
				}else {
					throw std::exception();
				}
			}
		}catch(std::exception& e){
			std::cout << "\nInvalid choice. Please press:" << std::endl;
			if(this->room_version == 1 || this->room_version == 2)
				std::cout << "(Answer 1)-> 1 or (Answer 2)-> 2" << std::endl;
			else
				std::cout << "(left)-> l or (right)-> r" << std::endl;
		}
	}
	
	return false;
}
