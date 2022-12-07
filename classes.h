#pragma once

#include<iostream>

class Being {
	//protected:
	int x_coord=2;
	int y_coord=2;

public:
	Being();
	~Being();

	int get_posis(); 
	//void virtual move();
};

class Avatar  :public Being {
	protected:
		int filter = 1; 
	//	bool team; 
	public :
	Avatar();
	~Avatar();
		int get_filt();
	//void move();
	//void set_team();
	void use_filter();	//heal team
	void incr_filter(); // auxisi filtro
	
};

class creature :public Being {
	//protected:
		
	   int health;// = H;
		int power;// = rand() % 3 + 1;
		int defence;// = rand() % 2 + 1;
		int giatriko;// = rand() % 2;

	public:
		creature();
		~creature();
		int get_health();
		int get_power() ;
		int get_defence() ;
		int get_giatriko();

		
		void get_damaged();   // -- health
		void get_healed();	  // ++ health 
		void healing();	      // -- giatirko if giatriko !=0 
	//	void attack();
		//	virtual void move()=0 ;
};

class Vampire : public creature {
	public:
		Vampire();//:creature() {}
		~Vampire();

//		void move();
};

class Werewolf: public creature  {
	public:
		Werewolf(); //:creature() {}
		~Werewolf();

//		void move();
};


