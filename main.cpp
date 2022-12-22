
#include <iostream>
#include <Windows.h>
#include "header.h"
#include <ctime>
#include <vector>
using namespace std;

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
        Vampire a;
        Werewolf b;
        v.push_back(a);
        w.push_back(b);
    }

    bool game_playing = true;
    bool pause = false;
    system("cls");
    while (game_playing) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
        map.Display_map();
        system("pause>nul");
        if (GetKeyState(VK_UP) & 0x8000) a.avatar_move(-1, 0, &map);
        if (GetKeyState(VK_DOWN) & 0x8000) a.avatar_move(1, 0, &map);
        if (GetKeyState(VK_LEFT) & 0x8000) a.avatar_move(0, -1, &map);
        if (GetKeyState(VK_RIGHT) & 0x8000) a.avatar_move(0, 1, &map);
        if (GetKeyState(VK_F1) & 0x8000) game_playing = false;
        if (GetKeyState(VK_F2) & 0x8000) pause = true;

        while (pause) {
            system("pause");
            pause = false;
            system("cls");
        }
    }
    return 0;
}

