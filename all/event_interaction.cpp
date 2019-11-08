#include "event_interaction.hpp"

Event_interaction::Event_interaction(short x):Event(){
	try{
		if( (x< 0) || ( x > 27) ){
			throw std::invalid_argument("Invalid number!");
		}
	}
	catch(std::invalid_argument& i){
		std::cout << i.what() << std::endl << std::endl;
		x= 0;
	}
	switch(x){
		case 0:
			{
				Basic_room *healer0 = new Life_elixir(this->selected_player);
				try{
					if(healer0 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer0->set_id(0);
				healer0->set_next_turn(21,21);
				this->room = new Room(healer0);
			}
			break;
		case 1:
			{
				Basic_room *healer1 = new Xp_room(this->selected_player);
				try{
					if(healer1 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer1->set_id(1);
				healer1->set_next_turn(21,21);
				this->room = new Room(healer1);
			}
			break;
		case 2:
			{
				Basic_room *healer2 = new Life_potion(this->selected_player);
				try{
					if(healer2 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer2->set_id(2);
				healer2->set_next_turn(35,35);
				this->room = new Room(healer2);
			}
			break;
		case 3:
			{
				Basic_room *healer3 = new Life_fairy(this->selected_player);
				try{
					if(healer3 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer3->set_id(3);
				healer3->set_next_turn(32,32);
				this->room = new Room(healer3);
			}
			break;
		case 4:
			{
				Basic_room *healer4 = new Life_fairy(this->selected_player);
				try{
					if(healer4 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer4->set_id(4);
				healer4->set_next_turn(31,31);
				this->room = new Room(healer4);
			}
			break;
		case 5:
			{
				Basic_room *healer5 = new Life_fairy(this->selected_player);
				try{
					if(healer5 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer5->set_id(5);
				healer5->set_next_turn(34,34);
				this->room = new Room(healer5);
			}
			break;
		case 6:
			{
				Basic_room *healer6 = new Life_fairy(this->selected_player);
				try{
					if(healer6 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer6->set_id(6);
				healer6->set_next_turn(11,11);
				this->room = new Room(healer6);
			
			}
			break;
		case 7:
			{
				Basic_room *healer7 = new Life_elixir(this->selected_player);
				try{
					if(healer7 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				healer7->set_id(7);
				healer7->set_next_turn(26,26);
				this->room = new Room(healer7);
			}

			break;
		case 8:
			{
			 	Basic_room *basic0 = new Left_right(this->selected_player); 
				try{
					if(basic0 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic0->set_id(8);
				basic0->set_next_turn(29, 28);
				this->room = new Room(basic0);
			}
			break;
		case 9:
			{
				Basic_room *basic1 = new Left_right(this->selected_player); 
				try{
					if(basic1 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic1->set_id(9);
				basic1->set_next_turn(30,18);
				this->room = new Room(basic1);
			}
			break;
		case 10:
			{
				Basic_room *basic2 = new Left_right(this->selected_player); 
				try{
					if(basic2 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic2->set_id(10);
				basic2->set_next_turn(22,17);
				this->room = new Room(basic2);
			}
			break;
		case 11:
			{
				Basic_room *basic3 = new Left_right(this->selected_player); 
				try{
					if(basic3 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic3->set_id(11);
				basic3->set_next_turn(37,7);
				this->room = new Room(basic3);
			}
			break;

		case 12:
			{
				Basic_room *basic4 = new Tip_room(this->selected_player, 1); //tip true
				try{
					if(basic4 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic4->set_id(12);
				basic4->set_next_turn(13,13);
				this->room = new Room(basic4);
			}
			break;
		case 13:
			{
				Basic_room *basic5 = new Tip_room(this->selected_player, 2); // pitfall tip
				try{
					if(basic5 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic5->set_id(13);
				basic5->set_next_turn(9,9);
				this->room = new Room(basic5);
			}
			break;
		case 14:
			{
				Basic_room *basic6 = new Tip_room(this->selected_player, 3); //tip lie
				try{
					if(basic6 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic6->set_id(14);
				basic6->set_next_turn(31,4);
				this->room = new Room(basic6);
			}
			break;
		case 15:
			{
				Basic_room *basic7 = new Tip_room(this->selected_player, 4); //tip truth
				try{
					if(basic7 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic7->set_id(15);
				basic7->set_next_turn(6,6);
				this->room = new Room(basic7);
			}
			break;
		case 16:
			{
				Basic_room *basic8 = new Dmg_npc(this->selected_player, 0); //constructor
				try{
					if(basic8 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic8->set_id(16);
				basic8->set_next_turn(13,13);
				this->room = new Room(basic8);
			}
			break;
		case 17:
		
			{
				Basic_room *basic9 = new Dmg_npc(this->selected_player, 1); //constructor
				try{
					if(basic9 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic9->set_id(17);
				basic9->set_next_turn(14,14);
				this->room = new Room(basic9);
			}
			break;
		case 18:
			{
				Basic_room *basic10 = new Mimic_death_room(this->selected_player);
				try{
					if(basic10 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic10->set_id(18);
				basic10->set_next_turn(50,50);
				this->room = new Room(basic10);
			}
			break;

		case 19:
			{			
				Basic_room *basic11 = new Pitfall_random(this->selected_player); //pitfall random
				try{
					if(basic11 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic11->set_id(19);
				basic11->set_next_turn(17,25);
				this->room = new Room(basic11);
			}
			break;
		case 20:
			{
				Basic_room *basic12 = new Abism_death_room(this->selected_player);
				try{
					if(basic12 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic12->set_id(20);
				basic12->set_next_turn(50,50);
				this->room = new Room(basic12);
			}
			break;
		case 21:
			{
				Basic_room *basic13 = new History_room(this->selected_player); //1
				try{
					if(basic13 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic13->set_id(21);
				basic13->set_next_turn(2,2);
				this->room = new Room(basic13);
			}
			break;
		case 22:
			{
				Basic_room *basic14 = new History_room(this->selected_player); //2
				try{
					if(basic14 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic14->set_id(22);
				basic14->set_next_turn(3,3);
				this->room = new Room(basic14);
			}
			break;
		case 23:
			{
				Basic_room *basic15 = new History_room(this->selected_player); //3
				try{
					if(basic15 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic15->set_id(23);
				basic15->set_next_turn(5,5);
				this->room = new Room(basic15);
			}
			break;

		case 24:
			{
				Basic_room *basic16 = new History_room(this->selected_player); //4
				try{
					if(basic16 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic16->set_id(24);
				basic16->set_next_turn(50,50);
				this->room = new Room(basic16);
			}
			break;
		case 25:
			{
				Basic_room *basic17 = new Quiz_room(this->selected_player, 1);	
				try{
					if(basic17 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic17->set_id(25);
				basic17->set_next_turn(50,50);
				this->room = new Room(basic17);
			}
			break;
		case 26:
			{
				Basic_room *basic18 = new Quiz_room(this->selected_player, 2); 	
				try{
					if(basic18 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic18->set_id(26);
				basic18->set_next_turn(36,27);
				this->room = new Room(basic18);
			}
			break;
		case 27:
			{
				Basic_room *basic19 = new Quiz_room(this->selected_player, 3); 
				try{
					if(basic19 == nullptr)
						throw std::runtime_error("Pointer is null");
		
				}catch( std::runtime_error& ia ) {
	    			std::cout << "Interaction not inicialized - Error:" << ia.what() << std::endl;
				}
				basic19->set_id(27);
				basic19->set_next_turn(38,50);
				this->room = new Room(basic19);
			}
			break;
			
		default:
			break;
	};		
}
Event_interaction::~Event_interaction(){
}
