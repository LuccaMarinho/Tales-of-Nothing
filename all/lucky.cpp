#include "lucky.hpp"

Lucky::Lucky(std::string name) : Player(name){
	set_r_class("Lucky");
	set_hp(get_dice(20));
	set_init_hp(get_hp());
	set_ac(get_dice(20));
	set_potions(get_dice(4));
	set_dodge_buff(get_dice(4));
	set_attack("Do your best!", 0);
	set_m_attack("Do your best!");
}

short Lucky::p_damage(){
	short damage;
	damage = get_dice(4);

	if (get_m_attack() == get_attack(0)){
		switch(damage){
			case 1:
				damage = get_dice(6);
				std::cout << "You used " << get_m_attack() << " - 1 D6 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 2:
				damage = get_dice(8);
				std::cout << "You used " << get_m_attack() << " - 1 D8 and did " << damage << " damage!" << std::endl;
				return damage;

			case 3:
				damage = get_dice(10);
				std::cout << "You used " << get_m_attack() << " - 1 D10 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 4:
				damage = get_dice(12);
				std::cout << "You used " << get_m_attack() << " - 1 D12 and did " << damage << " damage!" << std::endl;
				return damage;
				break;
		}
	}

	else if (get_m_attack() == get_attack(1)){
		switch(damage){
			case 1:
			case 2:
				damage = get_dice(4) + get_dice(8) + get_dice(12);
				std::cout << "You used " << get_m_attack() << " - 1 D4 + 1 D8 + 1 D12 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 3:
			case 4:
				damage = get_dice(6) + get_dice(10) + get_dice(16);
				std::cout << "You used " << get_m_attack() << " - 1 D16 + 1 D10 + 1 D16 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

		}
	}

	else if (get_m_attack() == get_attack(2)){
		damage = get_dice(8);
		switch(damage){
			case 1:
				damage = get_dice(4) + get_dice(4) + get_dice(4);
				std::cout << "You used " << get_m_attack() << " - 3 D4 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 2:
				damage = get_dice(6) + get_dice(6) + get_dice(6);
				std::cout << "You used " << get_m_attack() << " - 3 D6 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 3:
				damage = get_dice(8) + get_dice(8) + get_dice(8);
				std::cout << "You used " << get_m_attack() << " - 3 D8 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 4:
				damage = get_dice(10) + get_dice(10) + get_dice(10);
				std::cout << "You used " << get_m_attack() << " - 3 D10 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 5:
				damage = get_dice(12) + get_dice(12) + get_dice(12);
				std::cout << "You used " << get_m_attack() << " - 3 D12 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 6:
				damage = get_dice(16) + get_dice(16) + get_dice(16);
				std::cout << "You used " << get_m_attack() << " - 3 D16 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 7:
				damage = get_dice(20) + get_dice(20) + get_dice(20);
				std::cout << "You used " << get_m_attack() << " - 3 D20 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

			case 8:
				damage = get_dice(4) + get_dice(6) + get_dice(8) + get_dice(10) + get_dice(12) + get_dice(16) + get_dice(20);
				std::cout << "You used " << get_m_attack() << " - 1 D4 + 1 D6 + 1 D8 + 1 D10 + 1 D12 + 1 D16 + 1 D20 and did " << damage << " damage!" << std::endl;
				return damage;
				break;

		}
	}
	
	return 0;
}

void Lucky::level_up(){
	if (get_level() < 5){
		set_level(get_level() + 1);
		set_init_hp(get_init_hp() + 5);
		set_hp(get_init_hp());
		set_xp(get_xp() - std::abs(get_next_level()));
		set_next_level((300 * get_level() - get_xp()));

		if (get_level() % 2 == 0)
			set_dodge_hability(get_dodge_hability() + 1);

		else if (get_level() == 3)
			set_attack("Lucky Kick", 1);
		
		else if (get_level() == 5)
			set_attack("Try to not die", 2);


	}
}