#ifndef WALL_H
#define WALL_H


#include <QGraphicsRectItem>


class Wall: public QGraphicsRectItem {
    public:
        Wall(int x1,int y1,int x2,int y2);
};

#endif // WALL_H
