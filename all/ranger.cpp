#include "ranger.hpp"

Ranger::Ranger(std::string name) : Player(name){
	set_r_class("Ranger");
	set_hp(12);
	set_init_hp(get_hp());
	set_ac(16);
	set_potions(2);
	set_dodge_buff(1);
	set_attack("Quick Shot", 0);
	set_m_attack("Quick Shot");
}

short Ranger::p_damage(){
	short damage;
	if (get_m_attack() == get_attack(0)){
		damage = get_dice(8);
		std::cout << "You used " << get_m_attack() << " - 1 D8 and did " << damage << " damage!" << std::endl;

		if (dark){
			dark = false;
			std::cout << "The Darkness gave " << damage << " damage!" << std::endl;
			return damage * 2;
		}

		return damage;
	}

	else if (get_m_attack() == get_attack(1)){
		damage = get_dice(10) + get_dice(10);
		std::cout << "You used " << get_m_attack() << " - 2 D10 and did " << damage << " damage!" << std::endl;

		if (dark){
			dark = false;
			std::cout << "The Darkness gave " << damage << " damage!" << std::endl;
			return damage * 2;
		}

		return damage;
	}

	else if (get_m_attack() == get_attack(2)){
		set_hp(get_hp() - 3);
		dark = true;
		std::cout << "You used " << get_m_attack() << " your next attack will give the double of damage!" << std::endl;
		std::cout << "Also you lost 3 HP" << std::endl;
		return 0;
	}

	return 0;
}

void Ranger::level_up(){
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
			set_attack("Double Shot", 1);
		
		else if (get_level() == 5)
			set_attack("Dark Arrow", 2);
}