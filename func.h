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
    std::cout << "    ";\
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);\
}

void goto_(int x, int y);
void create_board();
void draw_board();
void draw_array();

extern HANDLE console;

const unsigned int LENGTH = 7;
const unsigned int HEIGHT = 7;
 
extern unsigned int text_attribute[];
extern unsigned short array[HEIGHT][LENGTH];
extern cell maze[HEIGHT][LENGTH];

extern cell* start_cell;
extern cell* end_cell;

enum class CELL{
    EMPTY_SPACE = 0,
    BORDER = 1,
    START_CELL = 2,
    END_CELL = 3,
    CHOSEN_CELL = 4,
    OPEN_CELL = 5
};
