#ifndef CELL_H
#define CELL_H


class Cell {
    private:
        bool init       = false;
        bool wall_left  = false;
        bool wall_up    = false;
        bool wall_down  = false;
        bool wall_right = false;
    public:
        Cell();
        Cell(bool visited);
        void setWall(bool up, bool right, bool down, bool left);
        void clearWall();
        bool isVisited();
        void visit();
};

#endif // CELL_H
