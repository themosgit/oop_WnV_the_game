//
// Created by Themos Papatheofanous on 4/12/22.
//

#ifndef OOP_WNV_THE_GAME_HEADER_H
#define OOP_WNV_THE_GAME_HEADER_H

#endif //OOP_WNV_THE_GAME_HEADER_H
class Game_visuals {
private:
    int map_x = 0;
    int map_y = 0;
    char** map = NULL;
public:
    Game_visuals();
    void Make_map();
    void Draw_map();

};

class Map : private Game_visuals {
public:

};