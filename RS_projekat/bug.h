#ifndef BUG_H
#define BUG_H


#include <QGraphicsPixmapItem>
#include <QObject>

class Bug: public QObject, public QGraphicsPixmapItem {
   Q_OBJECT
public:
    Bug();
public slots:
    void move();
private:
    int trail_x = 0;
    int trail_y = 0;
};

#endif // BUG_H
