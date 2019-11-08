#ifndef GNOME_H
#define GNOME_H

#include "enemy.hpp"

class Gnome: public Enemy{
	public:
		Gnome();

		short e_damage() override;
};

#endif