#pragma once

#include <iostream>
#include <windows.h>

static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

static unsigned int start_cell_posx, start_cell_posy = 1;
static unsigned int end_cell_posx, end_cell_posy = 0;

static const unsigned int LENGTH = 4;
static const unsigned int HEIGHT = 5;

static unsigned short array[HEIGHT][LENGTH] = {
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 1, 0, 1,
    0, 0, 0, 0  
};

static unsigned int text_attribute[] = {
    BACKGROUND_GREEN | BACKGROUND_INTENSITY,                                    // empty space
    BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, // border
    FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY,                     // start cell
    BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY                    // end cell
};

#define DRAW_CALL(c, t, x, y) {\
    SetConsoleTextAttribute(console, text_attribute[c]);\
    goto_(x, y);\
    std::cout << t;\
    goto_(x, y + 1);\
    std::cout << t;\
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);\
}

struct CELL{
    int posx;
    int poxy;
    unsigned short type;
};

void goto_(int x, int y);
void draw_board();
void set_end_coord( int x, int y);
void set_start_coord(int x, int y);
void modify_cell(int x, int y, CELL cell);