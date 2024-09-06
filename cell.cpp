#include "cell.h"
#include "func.h"
#include <algorithm>

cell::cell(int coordx, int coordy, unsigned short type): x(coordx), y(coordy), type(type) {}
cell::cell() {}

void cell::calculateFHGcost(){
    F_cost = end_cell_posx - x + end_cell_posy - y;//sqrt(pow(x + end_cell_posx, 2) + pow(y + end_cell_posy, 2)); // distance between the cell and the end cell
    H_cost = start_cell_posx - x + end_cell_posy - y;//sqrt(pow(x + start_cell_posx, 2) + pow(y + start_cell_posy, 2)); // distance between the cell and the starting cell
    G_cost = F_cost + H_cost; // F cost + H cost
}

bool findNewOpenCell(cell *cell_, std::vector<cell*> vec){
    if(maze[cell_->get_coordx()][cell_->get_coordy()].get_type() == (int)CELL::BORDER) return false; // the cell is a border
    else {for(cell* cell__ : vec) { if(cell__->get_coordx() == cell_->get_coordx() && cell__->get_coordy() == cell_->get_coordy()) return false;}}// the cell is in the chosen cell vector
    return true; // if the cell is neither a border or in the chosen cell vector, it can be in the open cell vector
}

std::vector<cell*> AstarPathfinding(cell *start_cell, cell *end_cell){
    std::vector<cell*> open; // the cells we are looking at
    std::vector<cell*> chosen; // the chosen cells
    std::vector<cell*> path;
    open.push_back(start_cell); // adding starting cell to open

    while(1){
        cell current = *open[0]; // initialise the lowest cost to the first cell in open    
        for(int i = 0; i < open.size(); i++){
            if (open[i]->getGcost() < current.getGcost()){ // we prioritise the Gcost
                current = *open[i];
            }
            else if (open[i]->getGcost() == current.getGcost()){ // if the two cells are equal we take the one with the lowest F cost
                if(open[i]->getFcost() < current.getFcost()) {
                    current = *open[i];
                }
            }
        }
        // we are sure to have found a better or equal cell at the end of the loop, so we move the current cell from the open vector to the chosen one
        open.erase(std::find(open.begin(), open.end(), current));
        chosen.push_back(&current);
        
        if(current.get_coordx() == end_cell->get_coordx() && current.get_coordy() == end_cell->get_coordy()){ // we found the end cell
            cell current_ = *end_cell; // initialise the current cell to the end cell
            path.push_back(end_cell); // put the end cell at the first place in the path
            // find the way back with the parent cells
            while(current_.get_coordx() != start_cell->get_coordx() && current_.get_coordy() != start_cell->get_coordy()){
                path.push_back(current_.getParentCell());
                current_ = *current_.getParentCell();
            }
            return path; // end
        }
        // add the neighbouring cell to the open list and set their parent cell to current
        cell* topRightCell = &maze[current.get_coordy() + 1][current.get_coordx() + 1];
        cell* rightCell = &maze[current.get_coordy()][current.get_coordx() + 1];
        cell* bottomRightCell = &maze[current.get_coordy() + 1][current.get_coordx() + 1];
        cell* bottomCell = &maze[current.get_coordy() + 1][current.get_coordx()];
        cell* bottomLeftCell = &maze[current.get_coordy() - 1][current.get_coordx() - 1];
        cell* leftCell = &maze[current.get_coordy()][current.get_coordx() - 1];
        cell* topLeftCell = &maze[current.get_coordy() + 1][current.get_coordx() - 1];
        cell* topCell = &maze[current.get_coordy() + 1][current.get_coordx()];

        if(findNewOpenCell(topRightCell, chosen)) {open.push_back(topRightCell); topRightCell->setParentCell(&current);} //top right
        if(findNewOpenCell(rightCell, chosen)) {open.push_back(rightCell); rightCell->setParentCell(&current);} //right
        if(findNewOpenCell(bottomRightCell, chosen)) {open.push_back(bottomRightCell); bottomRightCell->setParentCell(&current);} //bottom right
        if(findNewOpenCell(bottomCell, chosen)) {open.push_back(bottomCell); bottomCell->setParentCell(&current);}//bottom
        if(findNewOpenCell(bottomLeftCell, chosen)) {open.push_back(bottomLeftCell); bottomLeftCell->setParentCell(&current);} //bottom left
        if(findNewOpenCell(leftCell, chosen)) {open.push_back(leftCell); leftCell->setParentCell(&current);} //left
        if(findNewOpenCell(topLeftCell, chosen)) {open.push_back(topLeftCell); topLeftCell->setParentCell(&current);} //top left
        if(findNewOpenCell(topCell, chosen)) {open.push_back(topCell); topCell->setParentCell(&current);} //top
    }
};
