#ifndef CELL_H
#define CELL_H


class Cell {
    private:
        bool visited = false;
    public:
        Cell();
        Cell(bool visited);
        bool isVisited();
        void visit();
};

#endif // CELL_H
