#include "board.h"
#include "cell.h"
#include "wall.h"
#include <vector>

#include <QDebug>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>

Board::Board(int width, int height, QGraphicsScene *scene) {
    int size = width*height;
    this->width = width;
    this->height = height;
    this->scene = scene;
    for (int i = 0; i < size; i++) {
        this->cells.push_back(new Cell());
    }
}

Cell* Board::getCell(int x, int y) {
    int i = y* this->width + x;

    return this->cells[i];
}

void Board::move(int x, int y) {
    std::vector<Cell*> neg = this->getNeighbors(x, y);

    int x_new, y_new;

    qDebug() << x << y;

    bool free_cells = false;
    for (unsigned int i = 0; i < neg.size(); i++) {
        if (neg[i]->isVisited() == false) free_cells = true;
    }

    Cell* cell = this->getCell(x, y);
    cell->visit();


    if (free_cells) {
        this->cell_stack.push_back(y * this->width + x);

        int n = rand() % neg.size();
        while (neg[n]->isVisited() == true) {
            n = rand() % neg.size();
        }

        if (n == 0) {
            x_new = x;
            y_new = y - 1;
        } else if (n == 1) {
            x_new = x + 1;
            y_new = y;
        } else if (n == 2) {
            x_new = x;
            y_new = y + 1;
        } else {
            x_new = x - 1;
            y_new = y;
        }

        QGraphicsLineItem *line = new QGraphicsLineItem(x*this->scale, y*this->scale, x_new*this->scale, y_new*this->scale);
        this->scene->addItem(line);

        this->move(x_new, y_new);
    } else if (this->cell_stack.size() > 0) {
        int pos = this->cell_stack.back();
        this->cell_stack.pop_back();
        int x_new = pos % this->width;
        int y_new = pos / this->width;
        this->move(x_new, y_new);
    }
}

void Board::setWall(int x, int y, bool up, bool right, bool down, bool left) {
    int i = y * this->width + x;
    this->cells[i]->setWall(up, right, down, left);
}

void Board::clearWall(int x, int y) {
    int i = y * this->width + x;
    this->cells[i]->clearWall();
}

std::vector<Cell*> Board::getNeighbors(int x, int y) {
    std::vector<Cell*> neighbors;

    Cell* up        = y > 0 ? this->getCell(x, y-1) : new Cell(true);
    Cell* right     = x < this->width - 1 ? this->getCell(x+1, y) : new Cell(true);
    Cell* bottom    = y < this->height - 1 ? this->getCell(x, y+1) : new Cell(true);
    Cell* left      = x > 0 ? this->getCell(x-1, y) : new Cell(true);

    neighbors.push_back(up);
    neighbors.push_back(right);
    neighbors.push_back(bottom);
    neighbors.push_back(left);

//    neighbors.push_back((y > 0 ? this->getCell(x, y-1) : new Cell()));
//    neighbors.push_back((x < this->width -1 ? this->getCell(x+1, y) : new Cell()));
//    neighbors.push_back((y < this->height - 1 ? this->getCell(x, y+1) : new Cell()));
//    neighbors.push_back((x > 0 ? this->getCell(x-1, y) : new Cell()));

    return neighbors;
}
