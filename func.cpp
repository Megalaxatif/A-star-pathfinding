#include "func.h"

cell maze[HEIGHT][LENGTH] = {cell()};

cell *start_cell = &maze[5][5];
cell *end_cell  = &maze[1][1];

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void goto_(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

void draw_board(){
    for (int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < LENGTH; j++){
            DRAW_CALL(maze[i][j].get_type(), "    ", j*4, i*2)
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void create_board(){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < LENGTH; x++){
            maze[y][x] = cell(y,x,array[y][x]);
        }
    }
}
void draw_array(){
    for (int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < LENGTH; j++){
            std::cout << array[i][j];
        }
        std::cout << "\n";
    }
}

unsigned int text_attribute[] = {
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,                        // undiscovered cell
    BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, // border
    BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY,                   // start cell
    BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY,                   // end cell
    FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY,                     // chosen cell
    BACKGROUND_GREEN                                                            // open cell
};

unsigned short array[HEIGHT][LENGTH] = {
    1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 1, 0, 0, 1,
    1, 1, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 1
};


