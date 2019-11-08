#include "event.hpp"
#include "room.hpp"
#include "event_battle.hpp"
#include "event_interaction.hpp"
#include "inicializer.hpp"
#include <vector>
#include <memory>

/**
 * @mainpage
 * @brief RPG Game's Main Page.
 * @author Lais Lima (main file).
 * @author Lucas Marinho (documentation).
 * @section intro_sec Introduction
 * The game was developed to make a RPG Game's Experience.
 * 
 * @section compile_sec Compile
 * To compile this code you need to do "make" via terminal in the folder where "makefile" is.
 * If the make doesn't work or link, just delete the files in build and build_test folders.
 * 
 * @section exe_sec Execute
 * To execute the game you just need to do "./game" via terminal, after doing the "make".
 * 
 * @section compile_test_sec Compile Test
 * To compile the test you need to do "make test" via terminal in the folder where "makefile" is. 
 * If the make doesn't work or link, just delete the files in build and build_test folders.
 *
 * @section exe_test_sec Execute
 * To execute the tests you just need to do "./game_test" via terminal, after doing the "make test".
 */


const int FIRSTROOM = 8;

int main(){

	Event *Main_event = new Event();
	std::vector<Event*>* choices;
	Inicializer *Narrative = new Inicializer(Main_event);
	
	Main_event->game_start();
	Main_event->pick_player();
	Narrative->inicialize_objects();
	Narrative->inicialize_next_turn();

	
	Narrative->configure_current(FIRSTROOM);
	Narrative->run_room();
	choices = Narrative->get_choices();
	std::vector<Event*> &vr = *choices;
	boost::variant<Battle_room*, Basic_room*> v = vr[FIRSTROOM]->return_room()->get_room();
	Narrative->configure_next(boost::get<Basic_room*>(v)->get_id());

	Narrative->configure_current(Main_event->get_next_room().first);

	while(Main_event->get_game_on()){
		Narrative->run_room();
		if(Main_event->get_game_on() == false)
			break;
		Narrative->configure_next(Main_event->get_current_room().first);
		if(Main_event->get_game_on() == false)
			break;
		Narrative->configure_current(Main_event->get_next_room().first);
		if(Main_event->get_game_on() == false)
			break;
		
	}
	
	if(!Main_event->get_game_on()){
		delete Main_event->get_player();
		delete Main_event;
		delete Narrative;
	}

	return 0;
}