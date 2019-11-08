#include "event_battle.hpp"

Event_battle::Event_battle(short x):Event(){
	try{
		if( (x< 0) || ( x > 10) ){
			throw std::invalid_argument("Invalid number!");
		}
		
	}
	catch(std::invalid_argument& i){
		std::cout << i.what() << std::endl << std::endl;
		x= 0;
	}
	switch(x){
		case 0 :
			{
				Enemy* enemy0 = new Slime(1);
				try{
					if(enemy0 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}

				this->room = new Room (this->selected_player, enemy0, 28);
				}
			break;
		case 1 :
			{
				Enemy* enemy1 = new Pumpkin(2);
				try{
					if(enemy1 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy1, 29);
			}
			break;
		case 2 :
			{	
			Enemy* enemy2 = new Skeleton();
			try{
					if(enemy2 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy2, 30);
			}
			break;
		case 3 :
			{
				Enemy* enemy3 = new Gnome();
				try{
					if(enemy3 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy3, 31);
			}
			break;
		case 4 :
			{
				Enemy* enemy4 = new Wolf();
				try{
					if(enemy4 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy4, 32);

			}
			break;
		case 5 :
			{
				Enemy* enemy5 = new Slime(4, 600);
				try{
					if(enemy5 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy5, 33);
			
			}
			break;
		case 6 :
			{
				Enemy* enemy6 = new Pumpkin(5, 900);
				try{
					if(enemy6 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy6, 34);
		
			}
			break;
		case 7 :
			{
				Enemy* enemy7 = new Boss();
				try{
					if(enemy7 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy7, 35);
			}
			break;
		case 8 :
			{
				Enemy* enemy8 = new Boss(5);
				try{
					if(enemy8 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy8, 36);
			}
			break;
		case 9 :
			{
				Enemy* enemy9 = new Boss(7,1000);
				try{
					if(enemy9 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy9, 37);
			}
			break;
		case 10 :
			{
				Enemy* enemy10 = new Boss(7,1000);
				try{
					if(enemy10 == nullptr)
						throw std::runtime_error("Pointer is null");
			
				}catch( std::runtime_error& ia ) {
		    		std::cout << "Enemy not inicialized - Error:" << ia.what() << std::endl;
				}
				this->room = new Room (this->selected_player, enemy10, 38);
			}
			break;
		default:
			break;
	};

}
Event_battle::~Event_battle(){

}

