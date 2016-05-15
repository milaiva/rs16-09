#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    private:
        int direction_x;
        int direction_y;
    public:
        Bullet(int direction_x, int direction_y, int position_x, int position_y);
        ~Bullet();
    public slots:
        void move();
};

#endif // BULLET_H
