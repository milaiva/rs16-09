#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "cell.h"
#include <QGraphicsScene>

class Board {
    private:
        QGraphicsScene *scene;
        std::vector<Cell*> cells;
        std::vector<int> cell_stack;

        int width;
        int height;
        int scale = 50;
    public:
        Board(int width, int height, QGraphicsScene* scene);
        Cell* getCell(int x, int y);
        std::vector<Cell*> getNeighbors(int x, int y);
        void move(int x, int y);
};

#endif // BOARD_H
