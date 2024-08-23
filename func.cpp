#include "func.h"

cell maze[HEIGHT][LENGTH] = {cell()}; // initialize maze

cell::cell(int coordx, int coordy, unsigned short type): x(coordx), y(coordy), type(type) {}
cell::cell() {}

void cell::calculateFHGcost(){
    F_cost = sqrt(pow(x + end_cell_posx, 2) + pow(y + end_cell_posy, 2)); // distance between the cell and the end cell
    H_cost = sqrt(pow(x + start_cell_posx, 2) + pow(y + start_cell_posy, 2)); // distance between the cell and the starting cell
    G_cost = F_cost + H_cost; // F cost + H cost
}


void goto_(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}
/*
void draw_board(){
    for (int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < LENGTH; j++){
            DRAW_CALL(array[i][j], "    ", j*4, i*2);
        }
        std::cout << "\n";
    }
}
*/
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

