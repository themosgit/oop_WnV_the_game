#include "classes.h"
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;


int  main() {
	srand(time(NULL));
	
	Avatar a;
	a.choose_team();
	
	int  num;
	cout << "\n how many vampires/werewolfs do you want;" << endl;
	cin >> num;
	int i = 0;
	
	//Vampire* vamp;
	//vamp = new Vampire[num];

	//vector<Vampire*> vamp;	
	//vector<Werewolf*> wer;
	//for (int i = 0; i <= num; i++) {
	//	Vampire v;
	//  Werewolf w;
	//	vamp.push_back(&v);
	//  wer.push_back(&w);
		//i++;}

	//vector<Vampire*> vamp;
	//vector<Werewolf*> wer;
	//for (int i = 0; i <= num; i++) {
	//	vamp.push_back(new Vampire);
	//  wer.push_back(new Werewolf);
		//i++;}

	vector <Werewolf> w;
	vector<Vampire> v;
	for (int i = 0; i < num; i++) {
		Vampire a;
		Werewolf b;
		v.push_back(a);
		w.push_back(b);
		//cout << "\n" << a.get_health();
	}

	for (i = 0; i < v.size(); i++) {
		//i = rand() % v.size();
			//v[i].move();
		//cout << "\n" << i;
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				v[i].battle_or_heal(&v[j]);
			}
		}//}
		for (int j = 0; j < v.size(); j++) {
			if (w[j].is_alive() == true)
				v[i].battle_or_heal(&w[j]);
		}
	}
	//int wer = 1;
	//while (wer > 0) {
		//int f = 0;
		//for (int j = 0; j < v.size(); j++) {
			//if (w[j].is_alive() == true)
				//f++;}
	//	cout << "\nf= " << f;
	//	wer = f;}

		//while (v.size() > 0 && w.size() > 0) {}

	
}

