//
// Created by Themos Papatheofanous on 4/12/22.
//

#include <iostream>
#include <windows.h>
#include "header.h"
using namespace std;

int main() {
    Map map1;
    map1.Populate_Map();
    bool game_playing = true;
    while (game_playing) {
        system("cls");
        map1.Display_map();
        system("pause>nul");
        if (GetKeyState(VK_UP) & 0x8000) map1.movement(-1, 0);
        if (GetKeyState(VK_DOWN) & 0x8000) map1.movement(1, 0);
        if (GetKeyState(VK_LEFT) & 0x8000) map1.movement(0, -1);
        if (GetKeyState(VK_RIGHT) & 0x8000) map1.movement(0, 1);
        if (GetKeyState(VK_F1) & 0x8000) game_playing = false;
        system("cls");
        map1.Display_map();
    }

    return 0;
}