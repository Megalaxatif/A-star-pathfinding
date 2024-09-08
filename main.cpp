#include "func.h"

int main(){
    create_board();
    set_start_coord(3,3);
    set_end_coord(1,1);
    std::vector<cell*> path = AstarPathfinding(&start_cell, &end_cell);
    system("cls");
    std::cout << "finished" << "path size = " << path.size();
    goto_(0, 20);
    for (cell* cell_: path){
        std::cout << "X: " << cell_->get_coordx() << " Y: " << cell_->get_coordy() << "\n";
    }

    return 0;
}