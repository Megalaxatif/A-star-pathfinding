#include "func.h"

void goto_(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

void draw_board(){
    for (int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < LENGTH; j ++){
            DRAW_CALL(array[i][j], "    ", j*4, i*2);
        }
        std::cout << "\n";
    }
}