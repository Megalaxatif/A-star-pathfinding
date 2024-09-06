#pragma once

#include <iostream>
#include <windows.h>
#include <cmath>
#include "cell.h"


#define DRAW_CALL(c, t, x, y) {\
    SetConsoleTextAttribute(console, text_attribute[c]);\
    goto_(x, y);\
    std::cout << t;\
    goto_(x, y + 1);\
    std::cout << t;\
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);\
}

void goto_(int x, int y);
void create_board();
void draw_board();
void set_end_coord( int x, int y);
void set_start_coord(int x, int y);

extern HANDLE console;

extern unsigned int start_cell_posx, start_cell_posy;
extern unsigned int end_cell_posx, end_cell_posy;

const unsigned int LENGTH = 6;
const unsigned int HEIGHT = 6;

 
extern unsigned int text_attribute[4];
extern unsigned short array[HEIGHT][LENGTH];
extern cell maze[HEIGHT][LENGTH]; // initialise maze

enum class CELL{
    EMPTY_SPACE = 0,
    BORDER = 1,
    START_CELL = 2,
    END_CELL = 3,
};
