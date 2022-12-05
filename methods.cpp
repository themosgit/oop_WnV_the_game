//
// Created by Themos Papatheofanous on 4/12/22.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"

using namespace std;


Graphics::Graphics() {
    cout << "Enter Map Dimensions\n"
         << "X axis : ";
    cin >> playble_width;
    cout << "Y axis : ";
    cin >> playble_height;
}

Map::Map() {
    map = new char* [map_x];
    for (int i = 0; i < map_x; i++) {
        map[i] = new char[map_y];
    }
    srand(time(0));
    int obstacle_limit = playble_height * (playble_width / 10);
    int obstacles = 0;
    for (int i = 0; i < map_x; i++) {
        for (int j = 0; j < map_y; j++) {
            if ( i == 0 || i == map_x - 1) map[i][j] = '*';
            else if (j == 0 || j == map_y - 1) map[i][j] = '*';
            else {
                if (rand() % 15 == 0 && obstacles < obstacle_limit) {
                    obstacles++;
                    if (rand() % 2 == 0)map[i][j] = 'T';
                    else map[i][j] = '~';
                } else map[i][j] = ' ';
            }
        }
    }
}

void Map::Populate_Map() {

}

void Map::Display_map() {
    for (int i = 0; i < map_x; ++i) {
        for (int j = 0; j < map_y; ++j) {
            cout << map[i][j] <<"  ";
        }
        printf("\n");
    }
}


