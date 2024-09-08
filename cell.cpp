#include "cell.h"
#include "func.h"
#include <algorithm>
#include <string>
#include <stdio.h>

int test = 0;
std::vector<cell*> open; // the cells we are looking at
std::vector<cell*> chosen; // the chosen cells

cell::cell(int coordx, int coordy, unsigned short type): x(coordx), y(coordy), type(type) {}
cell::cell() {}

void cell::calculateFHGcost(){
    F_cost = abs(end_cell.get_coordx() - x) + abs(end_cell.get_coordy() - y);//sqrt(pow(x + end_cell_posx, 2) + pow(y + end_cell_posy, 2)); // distance between the cell and the end cell
    H_cost = abs(start_cell.get_coordx() - x) + abs(start_cell.get_coordy() - y);//sqrt(pow(x + start_cell_posx, 2) + pow(y + start_cell_posy, 2)); // distance between the cell and the starting cell
    G_cost = F_cost + H_cost; // F cost + H cost
}

bool findNewOpenCell(cell *cell_){
    if(maze[cell_->get_coordy()][cell_->get_coordx()].get_type() == (int)CELL::BORDER) {
        return false;
    } // the cell is a border
    for(cell* cell__ : chosen)  { if(cell__->get_coordx() == cell_->get_coordx() && cell__->get_coordy() == cell_->get_coordy()) return false; }// the cell is in the chosen cell vector
    for(cell* cell__ : open)    { if(cell__->get_coordx() == cell_->get_coordx() && cell__->get_coordy() == cell_->get_coordy()) return false; }// the cell is in the open cell vector
    return true; // if the cell is neither a border or in the chosen or open cell vector, it can be in the open cell vector
}

void includeCell(cell* cell_, cell* parent_cell){
    cell_->calculateFHGcost();
    open.push_back(cell_); 
    cell_->setParentCell(parent_cell);
    std::string cell_str = " " + std::to_string(cell_->getGcost()) + " " + std::to_string(cell_->getFcost());
    DRAW_CALL((unsigned short)CELL::OPEN_CELL, cell_str, cell_->get_coordx()*4, cell_->get_coordy()*2)
}
std::vector<cell*> AstarPathfinding(cell *start_cell, cell *end_cell){
    // reset both open and chosen vector
    open = std::vector<cell*>();
    chosen = std::vector<cell*>();
    std::vector<cell*> path;
    start_cell->calculateFHGcost();
    open.push_back(start_cell); // adding starting cell to open
    cell *current = open[0]; // initialise the lowest cost to the first cell in open   

    while(1){
        current = open[0]; // reset current
        for(int i = 0; i < open.size(); i++){
            // refresh the screen
            //goto_(0, HEIGHT*2 + 2);
            //std::cout << std::string(" ", 70) << "\n" << std::string(" ", 70) << "\n" << std::string(" ", 70) << "\n" << std::string(" ", 70) << "\n" << std::string(" ", 70);
            if (open[i]->getGcost() < current->getGcost()){ // we prioritise the Gcost
                // debuging
                //goto_(0, HEIGHT*2 + 2);
                //std::cout << "Gcost of cell (X="<<open[i]->get_coordx() << " Y =" <<open[i]->get_coordy() << ") is: " << open[i]->getGcost() <<". \n better than Gcost of current cell (X="<< current->get_coordx() << " Y="<< current->get_coordy() << ") which is "<< current->getGcost();
                
                current = open[i];
            }
            else if (open[i]->getGcost() == current->getGcost()){ // if the two cells are equal we take the one with the lowest F cost
                if(open[i]->getFcost() < current->getFcost()) {
                    // debuging
                    //goto_(0, HEIGHT*2 + 5);
                    //std::cout << "Fcost of cell (X="<<open[i]->get_coordx() << " Y =" <<open[i]->get_coordy() << ") is: " << open[i]->getFcost() <<". \n better than Gcost of current cell (X="<< current->get_coordx() << " Y="<< current->get_coordy() << ") which is "<< current->getFcost();
                    
                    current = open[i];
                }
            }
        }
        //goto_(0, HEIGHT*2 + 7);
        //std::cout << "current is at position X " << current->get_coordx() << "Y " << current->get_coordy() << "\n";
        //if (!chosen.empty()) std::cout << "current address is " << current << "last current cell address is " << chosen.back();  
        // we are sure to have found a better or equal cell at the end of the loop, so we move the current cell from the open vector to the chosen one
        // if the cell we add to the chosen vector is the same cell we add before it means that there is no other ways to the end cell and we are blocked, we must ckeck this
        // IMPORTANT: during the first loop the "chosen_vector" is empty, leading to an undefined statement if chosen.back() is executed. That's why we
        // have to let the code continue if the vector is empty
        if (chosen.empty() || current != chosen.back()){
            open.erase(std::find(open.begin(), open.end(), current));
            chosen.push_back(current);
            std::string cell_str = " " + std::to_string(current->getGcost()) + " " + std::to_string(current->getFcost());
            DRAW_CALL((unsigned short)CELL::CHOSEN_CELL, cell_str, current->get_coordx()*4, current->get_coordy()*2)
        }
        else { // we are blocked
            goto_(0, HEIGHT * 2 + 9);
            std::cerr << "pathfinding error: impossible to find a valid path with the data given. ";
            std::vector<cell*> empty_vec;
            return empty_vec; // we return an empty array
        }
        // we check if we found the path
        if(current->get_coordx() == end_cell->get_coordx() && current->get_coordy() == end_cell->get_coordy()){
            cell *current_ = end_cell; // initialise the current-cell to the end cell
            path.push_back(end_cell); // put the end cell at the first place in the path vector
            // find the way back with the parent cells
            while(1){
                std::cout << "in the loop";
                path.push_back(current_->getParentCell());
                //std::cout << path.size() << " ";
                current_ = current_->getParentCell();
                std::cout << "test";
                //std::cout << "2";
                //if(current_->get_coordx() == start_cell->get_coordx() && current_->get_coordy() == start_cell->get_coordy()) break;
            }
            return path;
        }
        // add the neighbouring cell to the open list and set their parent cell to current
        cell* topRightCell =    &maze[current->get_coordx() + 1][current->get_coordy() - 1];
        cell* rightCell =       &maze[current->get_coordx() + 1][current->get_coordy()    ];
        cell* bottomRightCell = &maze[current->get_coordx() + 1][current->get_coordy() + 1];
        cell* bottomCell =      &maze[current->get_coordx()    ][current->get_coordy() + 1];
        cell* bottomLeftCell =  &maze[current->get_coordx() - 1][current->get_coordy() + 1];
        cell* leftCell =        &maze[current->get_coordx() - 1][current->get_coordy()    ];
        cell* topLeftCell =     &maze[current->get_coordx() - 1][current->get_coordy() - 1];
        cell* topCell =         &maze[current->get_coordx()    ][current->get_coordy() - 1];

        if(findNewOpenCell(rightCell))       {includeCell(rightCell, current);} //right
        if(findNewOpenCell(topRightCell))    {includeCell(topRightCell, current);} //top right
        if(findNewOpenCell(bottomRightCell)) {includeCell(bottomRightCell, current);} //bottom right
        if(findNewOpenCell(bottomCell))      {includeCell(bottomCell, current);} //bottom
        if(findNewOpenCell(bottomLeftCell))  {includeCell(bottomLeftCell, current);}// bottom left
        if(findNewOpenCell(leftCell))        {includeCell(leftCell, current);} //left
        if(findNewOpenCell(topLeftCell))     {includeCell(topLeftCell, current);} //top left
        if(findNewOpenCell(topCell))         {includeCell(topCell, current);} //top

        // debuging
        goto_(0, HEIGHT*2 + 1);
        std::cout << " chosen: " << chosen.size() << " open: " << open.size();
        // press space and release it to continue the pathfinding
        while (GetAsyncKeyState(VK_SPACE) & 0x8000) {}      
        while (!(GetAsyncKeyState(VK_SPACE) & 0x8000)) {}
    }
};
