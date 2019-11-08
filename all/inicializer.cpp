#include "inicializer.hpp"

Inicializer::Inicializer(Event *e){
	this->_main_event = e;
}
Inicializer::~Inicializer(){
	for( unsigned int i=0; i<this->_choices.size(); i++){
		delete this->_choices[i];
	}
}
std::vector<Event*>* Inicializer::get_choices(){
	std::vector <Event*>*v = &this->_choices;
	return v;
}
void Inicializer::valid_number(int id_room){
	if( (id_room < 0) || ( id_room > 38 && id_room != 50) ){
		throw std::invalid_argument("Invalid number!");
	}
}
void Inicializer::running_battle(){
	int id = _main_event->get_current_room().first;
	boost::variant<Battle_room*, Basic_room*> v = _choices[id]->return_room()->get_room(); 
	boost::get<Battle_room*>(v)->run_battle(); 
	bool value = boost::get<Battle_room*>(v)->get_won_game();  
	_main_event->set_won(boost::get<Battle_room*>(v)->get_won_game()); 
	if(value == false && boost::get<Battle_room*>(v)->get_battle_run()==false) { 
		_main_event->get_messages(0);
		_main_event->set_game_on(false);
	}
	if(boost::get<Battle_room*>(v)->get_next_turn().first == 50 || boost::get<Battle_room*>(v)->get_next_turn().second == 50){
		this->game_end();
	}
	
	if(boost::get<Battle_room*>(v)->get_battle_run() && _main_event->get_game_on() == true){ 
		std::pair<short, Type> next;
		next.first =boost::get<Battle_room*>(v)->get_next_turn().second; 
		next.second = _choices[next.first]->return_room()->get_type();
		_main_event->set_next_room(next);
	}else if(_main_event->get_game_on() == true){
		std::pair<short, Type> next;
		next.first = boost::get<Battle_room*>(v)->get_next_turn().first; 
		next.second = _choices[next.first]->return_room()->get_type();
		_main_event->set_next_room(next);
	}
}
void Inicializer::running_interaction(){
	int id = _main_event->get_current_room().first;
	boost::variant<Battle_room*, Basic_room*> v = _choices[id]->return_room()->get_room();
	boost::get<Basic_room*>(v)->room_interaction();  
	if(boost::get<Basic_room*>(v)->get_end_game()){      
		_main_event->get_messages(0);
		_main_event->set_game_on(false);
	}

}
void Inicializer::run_room(){
	if(_main_event->get_current_room().second == Type::BATTLE){
		this->running_battle();
	}else{
		this->running_interaction();
	}
}
void Inicializer::configure_current(int id_room){
	try{
		this->valid_number(id_room);
	}
	catch(std::invalid_argument& i){
		id_room = 50;
		std::cout << i.what() << std::endl << std::endl;
	}

	
	std::pair<int, Type> current;

	current.first = id_room;
	
	if(id_room >=28){
		current.second = Type::BATTLE;
	}else
		current.second = Type::INTERACTION;
	_main_event->set_current_room(current);
}
void Inicializer::game_end(){
	if(_main_event->get_won() == true && _main_event->get_current_room().first== 35){
		_main_event->get_messages(1);
		_main_event->set_game_on(false);
	}

	else if(_main_event->get_won() == true && _main_event->get_current_room().first==37){
		_main_event->get_messages(1);
		_main_event->set_game_on(false);
	}

	else if( _main_event->get_current_room().first == 24){
		_main_event->get_messages(1);
		_main_event->set_game_on(false);
	}

	boost::variant<Battle_room*, Basic_room*> v = _choices[_main_event->get_current_room().first]->return_room()->get_room(); 
	if(_main_event->get_current_room().first == 25){
		if(boost::get<Basic_room*>(v)->choosing_way()){
			_main_event->get_messages(1);
			_main_event->set_game_on(false);
		}else{
			_main_event->get_messages(0);
			_main_event->set_game_on(false);
		}
	}
	
	else if(_main_event->get_current_room().first == 26 || _main_event->get_current_room().first == 27){
		_main_event->get_messages(0);
		_main_event->set_game_on(false);
	}
	else if(_main_event->get_player()->get_hp() == 0 && _main_event->get_current_room().first != 35 && _main_event->get_current_room().first!=37){
		_main_event->get_messages(0);
		_main_event->set_game_on(false);
	}
}
	
void Inicializer::configure_next(int id_room){
	try{
		this->valid_number(id_room);
	}
	catch(std::invalid_argument& i){
		id_room = 50;
		std::cout << i.what() << std::endl << std::endl;
	}
	
	boost::variant<Battle_room*, Basic_room*> v = _choices[id_room]->return_room()->get_room(); 
	
	if(id_room >= 28){
		if(boost::get<Battle_room*>(v)->get_next_turn().first == 50 || boost::get<Battle_room*>(v)->get_next_turn().second == 50){
			this->game_end();
		}
	}
	if(id_room < 28){
		if(boost::get<Basic_room*>(v)->get_next_turn().first == boost::get<Basic_room*>(v)->get_next_turn().second){
			if(boost::get<Basic_room*>(v)->get_next_turn().first == 50 || boost::get<Basic_room*>(v)->get_next_turn().second == 50){
				this->game_end();
			}else if(_main_event->get_game_on() == true){
				std::pair<short, Type> next;
				next.first = boost::get<Basic_room*>(v)->get_next_turn().first;
				next.second = _choices[next.first]->return_room()->get_type();
				_main_event->set_next_room(next);
			}
		}
		
		if(id_room == 8 || id_room == 9 || id_room == 10 || id_room == 11 || id_room == 14 ||id_room == 19 || id_room == 26 || id_room == 27){
			if(boost::get<Basic_room*>(v)->choosing_way()){
				if(boost::get<Basic_room*>(v)->get_next_turn().second == 50){
					_main_event->set_game_on(false);
					this->game_end();
				}
				else if(_main_event->get_game_on() == true){
					std::pair<short, Type> next;
					next.first = boost::get<Basic_room*>(v)->get_next_turn().second;
					next.second = _choices[next.first]->return_room()->get_type();
					_main_event->set_next_room(next);
				}
			}
			else{
				if(boost::get<Basic_room*>(v)->get_next_turn().first == 50){
					_main_event->set_game_on(false);
					this->game_end();
				}
				else if(_main_event->get_game_on() == true){
					std::pair<int, Type> next;
					next.first = boost::get<Basic_room*>(v)->get_next_turn().first;
					next.second = _choices[next.first]->return_room()->get_type();
					_main_event->set_next_room(next);
				}
			}
		}
	}
}
void Inicializer::inicialize_next_turn(){
	Room* event = nullptr;
	//healers classes 
	_choices[0]->set_next_class(_choices[21]->return_room(), _choices[21]->return_room());
	_choices[1]->set_next_class(_choices[21]->return_room(), _choices[21]->return_room());
	_choices[2]->set_next_class(_choices[35]->return_room(), _choices[35]->return_room());
	_choices[3]->set_next_class(_choices[32]->return_room(), _choices[32]->return_room());
	_choices[4]->set_next_class(_choices[31]->return_room(), _choices[31]->return_room()); 
	_choices[5]->set_next_class(_choices[34]->return_room(), _choices[34]->return_room());
	_choices[6]->set_next_class(_choices[11]->return_room(), _choices[11]->return_room());
	_choices[7]->set_next_class(_choices[26]->return_room(), _choices[26]->return_room());
	//direction classes
	_choices[8]->set_next_class(_choices[28]->return_room(), _choices[29]->return_room());
	_choices[9]->set_next_class(_choices[30]->return_room(), _choices[18]->return_room());
	_choices[10]->set_next_class(_choices[22]->return_room(), _choices[17]->return_room());
	_choices[11]->set_next_class(_choices[37]->return_room(), _choices[7]->return_room());
	//tip classes
	_choices[12]->set_next_class(_choices[13]->return_room(), _choices[13]->return_room());
	_choices[13]->set_next_class(_choices[9]->return_room(), _choices[9]->return_room()); 
	_choices[14]->set_next_class(_choices[31]->return_room(), _choices[4]->return_room());
	_choices[15]->set_next_class(_choices[6]->return_room(), _choices[6]->return_room());
	//damage classes
	_choices[16]->set_next_class(_choices[13]->return_room(), _choices[13]->return_room());
	_choices[17]->set_next_class(_choices[14]->return_room(), _choices[14]->return_room());
	_choices[18]->set_next_class(event, event);
	_choices[19]->set_next_class(_choices[17]->return_room(), _choices[25]->return_room());
	_choices[20]->set_next_class(event, event);
	//history classes
	_choices[21]->set_next_class(_choices[2]->return_room(), _choices[2]->return_room());
	_choices[22]->set_next_class(_choices[3]->return_room(), _choices[3]->return_room());
	_choices[23]->set_next_class(_choices[5]->return_room(), _choices[5]->return_room());
	_choices[24]->set_next_class(event, event);
	//quiz
	_choices[25]->set_next_class(event, event);
	_choices[26]->set_next_class(_choices[36]->return_room(), _choices[27]->return_room());
	_choices[27]->set_next_class(_choices[38]->return_room(), event);
	//battle classes
	_choices[28]->set_next_class(_choices[12]->return_room(), _choices[16]->return_room());
	_choices[29]->set_next_class(_choices[0]->return_room(), _choices[1]->return_room());
	_choices[30]->set_next_class(_choices[10]->return_room(), _choices[19]->return_room());
	_choices[31]->set_next_class(_choices[33]->return_room(), _choices[20]->return_room());
	_choices[32]->set_next_class(_choices[23]->return_room(), _choices[33]->return_room());
	_choices[33]->set_next_class(_choices[5]->return_room(), _choices[5]->return_room());
	_choices[34]->set_next_class(_choices[15]->return_room(), _choices[6]->return_room());
	//boss classes
	_choices[35]->set_next_class(event, event);
	_choices[36]->set_next_class(_choices[24]->return_room(), _choices[24]->return_room());
	_choices[37]->set_next_class(event, event);
	_choices[38]->set_next_class( _choices[24]->return_room(), _choices[24]->return_room());
}
void Inicializer::inicialize_objects(){
	Event *inter0 = new Event_interaction(0);
	inter0->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> a = inter0->return_room()->get_room(); 
	boost::get<Basic_room*>(a)->set_player(_main_event->get_player());
	_choices.push_back(inter0);

	Event *inter1 = new Event_interaction(1);
	inter1->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> b = inter1->return_room()->get_room(); 
	boost::get<Basic_room*>(b)->set_player(_main_event->get_player());
	_choices.push_back(inter1);

	Event *inter2 = new Event_interaction(2);
	inter2->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> c = inter2->return_room()->get_room(); 
	boost::get<Basic_room*>(c)->set_player(_main_event->get_player());
	_choices.push_back(inter2);

	Event *inter3 = new Event_interaction(3);
	inter3->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> d = inter3->return_room()->get_room(); 
	boost::get<Basic_room*>(d)->set_player(_main_event->get_player());
	_choices.push_back(inter3);

	Event *inter4 = new Event_interaction(4);
	inter4->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> e = inter4->return_room()->get_room(); 
	boost::get<Basic_room*>(e)->set_player(_main_event->get_player());
	_choices.push_back(inter4);

	Event *inter5 = new Event_interaction(5);
	inter5->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> f = inter5->return_room()->get_room(); 
	boost::get<Basic_room*>(f)->set_player(_main_event->get_player());
	_choices.push_back(inter5);

	Event *inter6 = new Event_interaction(6);
	inter6->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> g = inter6->return_room()->get_room(); 
	boost::get<Basic_room*>(g)->set_player(_main_event->get_player());
	_choices.push_back(inter6);

	Event *inter7 = new Event_interaction(7);
	inter7->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> h = inter7->return_room()->get_room(); 
	boost::get<Basic_room*>(h)->set_player(_main_event->get_player());
	_choices.push_back(inter7);

	Event *inter8 = new Event_interaction(8);
	boost::variant<Battle_room*, Basic_room*> i = inter8->return_room()->get_room(); 
	boost::get<Basic_room*>(i)->set_player(_main_event->get_player());
	inter8->set_player(_main_event->get_player());
	_choices.push_back(inter8);

	Event *inter9 = new Event_interaction(9);
	inter9->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> j = inter9->return_room()->get_room(); 
	boost::get<Basic_room*>(j)->set_player(_main_event->get_player());
	_choices.push_back(inter9);

	Event *inter10 = new Event_interaction(10);
	inter10->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> k = inter10->return_room()->get_room(); 
	boost::get<Basic_room*>(k)->set_player(_main_event->get_player());
	_choices.push_back(inter10);

	Event *inter11 = new Event_interaction(11);
	inter11->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> l = inter11->return_room()->get_room(); 
	boost::get<Basic_room*>(l)->set_player(_main_event->get_player());
	_choices.push_back(inter11);

	Event *inter12 = new Event_interaction(12);
	inter12->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> o = inter12->return_room()->get_room(); 
	boost::get<Basic_room*>(o)->set_player(_main_event->get_player());
	_choices.push_back(inter12);

	Event *inter13 = new Event_interaction(13);
	inter13->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> p = inter13->return_room()->get_room(); 
	boost::get<Basic_room*>(p)->set_player(_main_event->get_player());
	_choices.push_back(inter13);

	Event *inter14 = new Event_interaction(14);
	inter14->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> q = inter14->return_room()->get_room(); 
	boost::get<Basic_room*>(q)->set_player(_main_event->get_player());
	_choices.push_back(inter14);

	Event *inter15 = new Event_interaction(15);
	inter15->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> r = inter15->return_room()->get_room(); 
	boost::get<Basic_room*>(r)->set_player(_main_event->get_player());
	_choices.push_back(inter15);

	Event *inter16 = new Event_interaction(16);
	inter16->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> s = inter16->return_room()->get_room(); 
	boost::get<Basic_room*>(s)->set_player(_main_event->get_player());
	_choices.push_back(inter16);

	Event *inter17 = new Event_interaction(17);
	inter17->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> t = inter17->return_room()->get_room(); 
	boost::get<Basic_room*>(t)->set_player(_main_event->get_player());
	_choices.push_back(inter17);

	Event *inter18 = new Event_interaction(18);
	inter18->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> u = inter18->return_room()->get_room(); 
	boost::get<Basic_room*>(u)->set_player(_main_event->get_player());
	_choices.push_back(inter18);

	Event *inter19 = new Event_interaction(19);
	inter19->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> v = inter19->return_room()->get_room(); 
	boost::get<Basic_room*>(v)->set_player(_main_event->get_player());
	_choices.push_back(inter19);

	Event *inter20 = new Event_interaction(20);
	inter20->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> x = inter20->return_room()->get_room(); 
	boost::get<Basic_room*>(x)->set_player(_main_event->get_player());
	_choices.push_back(inter20);

	Event *inter21 = new Event_interaction(21);
	inter21->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> w = inter21->return_room()->get_room(); 
	boost::get<Basic_room*>(w)->set_player(_main_event->get_player());
	_choices.push_back(inter21);

	Event *inter22 = new Event_interaction(22);
	inter22->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> y = inter22->return_room()->get_room(); 
	boost::get<Basic_room*>(y)->set_player(_main_event->get_player());
	_choices.push_back(inter22);

	Event *inter23 = new Event_interaction(23);
	inter23->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> z = inter23->return_room()->get_room(); 
	boost::get<Basic_room*>(z)->set_player(_main_event->get_player());
	_choices.push_back(inter23);

	Event *inter24 = new Event_interaction(24);
	inter24->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> m = inter24->return_room()->get_room(); 
	boost::get<Basic_room*>(m)->set_player(_main_event->get_player());
	_choices.push_back(inter24);

	Event *inter25 = new Event_interaction(25);
	inter25->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> n = inter25->return_room()->get_room(); 
	boost::get<Basic_room*>(n)->set_player(_main_event->get_player());
	_choices.push_back(inter25);

	Event *inter26 = new Event_interaction(26);
	inter26->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> aa = inter26->return_room()->get_room(); 
	boost::get<Basic_room*>(aa)->set_player(_main_event->get_player());
	_choices.push_back(inter26);

	Event *inter27 = new Event_interaction(27);
	inter27->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> bb = inter27->return_room()->get_room(); 
	boost::get<Basic_room*>(bb)->set_player(_main_event->get_player());
	_choices.push_back(inter27);

	Event *battle0 = new Event_battle(0);
	battle0->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> cc = battle0->return_room()->get_room(); 
	boost::get<Battle_room*>(cc)->set_player(_main_event->get_player());
	_choices.push_back(battle0);

	Event *battle1 = new Event_battle(1);
	battle1->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> dd = battle1->return_room()->get_room(); 
	boost::get<Battle_room*>(dd)->set_player(_main_event->get_player());
	_choices.push_back(battle1);

	Event *battle2 = new Event_battle(2);
	battle2->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> ee = battle2->return_room()->get_room(); 
	boost::get<Battle_room*>(ee)->set_player(_main_event->get_player());
	_choices.push_back(battle2);

	Event *battle3 = new Event_battle(3);
	battle3->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> ff = battle3->return_room()->get_room(); 
	boost::get<Battle_room*>(ff)->set_player(_main_event->get_player());
	_choices.push_back(battle3);

	Event *battle4 = new Event_battle(4);
	battle4->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> gg = battle4->return_room()->get_room(); 
	boost::get<Battle_room*>(gg)->set_player(_main_event->get_player());
	_choices.push_back(battle4);

	Event *battle5 = new Event_battle(5);
	battle5->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> hh = battle5->return_room()->get_room(); 
	boost::get<Battle_room*>(hh)->set_player(_main_event->get_player());
	_choices.push_back(battle5);

	Event *battle6 = new Event_battle(6);
	battle6->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> ii = battle6->return_room()->get_room(); 
	boost::get<Battle_room*>(ii)->set_player(_main_event->get_player());
	_choices.push_back(battle6);

	Event *battle7 = new Event_battle(7);
	battle7->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> jj = battle7->return_room()->get_room(); 
	boost::get<Battle_room*>(jj)->set_player(_main_event->get_player());
	_choices.push_back(battle7);

	Event *battle8 = new Event_battle(8);
	battle8->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> kk = battle8->return_room()->get_room(); 
	boost::get<Battle_room*>(kk)->set_player(_main_event->get_player());
	_choices.push_back(battle8);

	Event *battle9 = new Event_battle(9);
	battle9->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> ll = battle9->return_room()->get_room(); 
	boost::get<Battle_room*>(ll)->set_player(_main_event->get_player());
	_choices.push_back(battle9);
	
	Event *battle10 = new Event_battle(10);
	battle10->set_player(_main_event->get_player());
	boost::variant<Battle_room*, Basic_room*> mm = battle10->return_room()->get_room(); 
	boost::get<Battle_room*>(mm)->set_player(_main_event->get_player());
	_choices.push_back(battle10);
	
}
