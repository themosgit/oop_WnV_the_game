
#ifndef WNV_HEADER_H
#define WNV_HEADER_H

#endif //WNV_HEADER_H
#pragma once

class Graphics{
protected:
    int playble_width = 0;
    int playble_height = 0;
public:
    Graphics();
    virtual ~Graphics();
};

class Map : protected Graphics {
protected:
    int map_x = playble_width + 2;
    int map_y = playble_height + 2;
public:
    char** map;
    Map();
    int Get_mapx();
    int Get_mapy();
    void Display_map();
    ~Map();
};



class Being {
protected:
    int x_coord;
    int y_coord;
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
    char team_signate;
public :
    Avatar(Map*);
    ~Avatar();
    void choose_team();
    bool team_vamp();
    bool team_wer();
    void avatar_move(int ud, int lr, Map*);
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
    char signate;
    bool is_alive;
public:
    //int health;
    creature();
    ~creature();
    int get_health();
    int get_power();
    int get_defence() ;
    int get_giatriko();
    bool get_alive();
    virtual bool is_vampire()=0;
    virtual bool is_werewolf()=0;
    void move(Map*);
    void get_healed();
    void battle_or_heal(creature*, Map*);
    void show();
};

class Vampire : public creature {
public:
    Vampire(int i, Map*);//:creature() {}
    ~Vampire();
    bool is_vampire() ;
    bool is_werewolf() ;
};

class Werewolf: public creature  {
public:
    Werewolf(int i, Map*); //:creature() {}
    ~Werewolf();
    bool is_vampire();
    bool is_werewolf();
};
