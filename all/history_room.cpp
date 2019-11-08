#include "history_room.hpp"

History_room::History_room(Player* p) : Basic_room(p) {
	history_version++;
	if(history_version == 4){
		this->texts.push_back("\n???: -Bipi-bopi !!!!!");
		this->texts.push_back("The monster falls back defeat and its lights go out");
		this->texts.push_back("Shortly after his lights reign and he rises");
		this->texts.push_back("???: -System restarted successfully - bebop!");
		this->texts.push_back("-Hello living creature of the planet PDS2.2019 / 1 - bebop!");
		this->texts.push_back("-I am the robot Lab99Ex99 model VPL - bebop!");
		this->texts.push_back("I came to your planet due to an accident involving an asteroid");
		this->texts.push_back("and I ended up being sucked by the gravity of your planet - bebop!");
		this->texts.push_back("-The configurations of my systems have had problems,");
		this->texts.push_back("I ended up entering in Auto-Defense mode");
		this->texts.push_back("and activating the protocol Monters_spaw - bebop!");
		this->texts.push_back("-Thank you for helping me get back to normal - bebop!");
		this->texts.push_back("-Accept this as thanks - bebop!");
		this->texts.push_back("You received a strange object named Xiamin ...");
		this->texts.push_back("-Disabling protocol Monsters_spaw - bebop!");
		this->texts.push_back("-Now, I must return to my journey - bebop!");
		this->texts.push_back("And so, Lab99Ex99, flies through the sky");
		this->texts.push_back("flaming flames of his feet");
		this->texts.push_back("Even confused, the adventurer returns to the village");
		this->texts.push_back("and explains that everything is solved.");
		this->texts.push_back("He takes his reward, and leaves for his next adventure.");
		this->texts.push_back("\nTHE END\n");
	}else if(history_version == 3){
		this->texts.push_back("\nFairy: -Oh! You managed to defeat that scary creature!");
		this->texts.push_back("-You are here to save the forest, are not you?");
		this->texts.push_back("-That bright being, he's resting at the end of the woods.");
		this->texts.push_back("As scared as I was, I followed him that night");
		this->texts.push_back("and since he stopped, he does not even move a finger.");
		this->texts.push_back("-He said some strange things before bed, like:");
		this->texts.push_back("Bipi-bopi.");
		this->texts.push_back("-He does not look aggressive like the others,");
		this->texts.push_back("maybe you should talk to him.");	
		this->texts.push_back("-Well, that's all I know, good luck!");	
		this->texts.push_back("-Now I have to look for my sister!");	
		this->texts.push_back("-I have not seen her since the incident.\n");	
	}else if(history_version == 2){
		this->texts.push_back("\nFairy: -Oh! Hey you!");
		this->texts.push_back("-I saw you defeating that dangerous being.");
		this->texts.push_back("-You are here to rid the woods of these beings,");
		this->texts.push_back("are not you?");
		this->texts.push_back("-Know then that the mysterious light is actually");
		this->texts.push_back("a creature as well.");
		this->texts.push_back("-Another fairy told me that this creature left");
		this->texts.push_back("the crash site and headed toward the bottom of the forest.");
		this->texts.push_back("She also told me that these smaller creatures came out");
		this->texts.push_back("of the same place as the other.");
		this->texts.push_back("-Well, that's all I know, good luck!");
		this->texts.push_back("-Now I have to look for my sister!");
		this->texts.push_back("-I have not seen her since the incident.\n");
	}else if(history_version == 1){
		this->texts.push_back("\nFairy: -Oh! Who are you? And what are you doing here?");
		this->texts.push_back("-I see, you came to unravel the mystery of the light");
		this->texts.push_back("that fell from the sky!");
		this->texts.push_back("-In that case, I'll tell you everything I know:");		
		this->texts.push_back("-That night, when the light struck the woods,");
		this->texts.push_back("I could see a glittering being coming out");
		this->texts.push_back("of where the impact had been");
		this->texts.push_back("and going into the woods.");		
		this->texts.push_back("His body was strange,");
		this->texts.push_back("it seemed to be made of something that");
		this->texts.push_back("does not exist in nature.");	
		this->texts.push_back("Soon after, these dangerous beings also");	
		this->texts.push_back("came out of the hole.");	
		this->texts.push_back("-Well, that's all I know, good luck!\n");	
	}
}
void History_room::room_interaction(){
	this->print_texts();
}
