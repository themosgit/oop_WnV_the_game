#include "classes.h"
#include <iostream>
#include <string>
 
using namespace std;

//being
Being::Being(){}
Being::~Being(){}
int Being::get_posis() {
	cout << "\n x = " << x_coord <<"    "<<"y = " << y_coord << endl;
		return x_coord, y_coord;
}

int Being::get_x() { return x_coord; }
int Being::get_y() { return y_coord; }


//avatar
Avatar::Avatar(){}
Avatar::~Avatar(){}

int Avatar::get_filter() { return filter; }
void Avatar::use_filter() {
	if (filter > 0) {
		filter--;
		cout << "\nused filter,  new filter is " << filter << endl;
	}
	else cout << "\n dont have filter" << endl;
}
void Avatar::incr_filter() {
	filter++;
	cout << "\n new filter is " << filter << endl;
}

//creature
creature::creature():Being() {
	health = 4;
	power = rand() % 3 + 1;
	defence = rand() % 2 + 1;
	giatriko = rand() % 2;
	//cout << "\nhealth="<<health<<"\npower = " << power << "\ndefence = " <<defence << "\ngiatriko = " << giatriko << endl;
}
creature::~creature() { }

int creature::get_health(){return health;}
int creature::get_power() {return power;}
int creature::get_defence() {return defence;}
int creature::get_giatriko(){return giatriko;}
void creature::show(){
	cout << "\nhealth=" << get_health() << "\npower = " << get_power() <<
		"\ndefence = " << get_defence() << "\ngiatriko = " << get_giatriko() <<  endl;
}
bool creature::is_alive() { return true; }
void creature::get_healed() {
	if (health < 4) {
		health++;
		cout << "\n creature got healed \nnew health=" << health << endl;
	}
	else cout << "\n creature has max health";
}
void creature::battle_or_heal(creature* a) {
	int x = a->get_x() - get_x();
	int y = a->get_y() - get_y();
	if (abs(x) == 1 || abs(y) == 1) {
		if (a->is_vampire() == is_vampire()) {
			if (giatriko != 0)
			{		a->get_healed();
					giatriko--;	 }
			else cout << "\n not enough giatriko";
		}
		else if (a->is_vampire() != is_vampire()) {
			if (get_power() < a->get_power()){
				cout << "\n cant attack is stronger";}
			else if (get_power() >= a->get_power())
			{	a->health = a->health - abs(a->get_defence() - get_power());
				if (a->get_health() <= 0) {
					cout << "\n creature is dead";
					a->is_alive() == false;	}
				else  cout << "\n attacked creature health is " << a->get_health();
			}
		}
	}
	else {
		cout << "\n creature is not close ";
		get_posis();
		a->get_posis();
	}
}
void creature::move(){
	int n;
	if (is_vampire() == true)
		n= rand() % 8;
	else n=rand() % 4;
	cout << "\n case  " << n;
	switch (n) {
	case 0:	//doesnt move
		break;
	case 1: // paei deksia x++
		x_coord++;
		break;
	case 2: //paei aristera x--
		x_coord--;
		break;
	case 3: //paei panw y++
		y_coord++;
		break;
	case 4: //paei katv y--
		y_coord--;
		break;
	case 5: //diagwnia panw deksia x++,y++
		x_coord++;
		y_coord++;
		break;
	case 6: //diagwnia panw aristera y++,x--
		x_coord--;
		y_coord++;
		break;
	case 7:  //diagvnia katw deksia x++,y--
		x_coord++;
		y_coord++;
		break;
	case 8:  //diagwnia katw aristera x--, y--
		x_coord--;
		y_coord++;
		break;
	default:
		cout << "\n wrong" << endl;
	}
	get_posis();
}

//Vampire
Vampire::Vampire():creature(){
//	cout << "\n Creating Vampire" << endl;	
}
bool Vampire::is_vampire(){ return true; }
bool Vampire::is_werewolf(){return false;}
Vampire::~Vampire() {}


//werewolf
Werewolf::Werewolf():creature() {
	//	cout << "\n Creating Werewolf " << endl;
}
Werewolf::~Werewolf(){}
bool Werewolf::is_vampire(){ return false;}
bool Werewolf::is_werewolf()  {return true;}











