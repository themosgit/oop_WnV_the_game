#include "classes.h"
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;


int  main() {
	srand(time(NULL));
	int  num;
	cout << "\n how many vampires/werewolfs do you want;" << endl;
	cin >> num;
	int i = 0;
	Avatar a;
	
	//Vampire* vamp;
	//vamp = new Vampire[num];
	
	//vector<Vampire*> vamp;	
	//vector<Werewolf*> wer;
	//cout << "\n  Vampires:" << endl;
	//for (int i = 0; i <= num; i++) {
	//	Vampire v;
	//	vamp.push_back(&v);
		//i++;}
	//cout << "\n  Werewolves:" << endl;
	//for (int i = 0; i <= num; i++) {
	//	Werewolf w;
	//	wer.push_back(&w);
	//	i++;}
	vector <Werewolf> w;
	vector<Vampire> v;
	for (int i = 0; i < num; i++){
		Vampire a;
		// inserting objects to vector
		v.push_back(a);
		//cout << "\n" << a.get_health();
	}
	
	
	for (i = 0; i < v.size(); i++) {
		v[i].move();
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {			
				v[i].battle_or_heal(&v[j]);
			}}}
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i].is_alive() == true) {
			cout << "\n " << i;}}

	//cout << "\n" << v.size();
	while (v.size() > 0 && w.size() > 0) {
	}
	
}


