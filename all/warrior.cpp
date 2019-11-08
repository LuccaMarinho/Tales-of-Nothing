#include "warrior.hpp"

Warrior::Warrior(std::string name) : Player(name){
	set_r_class("Warrior");
	set_hp(15);
	set_init_hp(get_hp());
	set_ac(14);
	set_potions(1);
	set_dodge_buff(1);
	set_attack("Sword Slash", 0);
	set_m_attack("Sword Slash");
}	

short Warrior::p_damage(){
	short damage;
	if (get_m_attack() == get_attack(0)){
		damage = get_dice(10);
		std::cout << "You used " << get_m_attack() << " - 1 D10 and did " << damage << " damage!" << std::endl;
		return damage;
	}

	else if (get_m_attack() == get_attack(1)){
		damage = get_dice(10) + get_dice(10);
		std::cout << "You used " << get_m_attack() << " - 2 D10 and did " << damage << " damage!" << std::endl;
		return damage;
	}

	else if (get_m_attack() == get_attack(2)){
		damage = get_dice(16) + get_dice(12) + get_dice(12);
		std::cout << "You used " << get_m_attack() << " - 1 D16 + 2 D12 and did " << damage << " damage!" << std::endl;
		return damage;
	}

	return 0;
}

void Warrior::level_up(){
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
			set_attack("Heavy Impact", 1);
		
		else if (get_level() == 5)
			set_attack("Brutal Strike", 2);
}