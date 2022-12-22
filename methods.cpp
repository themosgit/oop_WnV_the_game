#include "header.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Graphics::Graphics() {
    cout << "Enter Map Dimensions\n"
         << "Y axis: ";
    cin >> playble_height;
    cout << "X axis: ";
    cin >> playble_width;
}

Graphics::~Graphics() noexcept = default;

Map::Map() {
    srand(time(NULL));
    map = new char* [map_x];
    for (int i = 0; i < map_x; i++) {
        map[i] = new char[map_y];
    }
    int obstacle_limit = (playble_height * playble_width) / 4;
    int obstacles = 0;
    bool giatriko = true;
    for (int i = 0; i < map_x; i++) {
        for (int j = 0; j < map_y; j++) {
            if ( i == 0 || i == map_x - 1) map[i][j] = '*';
            else if (j == 0 || j == map_y - 1) map[i][j] = '*';
            else {
                if (rand() % map_x == 0 && obstacles < obstacle_limit) {
                    obstacles++;
                    if (rand() % 2 == 0)map[i][j] = 'T';
                    else map[i][j] = '~';
                    if (j > 2 && j < map_y - 2 && giatriko) {
                        map[i][j] = '$';
                        giatriko = false;
                    }
                }
                else map[i][j] = ' ';
            }
        }
    }
}

int Map::Get_mapx() {
    return playble_width;
}
int Map::Get_mapy() {
    return playble_height;
}

void Map::Display_map() {
    for (int i = 0; i < map_x; ++i) {
        for (int j = 0; j < map_y; ++j) {
            cout << map[i][j] <<" ";
        }
        printf("\n");
    }
}

Map::~Map() {
    delete[] *map;
    delete[]  map;
}

Being::Being(){}
Being::~Being(){}

int Being::get_posis() {
    cout << "\n x = " << x_coord <<"    "<<"y = " << y_coord << endl;
    return x_coord, y_coord;
}

int Being::get_x() {
    return x_coord;
}
int Being::get_y() {
    return y_coord;
}

Avatar::Avatar(Map* map){
    x_coord = map->Get_mapx() / 2;
    y_coord = map->Get_mapy() / 2;
    choose_team();
    map->map[x_coord][y_coord] = team_signate;
}

Avatar::~Avatar(){}

void Avatar::choose_team() {
    cout << "\nchoose team";
    cout << "\n[1] Vampires , [2] Werewolves ";
    int c;
    cin >> c;
    switch (c) {
        case (1): {
            cout << "\nteam vampires";
            team_V = true;
            team_signate = 'V';
            team_W = false;
            break; }
        case(2): {
            cout << "\nteam werewolves";
            team_V = false;
            team_signate = 'W';
            team_W = true;
            break; }
        default :{
            cout << "\ntry again";
            choose_team();
        }
    }
}

void Avatar::avatar_move(int ud, int lr, Map* map) {
    map->map[x_coord][y_coord] = ' ';
    if (map->map[x_coord + ud][y_coord] == ' ' || map->map[x_coord + ud][y_coord] == '$' ) x_coord += ud;
    if (map->map[x_coord][y_coord + lr] == ' ' || map->map[x_coord][y_coord + lr] == '$') y_coord += lr;
    if (map ->map[x_coord][y_coord] == '$') incr_filter();;
    map->map[x_coord][y_coord] = team_signate;

}

bool Avatar::team_vamp() {
    return team_V;
}

bool Avatar::team_wer() {
    return team_W;
}

int Avatar::get_filter() {
    return filter;
}

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

creature::~creature() {}

int creature::get_health() {
    return health;
}

int creature::get_power() {
    return power;
}

int creature::get_defence() {
    return defence;
}

int creature::get_giatriko(){
    return giatriko;
}

void creature::show() {
    cout << "\nhealth=" << get_health() << "\npower = " << get_power() <<
         "\ndefence = " << get_defence() << "\ngiatriko = " << get_giatriko() <<  endl;
}

bool creature::is_alive() {
    if (get_health() > 0)
        return true;
    else return false;
}

void creature::get_healed() {
    if (is_alive()) {
        if (health < 4 && health>0) {
            health++;
            cout << "\n creature got healed \nnew health=" << health << endl;
        }
        else if (health =4)
            cout << "\n creature has max health";
    }
    else cout << "\n cant heal is dead ";
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
            if (get_power() < a->get_power()) {
                cout << "\n cant attack is stronger";
            }
            else if (get_power() >= a->get_power()) {
                a->health = a->health - abs(a->get_defence() - get_power());
                if (a->get_health() <= 0) {
                    cout << "\n creature is dead";
                    a->is_alive() == false;
                }
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
    signate = 'v';
}
bool Vampire::is_vampire() {
    return true;
}
bool Vampire::is_werewolf() {
    return false;
}

Vampire::~Vampire() {}


//werewolf
Werewolf::Werewolf():creature() {
    signate = 'w';
}
Werewolf::~Werewolf(){}

bool Werewolf::is_vampire() {
    return false;
}
bool Werewolf::is_werewolf() {
    return true;
}








