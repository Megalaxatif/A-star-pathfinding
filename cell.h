#pragma once
#include <vector>

class cell{
    public:
        cell(int coordx, int coordy, unsigned short type);
        cell();
        void calculateFHGcost();
        inline unsigned short get_type() {return type;}
        inline int get_coordx() {return x;}
        inline int get_coordy() {return y;}
        inline int getFcost() {return F_cost;}
        inline int getHcost() {return H_cost;}
        inline int getGcost() {return G_cost;}
        inline cell* getParentCell() {return parent_cell;}
        inline void setParentCell(cell *cell_) {parent_cell = cell_;}
        inline void setType(unsigned short type_) {type = type_;}
    private:
        int x = 0;
        int y = 0;
        int F_cost = 0;
        int H_cost = 0;
        int G_cost = 0;
        unsigned short type = 0;
        cell *parent_cell;
}; 
std::vector<cell*> AstarPathfinding(cell *start, cell *end);
bool findNewOpenCell(cell *cell_);
void includeCell(cell* cell_, cell* parent_cell);