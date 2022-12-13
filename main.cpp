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

	Vampire* vamp;
	vamp = new Vampire[num];
	
	//for (i = 0; i < num; i++)
	//	vamp[i].show();


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
}