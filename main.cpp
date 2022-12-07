#include "classes.h"
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;


int  main() {
	Avatar a;

	srand(time(NULL));
	 int  num ;
	cout << "\n how many vampires/werewolfs do you want;" << endl;
	cin >> num;
	
	vector<Vampire> vamp;
	vector<Werewolf> wer;
	cout << "\nVampires:" << endl;
	for (int i = 0; i <= num; i++) {
		Vampire v;
		vamp.push_back(v);
		i++;
	}
	cout << "\nWerewolves:" << endl;
	for (int i = 0; i <= num; i++) {
		Werewolf w;
		wer.push_back(w);
		i++;
	}
	
	

	//cout << "\npower=" << f.get_power() << "\ndefence=" << f.get_defence() << "\ngiatriko=" << f.get_giatriko() << endl;

		

}