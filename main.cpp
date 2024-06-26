#include <iostream>
#include <Windows.h>
#include "header.h"
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

int main() {
    srand(time(NULL));
    Map map;                 
    Avatar a(&map);                      // creating the avatar player placing them within the map
    int x = map.Get_mapx();
    int y = map.Get_mapy();
    system("cls");                               
    cout << "Avatar Movement With Arrow Keys\n"
         << "Exit Game With F1\n"
         << "Pause Game With F2\n"
         << "Heal Nearby Ally With F3\n";
    system("pause");
    system("cls");
    int num = x*y/15;            // number of vampires and werewolves to be constructed
    vector <Vampire> v;          // vectors saving all objects vampires and werewolves
    vector <Werewolf> w;
    for (int i = 0; i < num; i++) {   // loop creating each vampire and werewolve
        Vampire b;
        Werewolf c;
        b.initV(i, &map);    // placing them in legal places within the map
        c.initW(i, &map);
        v.push_back(b);  
        w.push_back(c);
    }
    bool game_playing = true;
    bool pause = false;
    system("cls");
    int numw; 
    int numv; 
    int counter_day = num * 20; // counter to control the day/night cycle 
    bool day = true;
    while (game_playing) {  // main game loop
        numw = num;
        numv = num;
        if (counter_day <= 0 && !day){ 
            day = true;
            counter_day = num * 20;
        }
        if (counter_day <= 0 && day){
            day = false;
            counter_day = num * 20;
        }
        for (int i = 0; i < num; ++i) {  
            if (GetKeyState(VK_UP) & 0x8000) a.avatar_move(-1, 0, &map); // checking for user input
            if (GetKeyState(VK_DOWN) & 0x8000) a.avatar_move(1, 0, &map); 
            if (GetKeyState(VK_LEFT) & 0x8000) a.avatar_move(0, -1, &map);
            if (GetKeyState(VK_RIGHT) & 0x8000) a.avatar_move(0, 1, &map);
            if (GetKeyState(VK_F1) & 0x8000) game_playing = false;
            if (GetKeyState(VK_F2) & 0x8000) pause = true;
            if (GetKeyState(VK_F3) & 0x8000) { 

                if(a.get_filter() > 0) {          // checks time of day and if the magic filter is available
                    if (a.team_vamp() && !day) {
                        a.use_filter();
                        for (int j = 0; j < num; ++j) { // heals all remaining vampires and werewolves
                            v[j].get_healed();         
                        }
                    } else if (!a.team_vamp() && day) {
                        for (int j = 0; j < num; ++j) {
                            w[j].get_healed();
                        }
                        a.use_filter();
                    } else cout << "Incorrect time of day can't use filter    " << endl;
                } else a.use_filter();
            }
            v[i].move(&map); // moving the vampire or werewolf within the map
            w[i].move(&map);
            for (int j = 0; j < num; ++j) { //for each werewolf and vampire we are using the function
                if (num <= 3) sleep_for(100ms); //battle or heal with every other w and v
                else sleep_for (10ms);        // setting game pace according to the number of w and v
                --counter_day; // day/night cycle counter
                if (j != i) {
                    v[i].battle_or_heal(&w[j], &map);
                    w[i].battle_or_heal(&w[j], &map);
                    v[i].battle_or_heal(&v[j], &map);
                    w[i].battle_or_heal(&v[j], &map);
                } else {
                    v[i].battle_or_heal(&w[j], &map);
                    w[i].battle_or_heal(&v[j], &map);
                }
            }
            if (!v[i].get_alive()) --numv; // if every v or w is not alive the game ends
            if (!w[i].get_alive()) --numw;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // refreshing screen
            if (day) cout << "It's Day!!\n";
            else cout << "It's Night!!\n";
            map.Display_map(); 
        }
        if (numv == 0 || numw == 0) game_playing = false; //pause menu 
        while (pause) {
            cout << "Vampires Remaining: " << numv <<"           "<< endl;
            for (int i = 0; i < num; ++i) {
                if (v[i].get_alive()) v[i].show();
            }
            cout << "\n" << "Werewolves Remaining: " << numw << endl;
            for (int i = 0; i < num; ++i) {
                if (w[i].get_alive()) w[i].show();
            }
            cout << "\n" <<"Magic Filters Remaining: " << a.get_filter() << endl;
            system("pause");
            pause = false;
            system("cls");
        }
    }
    system("cls");
    if (numw == 0) cout << "Vampires Won!!\n"; 
    else if (numv == 0) cout << "Werewolfs Won!!\n";
    else cout << "Please Wait Exiting Game...\n";
    sleep_for(5000ms);
    return 0;
}
