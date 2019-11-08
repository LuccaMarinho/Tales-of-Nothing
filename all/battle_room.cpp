#include "battle_room.hpp"

Battle_room::Battle_room(Player *player, Enemy *enemy){
	this->_current_player = player;
	this->_chosen_enemy = enemy;
	this->_dodge = false;
	this->_battle_on = false;
	this->_battle_run = false;
	this->_damage = 0;
	this->_winner = Winner::ENEMY;
	this->_won_game = false;
	srand(time(NULL));
}
Battle_room::~Battle_room(){

	delete this->_chosen_enemy;
}
void Battle_room::set_player(Player *p){
	this->_current_player = p;
}
void Battle_room::set_battle_on(bool value_battle){
	this->_battle_on = value_battle;
}
bool Battle_room::is_battle_on(){
	return this->_battle_on;
}
int Battle_room::get_id(){
	return this->_id;
}
void Battle_room::set_id(int x){
	this->_id =x;
}
std::pair<short,short> Battle_room::get_next_turn(){
		return this->_next_turn;
}
void Battle_room::set_next_turn(short left, short right){
	this->_next_turn.first = left;
	this->_next_turn.second = right;
}
bool Battle_room::get_won_game(){
	return this->_won_game;
}
bool Battle_room::get_battle_run(){
	return this->_battle_run;
}

bool Battle_room::stop_battle(){
	if(this->_current_player->get_hp() <= 0){
		this->_winner = Winner::ENEMY;
		return true;
	}
	if(this->_chosen_enemy->get_hp() <= 0){
		this->_winner = Winner::PLAYER;
		this->_chosen_enemy->status();
		this->_current_player->set_xp(this->_current_player->get_xp() + this->_chosen_enemy->get_d_xp());
		this->_current_player->set_next_level(this->_current_player->get_next_level() - this->_current_player->get_xp());
		return true;
	}
	return false;
}
void Battle_room::define_attack(short i){
	switch(i){
		case 1:
			this->_current_player->set_m_attack(this->_current_player->get_attack(0));
			break;
		case 2:
			if(this->_current_player->get_attack(1) == "N/A"){
				std::cout << "Attack not avaible, choose another option." << std::endl;
				this->_current_player->set_m_attack(std::string("N/A"));
			}else 
				this->_current_player->set_m_attack(this->_current_player->get_attack(1));
			break;
		case 3:
			if(this->_current_player->get_attack(2) == "N/A"){
				std::cout << "Attack not avaible, choose another option." << std::endl;
				this->_current_player->set_m_attack(std::string("N/A"));
			}else 
				this->_current_player->set_m_attack(this->_current_player->get_attack(2));
			break;
		default:
			std::cout << "Incorrect number for attack." << std::endl;
			break;
	}
}
void Battle_room::player_attacking(){
	if(this->_current_player->get_m_attack() != "N/A"){
		if(this->_dice.roll_dice(20) > this->_chosen_enemy->get_ac()){
			this->_chosen_enemy->set_hp(this->_chosen_enemy->get_hp()- this->_current_player->p_damage());
			std::cout << std::endl << this->_chosen_enemy->get_name() <<" 's life: " << this->_chosen_enemy->get_hp() << std:: endl << std::endl;
		}else{
			std::cout << "You missed!" << std::endl << std::endl;
		}
	}
}
void Battle_room::enemy_attacking(){
	if(this->_battle_run == false){
		if((this->_dodge == false) && this->_dice.roll_dice(20) > this->_current_player->get_ac()){
			this->_current_player -> set_hp(this->_current_player->get_hp() - this->_chosen_enemy->e_damage());
			std::cout << std::endl << "Your current life: " << this->_current_player->get_hp()  << std::endl<< std::endl;
		}
		else if(this->_dodge == false ){
			std::cout << std::endl << this->_chosen_enemy->get_name() << " missed!" << std::endl << std::endl;
		}
	}
	this->_dodge = false;
}
void Battle_room::run_battle(){;
	this->_battle_on = true;
	this->_chosen_enemy->status();
	while(this->_battle_on){

		if(stop_battle()){
			if(this->_winner == Winner::PLAYER){ 
				std::cout << "You won the battle!" << std::endl;
				this->_won_game = true;
			}else{
				std::cout << "You lost the battle" << std::endl;
			} 
			this->_current_player->status();
			this->_battle_on = false;
		}
		this->_current_decision = this->_current_player->p_decision();
		switch(this->_current_decision){
			case 1:
				define_attack(1);
				player_attacking();
				break;
			case 2:
				define_attack(2);
				player_attacking();
				break;
			case 3:
				define_attack(3);
				player_attacking();
				break;
			case 4: //option dodge
				this->_current_player->set_ac(this->_current_player->get_ac() + this->_current_player->get_dodge_buff());
				if(this->_current_player->get_ac() > this->_dice.roll_dice(20)){
					this->_dodge =true;
					this->_damage = (this->_current_player->d_damage(this->_current_player->get_dodge_hability()) );
					this->_chosen_enemy->set_hp(this->_chosen_enemy->get_hp() - this->_damage);
					std::cout << "You dodged his attack and did " << this->_damage << " damage!" << std::endl << std::endl;
					std::cout << this->_chosen_enemy->get_name() << " 's life: " << this->_chosen_enemy->get_hp() << std::endl << std::endl;	
				}else {
					this->_damage = ( this->_chosen_enemy->p_fail(this->_chosen_enemy -> get_dodge_fail()) );
					this->_current_player-> set_hp(this->_current_player->get_hp() - this->_damage);
					std::cout << "You failed to dodge and took " << this->_damage << " damage!" << std::endl << std::endl;
				}
				this->_current_player->set_ac(this->_current_player->get_ac() - this->_current_player->get_dodge_buff());
				break;			
			case 5: //option potion
				if(this->_current_player->get_ac() > this->_dice.roll_dice(20)){
					this->_dodge = (true);
					std::cout << "You dodged his attack " << std::endl;
					this->_current_player->p_potion_heal();
				}else {
					this->_damage = (this->_chosen_enemy->p_fail(this->_chosen_enemy->get_potion_fail()));
					std::cout << "You failed to dodge and took "<< this->_damage << " damage!" << std::endl;
					this->_current_player->p_potion_heal();
				}
				break;
			case 6: //option run
				if(this->_dice.roll_dice(20) > this->_chosen_enemy-> get_e_taunt()){
					std::cout << "You dodged his attack and ran as faster as you could, you're safe now!" << std::endl;
					this->_current_player->status();
					this->_battle_run = true;
					this->_battle_on = false;
				}else{
					this->_damage = (this->_chosen_enemy->p_fail(this->_chosen_enemy->get_run_fail()));
					std::cout << "You tried to run but tripped, the battle continues..." << std::endl;
					std::cout << "You took " << this->_damage << " damage!" << std::endl;
					break;
				}
			default:
				break;
				
			} // end switch
		enemy_attacking();
		if(stop_battle()){
			if(this->_winner == Winner::PLAYER){ 
				std::cout << "You won the battle!"<<  std::endl;
				this->_won_game = true;
			}else{
				std::cout << "You lost the battle" <<  std::endl;
			} 
			this->_current_player->status();
			this->_battle_on = false;
		}
	}	
} 
