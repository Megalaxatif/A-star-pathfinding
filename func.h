#pragma once

#include <iostream>
#include <windows.h>
#include <cmath>

#define DRAW_CALL(c, t, x, y) {\
    SetConsoleTextAttribute(console, text_attribute[c]);\
    goto_(x, y);\
    std::cout << t;\
    goto_(x, y + 1);\
    std::cout << t;\
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);\
}

static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

static unsigned int start_cell_posx, start_cell_posy = 1;
static unsigned int end_cell_posx, end_cell_posy = 0;

static const unsigned int LENGTH = 6;
static const unsigned int HEIGHT = 6;

static unsigned int text_attribute[] = {
    BACKGROUND_GREEN | BACKGROUND_INTENSITY,                                    // empty space
    BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, // border
    FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY,                     // start cell
    BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY                    // end cell
};

static unsigned short array[HEIGHT][LENGTH] = {
    3, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 1, 0,
    0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 2, 0,
    0, 0, 0, 0, 0, 0
};

class cell{
    public:
        cell(int coordx, int coordy, unsigned short type);
        cell();
        void calculateFHGcost();
        inline unsigned short get_type() {return type;}
        inline int get_coordx() {return x;}
        inline int get_coordy() {return y;}
    private:
        int x = 0;
        int y = 0;
        int F_cost = 0; 
        int H_cost = 0;
        int G_cost = 0;
        unsigned short type = 0;
}; 

extern cell maze[HEIGHT][LENGTH];



void goto_(int x, int y);
void create_board();
void draw_board();
void set_end_coord( int x, int y);
void set_start_coord(int x, int y);
//void modify_cell(int x, int y, CELL cell);
