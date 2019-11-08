#ifndef INICIALIZER_H
#define INICIALIZER_H

#include <vector>
#include "event_battle.hpp"
#include "event_interaction.hpp"
#include <boost/variant.hpp>

class Inicializer{
	private:
		Event* _main_event;
		std::vector<Event*> _choices;
		void running_battle();
		void running_interaction();
		void game_end();
		void valid_number(int id_room);
	public:		
		Inicializer(Event *e);
		~Inicializer();
		void inicialize_objects();
		void inicialize_next_turn();  	//first = left = 0 = win = correct
										// second= right = 1 = run = wrong							
		void configure_next(int id_room);
		void configure_current(int id_room);
		void run_room();	
		std::vector<Event*>*get_choices();
};

#endif