#include "mage.hpp"

Mage::Mage(std::string name) : Player(name){
	set_r_class("Mage");
	set_hp(10);
	set_init_hp(get_hp());
	set_ac(12);
	set_potions(3);
	set_dodge_buff(2);
	set_attack("Fireball", 0);
	set_m_attack("Fireball");
}	

short Mage::p_damage(){
	short damage;
	damage = get_dice(4);
	
	if (get_m_attack() == get_attack(0)){
		if(damage == 4){
			damage = get_dice(12) + get_dice(4);
			std::cout << "You used " << get_m_attack() << " - 1 D12 + Burn Effect - 1D4 and did " << damage << " damage!" << std::endl;
			return damage;
		}

		else{
			damage = get_dice(12);
			std::cout << "You used " << get_m_attack() << " - 1 D12 and did " << damage << " damage!" << std::endl;
			return damage;
		}
	}
	
	else if (get_m_attack() == get_attack(1)){
		damage = get_dice(4) + get_dice(4) + get_dice(4) + get_dice(4) + get_dice(4) + get_dice(4);
		std::cout << "You used " << get_m_attack() << " - 6 D4 and did " << damage << " damage!" << std::endl;
		return damage; 
	}

	else if (get_m_attack() == get_attack(2)){
		damage = get_dice(10) + get_dice(10) + get_dice(10) + get_dice(6);
		std::cout << "You used " << get_m_attack() << " - 3 D10 + 1 D6 and did " << damage << " damage!" << std::endl;
		return damage; 
	}
	
	return 0;
}

void Mage::level_up(){
	if (get_level() < 5){
		set_level(get_level() + 1);
		set_init_hp(get_init_hp() + 5);
		set_hp(get_init_hp());
		set_xp(get_xp() - std::abs(get_next_level()));
		set_next_level((300 * get_level() - get_xp()));
	}

		if (get_level() % 2 == 0)
			set_dodge_hability(get_dodge_hability() + 1);

		else if (get_level() == 3)
			set_attack("Blizzard", 1);
		
		else if (get_level() == 5)
			set_attack("Thunder Storm", 2);
}
