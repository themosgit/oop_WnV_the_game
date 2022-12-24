
#ifndef WNV_HEADER_H
#define WNV_HEADER_H

#endif //WNV_HEADER_H
#pragma once

class Graphics{
protected:
    int playble_height = 0;
    int playble_width = 0;
public:
    Graphics();
    virtual ~Graphics();
};

class Map : protected Graphics {
protected:
    int map_y = playble_height + 2;
    int map_x = playble_width + 2;
public:
    char** map;
    Map();
    int Get_mapx() const;
    int Get_mapy() const;
    void Display_map() const;
    ~Map();
};



class Being {
protected:
    int x_coord{};
    int y_coord{};
public:
    Being();
    ~Being();
    int get_posis();
    int get_x() const;
    int get_y() const;
};

class Avatar  :public Being {
protected:
    int filter = 1;
    bool team_V{};
    bool team_W{};
    char team_signate{};
public :
    Avatar(Map*);
    ~Avatar();
    void choose_team();
    bool team_vamp() const;
    bool team_wer() const;
    void avatar_move(int ud, int lr, Map*);
    //void get_team();
    int get_filter() const;
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
    char signate{};
    bool is_alive;
public:
    //int health;
    creature();
    ~creature();
    int get_health() const;
    int get_power() const;
    int get_defence() const;
    int get_giatriko() const;
    bool get_alive() const;
    virtual bool is_vampire()=0;
    virtual bool is_werewolf()=0;
    void move(Map*);
    void get_healed();
    void battle_or_heal(creature*, Map*);
    void show() const;
};

class Vampire : public creature {
public:
    Vampire();//:creature() {}
    void initV(int i, Map*);
    ~Vampire();
    bool is_vampire() ;
    bool is_werewolf() ;
};

class Werewolf: public creature  {
public:
    Werewolf(); //:creature() {}
    void initW(int i, Map*);
    ~Werewolf();
    bool is_vampire();
    bool is_werewolf();
};
