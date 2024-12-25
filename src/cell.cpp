#include <header/cell.h>
#include <header/pathfinding.h>
#include <cmath>

cell::cell(int coordx, int coordy, unsigned short type): x(coordx), y(coordy), type(type) {}
cell::cell() {}

void cell::calculateFHGcost(){
    F_cost = abs(end_cell->get_coordx() - x) + abs(end_cell->get_coordy() - y);
    H_cost = abs(start_cell->get_coordx() - x) + abs(start_cell->get_coordy() - y);
    G_cost = F_cost + H_cost; // F cost + H cost
}