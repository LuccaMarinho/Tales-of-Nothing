#include "skeleton.hpp"

Skeleton::Skeleton(){
	this->name = "Skeletor";
	this->race = "Skeleton";
	this->level = 2;
	this->d_xp = 300;
	this->hp = 21;
	this->ac = 18;
	this->attacks[0] = "Bone Bone";
	this->attacks[1] = "Bone Throw";
	this->attacks[2] = "To the Bone";
	this->e_taunt = 13;
	this->dodge_fail = 1;
	this->potion_fail = 0;
	this->run_fail = 1;
}

short Skeleton::e_damage(){
	short damage;
	short attack = get_dice(4);
	if(hp > 7){
		if (attack <= 2){
			damage = get_dice(8);
			std::cout << std::endl << name << " used " << attacks[0] << " and did " << damage << " damage!" << std::endl;
			std::cout << "Also, it lost 1 HP" << std::endl;
			hp -= 1;
			return damage;
		}

		else if (attack >= 3){
			damage = get_dice(8);
			std::cout << std::endl << name << " used " << attacks[1] << " and did " << damage << " damage!" << std::endl;
			std::cout << "Also, it lost 1 AC" << std::endl;
			ac -= 1;
			return damage;
		}
	}
	
	else{
		damage = get_dice(6) + get_dice(4) + get_dice(4);
		std::cout << std::endl << name << " used " << attacks[2] << " and did " << damage << " damage!" << std::endl;
		std::cout << "Also, it healed 3 HP and 1 AC" << std::endl;
		hp += 1;
		ac += 1;
		return damage;
	}

	return 0;
}
