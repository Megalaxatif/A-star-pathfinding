#include <iostream>
#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

const unsigned short LENGTH = 4;
const unsigned short HEIGHT = 5;

void goto_(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}
#define DRAW_CALL(c, t, x, y) {\
    SetConsoleTextAttribute(console, text_attribute[c]);\
    goto_(x, y);\
    std::cout << t;\
    goto_(x, y + 1);\
    std::cout << t;\
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);\
}

unsigned int text_attribute[] = {
    BACKGROUND_GREEN | BACKGROUND_INTENSITY,                                    // empty space
    BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, // border
    FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY,                     // start cell
    BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY                    // end cell
};


unsigned short array[HEIGHT][LENGTH] = {
    3, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 1, 0, 1,
    0, 0, 0, 2  
};

int main(){
    for (int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < LENGTH; j ++){
            DRAW_CALL(array[i][j], "    ", j*4, i*2);
        }
        std::cout << "\n";
    }
    return 0;
}