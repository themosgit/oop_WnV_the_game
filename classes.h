#pragma once

#include<iostream>
#include<string>

class Being {
	protected:
	int x_coord=2;
	int y_coord=2;

public:
	Being();
	~Being();
	int get_posis(); 
	int get_x();
	int get_y();
};

class Avatar  :public Being {
	protected:
		int filter = 1; 
		bool team_V;
		bool team_W;
	public :
	Avatar();
	~Avatar();
	void choose_team();
	bool team_vamp();
	bool team_wer();
	//void get_team();
		int get_filter();
	void use_filter();	//heal team
	void incr_filter(); // auxisi filtro
};

class creature :public Being {
	protected:
//private:
	    int health; // = H;
		int power; // = rand() % 3 + 1;
		int defence;// = rand() % 2 + 1;
		int giatriko;// = rand() % 2;
		
	public:
		//int health;
		creature();
		 ~creature();
		int get_health();
		int get_power();
		int get_defence() ;
		int get_giatriko();
		bool is_alive();
		virtual bool is_vampire()=0;
		virtual bool is_werewolf()=0;
		void move();
		void get_healed();
		void battle_or_heal(creature*);
		void show();
};

class Vampire : public creature {
	
	public:
		Vampire();//:creature() {}
		~Vampire();
		bool is_vampire() ;
		bool is_werewolf() ;		
};

class Werewolf: public creature  {
	public:
		Werewolf(); //:creature() {}
		~Werewolf();
		bool is_vampire();
		bool is_werewolf();		
};


