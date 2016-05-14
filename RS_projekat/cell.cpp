#include "cell.h"

Cell::Cell() {
    this->visited = false;
}

Cell::Cell(bool visited) {
    this->visited = visited;
}

bool Cell::isVisited() {
    return this->visited;
}

void Cell::visit() {
    this->visited = true;
}
