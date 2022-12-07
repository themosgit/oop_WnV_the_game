#include "classes.h"
#include <iostream>

using namespace std;

//being
Being::Being(){}
Being::~Being(){}
int Being::get_posis() {
	cout << "\n x = " << x_coord <<"    "<<"y = " << y_coord << endl;
		return x_coord, y_coord;
}

//avatar
Avatar::Avatar(){}
Avatar::~Avatar(){}
int Avatar::get_filt() { return filter; }
void Avatar::use_filter() {
	if (filter > 0) {
		filter--;
		cout << "\nused filter,  new filter is " << filter << endl;
	}
	else
		cout << "\n dont have filter" << endl;
}
void Avatar::incr_filter() {
	filter++;
	cout << "\n new filter is " << filter << endl;
}

//creature
creature::creature() {
	health = 5;
	power = rand() % 3 + 1;
	defence = rand() % 2 + 1;
	giatriko = rand() % 2;
	//cout << "\nhealth="<<health<<"\npower = " << power << "\ndefence = " <<defence << "\ngiatriko = " << giatriko << endl;
}
creature::~creature() { }

int creature::get_health()  {return health; }
int creature::get_power()   {return power; }
int creature::get_defence() {return defence; }
int creature::get_giatriko(){return giatriko; }

void creature::get_damaged() {			//idia klash
	int n = power - defence;
	health = health - abs(n);
	cout << "\n new health is " << health << endl;
}

void creature::healing() {		//idia klash
	if (giatriko > 0){
		health = health + 3;
		giatriko--;
		cout << "\n new health=" << health << "\n new giatriko=" << giatriko << endl;}
	else
	cout << "\nnot enough giatriko" << endl;}

void creature::get_healed() {
	health = health + 3;
	cout << "\n creature got healed \nnew health=" << health << endl;
}

//Vampire

Vampire::Vampire():creature(){
	cout << "\n Creating Vampire" << endl;
	cout << "\nhealth=" << get_health() << "\npower = " << get_power() <<
		"\ndefence = " << get_defence() << "\ngiatriko = " << get_giatriko() << endl;
}
	
Vampire::~Vampire() {}

//werewolf
Werewolf::Werewolf():creature() {
		cout << "\n Creating Werewolf" << endl;
		cout << "\nhealth=" << get_health() << "\npower = " << get_power() <<
			"\ndefence = " << get_defence() << "\ngiatriko = " << get_giatriko() << endl;
}
Werewolf::~Werewolf(){}








