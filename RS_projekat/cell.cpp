#include "cell.h"

Cell::Cell() {
    this->init = false;
}

Cell::Cell(bool visited) {
    this->init = visited;
}

void Cell::setWall(bool up, bool right, bool down, bool left) {
    this->wall_up       = up;
    this->wall_right    = right;
    this->wall_down     = down;
    this->wall_left     = left;
}

void Cell::clearWall() {
    this->setWall(false, false, false, false);
}

bool Cell::isVisited() {
    return this->init;
}

void Cell::visit() {
    this->init = true;
}
