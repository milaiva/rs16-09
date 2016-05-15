#include <QDebug>
#include <QList>
#include <QTimer>

#include "bullet.h"
#include "enemy.h"

Bullet::Bullet(int direction_x, int direction_y, int position_x, int position_y): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/Images/bullet.png"));
    this->direction_x = direction_x;
    this->direction_y = direction_y;
    this->setTransformOriginPoint(22.5,22.5);  //ovim postavljam da se rotira oko centra

    qDebug() << "POS" << position_x << position_y << direction_x << direction_y;

    this->setPos(position_x + direction_x * 20, position_y + direction_y * 20);

    if      (direction_x ==  1) this->setRotation( 90);
    else if (direction_x == -1) this->setRotation(-90);
    else if (direction_y ==  1) this->setRotation(180);
    else if (direction_y == -1) this->setRotation(  0);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
}

Bullet::~Bullet() {
}

void Bullet::move() {
    qDebug() << "AA";

    this->setPos(this->x() + this->direction_x, this->y() + this->direction_y);

    QList<QGraphicsItem*> colliding_items = this->collidingItems();

    if (colliding_items.size() > 0) {
        for (int i = 0; i < colliding_items.size(); i++) {
            if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
                (*colliding_items[i]).~QGraphicsItem();
            }
        }
        this->Bullet::~Bullet();
    }

}
