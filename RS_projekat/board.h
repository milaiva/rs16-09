#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "cell.h"
#include <QGraphicsScene>

class Board {
    private:
        int width;
        int height;
        int scale = 20;
        QGraphicsScene *scene;
        std::vector<Cell*> cells;
        std::vector<int> cell_stack;
    public:
        Board(int width, int height, QGraphicsScene* scene);
        Cell* getCell(int x, int y);
        void setWall(int x, int y, bool up, bool right, bool down, bool left);
        void clearWall(int x, int y);
        std::vector<Cell*> getNeighbors(int x, int y);
        void move(int x, int y);
};

#endif // BOARD_H
