#include "func.h"

int main(){
    create_board();
    draw_board();
    std::vector<cell*> path = AstarPathfinding(start_cell, end_cell);
    //system("cls");
    goto_(0, 20);
    for (cell* cell_: path){
        std::cout << "X: " << cell_->get_coordx() << " Y: " << cell_->get_coordy() << "\n";
    }

    return 0;
}