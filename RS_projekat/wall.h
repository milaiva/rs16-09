#ifndef WALL_H
#define WALL_H


#include <QGraphicsRectItem>
#include<Qline>


class Wall: public QGraphicsRectItem {
    public:
        Wall(int x,int y);
};

#endif // WALL_H
