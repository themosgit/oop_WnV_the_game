//
// Created by Themos Papatheofanous on 4/12/22.
//
#include <iostream>
#include "header.h"

using namespace std;

Game_visuals::Game_visuals() {
    cout << "Enter Map Dimensions\n"
         << "X axis : ";
    cin >> map_x;
    cout << "Y axis : ";
    cin >> map_y;

    map = new char* [map_x];
    for (int i = 0; i < map_x; i++) {
        map[i] = new char[map_y];
    }

}

void Game_visuals::Make_map() {
    for (int i = 0; i < map_x; i++) {
        for (int j = 0; j < map_y; j++) {
            if( i == 0 || i == map_x - 1) map[i][j] = '*';
            else if (j == 0 || j == map_y - 1) map[i][j] = '*';
            else map[i][j] = ' ';
        }
    }
}

void Game_visuals::Draw_map() {
    cout << map_x << map_y << endl;
    for (int i = 0; i < map_x; ++i) {
        for (int j = 0; j < map_y; ++j) {
            cout << map[i][j] << "  ";
        }
        printf("\n");
    }
}


