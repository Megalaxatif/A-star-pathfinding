#include "func.h"

void goto_(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

void draw_board(){
    for (int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < LENGTH; j++){
            DRAW_CALL(maze[i][j].get_type(), "    ", j*4, i*2);
        }
        std::cout << "\n";
    }
}

void create_board(){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < LENGTH; x++){
            maze[y][x] = cell(y,x,array[y][x]);
        }
    }
}

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

unsigned int start_cell_posx, start_cell_posy = 1;
unsigned int end_cell_posx, end_cell_posy = 0;


unsigned int text_attribute[] = {
    BACKGROUND_GREEN | BACKGROUND_INTENSITY,                                    // empty space
    BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, // border
    FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY,                     // start cell
    BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY                    // end cell
};

unsigned short array[HEIGHT][LENGTH] = {
    3, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 1, 0,
    0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 2, 0,
    0, 0, 0, 0, 0, 0
};

cell maze[HEIGHT][LENGTH] = {cell()};