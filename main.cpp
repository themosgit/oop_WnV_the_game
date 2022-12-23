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
    srand(time(nullptr));
    Map map;
    Avatar a(&map);
    int x = map.Get_mapx();
    int y = map.Get_mapy();
    int num = x*y/15;
    vector <Werewolf> w;
    vector <Vampire> v;
    for (int i = 0; i < num; i++) {
        Vampire a(i, &map);
        Werewolf b(i, &map);
        v.push_back(a);
        w.push_back(b);
    }

    bool game_playing = true;
    bool pause = false;
    system("cls");
    int numw = num;
    int numv = num;
    while (game_playing) {
        for (int i = 0; i < num; ++i) {
            sleep_for(50ms);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
            map.Display_map();
            if (GetKeyState(VK_UP) & 0x8000) a.avatar_move(-1, 0, &map);
            if (GetKeyState(VK_DOWN) & 0x8000) a.avatar_move(1, 0, &map);
            if (GetKeyState(VK_LEFT) & 0x8000) a.avatar_move(0, -1, &map);
            if (GetKeyState(VK_RIGHT) & 0x8000) a.avatar_move(0, 1, &map);
            if (GetKeyState(VK_F1) & 0x8000) game_playing = false;
            if (GetKeyState(VK_F2) & 0x8000) pause = true;
            if (i <= numv)  v[i].move(&map);
            if (i <= numw)  w[i].move(&map);
            if (!v[i].get_alive()){
                swap(v[i], v[numv]);
                v.pop_back();
                --numv;
            }
            if(!w[i].get_alive()){
                swap(w[i], w[numw]);
                w.pop_back();
                --numw;
            }
            if (numv == 0 || numw == 0) game_playing = false;
            for (int j = 0; j < num; ++j) {
                if (i <= numw  && i <= numv){
                    v[i].battle_or_heal(&w[j], &map);
                    w[i].battle_or_heal(&w[j], &map);
                    if (!v[j].get_alive()){
                        swap(v[j], v[numv]);
                        v.pop_back();
                        --numv;
                    }
                }
                if (num <= numv) {
                    v[i].battle_or_heal(&v[j], &map);
                    w[i].battle_or_heal(&v[j], &map);
                    if(!w[j].get_alive()){
                        swap(w[j], w[numw]);
                        w.pop_back();
                        --numw;
                    }
                }
            }
        }
        while (pause) {
            system("pause");
            pause = false;
            system("cls");
        }
    }
    return 0;
}