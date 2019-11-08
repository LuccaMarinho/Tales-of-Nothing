#include "event.hpp"

Event::Event(){
	this->_game_on= false;
	this->_won=false;
	this->selected_player = nullptr;
	this->room = nullptr;
	this->_messages.push_back(std::string("You lost the game because you are dead!Try again another time!!"));
	this->_messages.push_back(std::string("You won the game!!Congratulations!!Play again to find different routes you could have taken!"));
}
Event::~Event(){
	delete this->room;
}
Room * Event::return_room(){
	return this->room;
}
std::pair<Room*, Room*> Event::get_next_class(){
	return this->_next_class;
}
void Event::set_next_class(Room *left,Room *right){
	this->_next_class.first = left;
	this->_next_class.second = right;
}
void Event::set_player(Player* play){
	this->selected_player = play;
}
Player* Event::get_player(){
	return this->selected_player;
}
void Event::set_game_on(bool value_game){
	this->_game_on =value_game;
}
bool Event::get_game_on(){
	return this->_game_on;
}
void Event::set_won(bool value_won){
	this->_won = value_won;
}
bool Event::get_won(){
	return this->_won;
}
void Event::set_current_room(std::pair<short, Type> a){
	this->_current_room = a;
}
std::pair< short, Type>Event::get_current_room(){
	return this->_current_room;
}
void Event::set_next_room(std::pair<short, Type> a){
	this->_next_room = a;
}
std::pair< short, Type >Event::get_next_room(){
	return this->_next_room;
}
void Event::insert_message(std::string text){
	this->_messages.push_back(text);
}
void Event::get_messages(short i){
	std::cout << this->_messages[i] << std::endl;
}
void Event::game_start(){

	std::cout << " Welcome to Nothing Woods" << std::endl;

	std::cout << " Tutorial: \n\t1. After you choose your player you won't be able to change it"
					<< std::endl<< "\t2. When you're asked to choose between options that goes from 1 until 6, please press the corresponding number in your keyboard key"
	                << std::endl<< "\t3. When you're asked to choose between left and right, please press the L or R in your keyboard"
	                << std::endl<< "\t4. When you're asked to choosed between two answers, please press 1 or 2 in your keyboard"
	                << std::endl<< "\t5. During the game you will face battles against different enemies and encounter rooms where you will find objects and people to interact with"
	                << std::endl<< "\t6. Pay attention to all the information received from other characters because it will help you during your path"
	                << std::endl<< "\t7. At each turn of the battle you and your enemy each have one action, and you will have 6 options to choose from:"
	                << std::endl<< "\t\t1st You will attack using your first attack, is the only one you have when you start the game, you will throw a dice, and if"
	                         << "the value is greater than the enemy's armor, you will cause him damage, otherwise your attack won't reach the enemy"
	                << std::endl<< "\t\t2nd You will atack using your second attack, you will get this attack when you increase your level, you will be notified when you get it,"
	                         << "so don't try to use it before, otherwise you will lose your action in the current turn"
	                << std::endl<< "\t\t3rd You will attack using your third attack, the same rule explained for the attack 2 is valid"
	                << std::endl<< "\t\t4rt You will try to dodge the enemy's attack, if you are able to dodge it, the enemy will suffer a damage correspoding to the class you have chosen,"
	                         << "otherwise, if you fail to dodge, you will suffer a damage from the enemy"
	                << std::endl<< "\t\t5th You will try to use a potion to restore your life, and try do dodge the enemy's attack, and if you fail you" 
	                         << "will suffer a damage corresponding to your enemy's strengh, but you will still be able to use your potion"
	                << std::endl<< "\t\t6th You will try to  run from the battle, but if you can't be fast enough you will suffer damage from the enemy " << std:: endl;
}

short Event::valid_name(std::string s){
	short result = 0;
	for(size_t n = 0; n < s.length(); n++){
		if (isdigit(s[n]) ){
			result = 1;
			break;
		}
		if( (s[n] >= '!' && s[n] <= '/') || (s[n] >= ':' && s[n] <= '@')
			|| (s[n] >= '[' && s[n] <= '`') || (s[n] >= '{' && s[n] <= '_') ){
			result = 2;
			break;
		}		
	} 

	bool r = true;
	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        if (*it != ' '){
        	r = false;
        }
    }
	if(r){
		result = 3;
	}

	return result;
}
void Event::pick_player(){
	std::string name;
	this->_game_on = true;
	while(true){
		std::cout << "Your name can only contain letters." << std::endl;
		std::cout << "What's your name?: " << std::endl;

		try{
			getline(std::cin, name);
			if(valid_name(name) == 1){
				throw std::invalid_argument("Invalid name!You wrote a number!");
			}else if(valid_name(name) == 2){
				throw std::invalid_argument("Invalid name!You wrote a non-alphanumeric character!");
			}else if(valid_name(name) == 3){
				throw std::invalid_argument("Invalid name!Your name can't contain blank spaces!");
			}else{
				break;
			}
		}
		catch(std::invalid_argument& i){
			std::cout << i.what() << std::endl << std::endl;
		}
	}

	std::cout << std::endl << "Choose your class" << std::endl;

	std::cout << std::endl << "Mage" << std::endl << "HP: 10  AC: 12  Attack: Fireball (Burn Chance - 25%)  Damage: 1D12" << std::endl << "Potions: 3 (+5HP) Dodge Buff: +2" << std::endl;
	std::cout << std::endl << "Warrior" << std::endl << "HP: 15  AC: 14  Attack: Sword Slash  Damage: 1D10 Potions: 1 (+5HP) Dodge Buff: +1" << std::endl;
	std::cout << std::endl << "Ranger" << std::endl << "HP: 12  AC: 16  Attack: Quick Shot  Damage: 1D8  Potions: 2 (+5HP)  Dodge Buff: +1" << std::endl;
	std::cout << std::endl << "Lucky" << std::endl <<"HP: ALEATORIO  AC: ALEATORIO  Attack: Do your best!  Damage: ALEATORIO  Potions: ALEATORIO (+5HP)  Dodge Buff: ALEATORIO" << std::endl << std::endl;
	//int result;
	std::string decision;
	while(true){
		
			std::cout << "What's your class?:" << "[1]Mage [2]Warrior [3]Ranger [4]Lucky : " << std::endl;
		try{	
			std::cin >> decision;
			std::cout << std::endl;

			if((decision >= "a" && decision <= "z") || (decision >= "A" && decision <= "Z")){
				throw std::invalid_argument("Invalid character!");
			}

			else if((decision >= "!" && decision <= "/") || (decision >= ":" && decision <= "@"))
				throw std::invalid_argument("Invalid character!");

			else if((decision >= "[" && decision <= "`") || (decision >= "{" && decision <= "~"))
				throw std::invalid_argument("Invalid character!");

			else if((atoi(decision.c_str()) <= 0) || (atoi(decision.c_str()) >= 5)){
				throw std::invalid_argument("Invalid number!");;
			}
			else{
				break;
			}
		}
		catch(std::invalid_argument& i){
			std::cout << i.what() << std::endl << std::endl;
		} 
	}
	int result = (atoi(decision.c_str()));
	
	switch(result){
		case 1:
			this->selected_player = new Mage(name);
			break;
		case 2:
			this->selected_player = new Warrior(name);
			break;
		case 3:
			this->selected_player = new Ranger(name);
			break;
		case 4:
			this->selected_player = new Lucky(name);
			break;
		default:
			this->selected_player = new Mage(name);
			break;
	}
	try{
		if(this->selected_player == nullptr)
			throw std::runtime_error("Pointer is null");
		
	}catch( std::runtime_error& ia ) {
	    std::cout << "Player not inicialized - Error:" << ia.what() << std::endl;
	}
}
