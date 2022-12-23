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
    Avatar a(&map);
    int x = map.Get_mapx();
    int y = map.Get_mapy();
    system("cls");
    cout << "Avatar Movement With Arrow Keys\n"
         << "Exit Game With F1\n"
         << "Pause Game With F2\n"
         << "Heal Nearby Ally With F3\n";
    system("pause");
    system("cls");
    int num = x*y/15;
    vector <Vampire> v;
    vector <Werewolf> w;
    for (int i = 0; i < num; i++) {
        Vampire b;
        Werewolf c;
        b.initV(i, &map);
        c.initW(i, &map);
        v.push_back(b);
        w.push_back(c);
    }
    bool game_playing = true;
    bool pause = false;
    system("cls");
    int numw;
    int numv;
    int counter_day = num * 20;
    bool day = true;
    while (game_playing) {
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
            if (GetKeyState(VK_UP) & 0x8000) a.avatar_move(-1, 0, &map);
            if (GetKeyState(VK_DOWN) & 0x8000) a.avatar_move(1, 0, &map);
            if (GetKeyState(VK_LEFT) & 0x8000) a.avatar_move(0, -1, &map);
            if (GetKeyState(VK_RIGHT) & 0x8000) a.avatar_move(0, 1, &map);
            if (GetKeyState(VK_F1) & 0x8000) game_playing = false;
            if (GetKeyState(VK_F2) & 0x8000) pause = true;
            if (GetKeyState(VK_F3) & 0x8000) {

                if(a.get_filter() > 0) {
                    if (a.team_vamp() && !day) {
                        a.use_filter();
                        for (int j = 0; j < num; ++j) {
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
            v[i].move(&map);
            w[i].move(&map);
            for (int j = 0; j < num; ++j) {
                if (num <= 2) sleep_for(100ms);
                else sleep_for (10ms);
                --counter_day;
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
            if (!v[i].get_alive()) --numv;
            if (!w[i].get_alive()) --numw;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
            if (day) cout << "It's Day!!\n";
            else cout << "It's Night!!\n";
            map.Display_map();
        }
        if (numv == 0 || numw == 0) game_playing = false;
        while (pause) {
            cout << "Vampires Remaining: " << numv <<"           "<< endl;
            for (int i = 0; i < num; ++i) {
                if (v[i].get_alive()) v[i].show();
            }
            cout << "\n" << "Werewolves Remaining: " << numw << endl;
            for (int i = 0; i < num; ++i) {
                if (w[i].get_alive()) w[i].show();
            }
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