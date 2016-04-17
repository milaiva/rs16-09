#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QDebug>

#include "player.h"

Player::Player() {
    this->setRect(10,10,20,20); // change the rect from 0x0 (default) to 100x100 pixels
}

void Player::keyPressEvent(QKeyEvent *event){
    int modifier_x = 0;
    int modifier_y = 0;

    if (event->key() == Qt::Key_A){
        modifier_x = -10;
    } else if (event->key() == Qt::Key_D){
        modifier_x = 10;
    } else if (event->key() == Qt::Key_W){
        modifier_y = -10;
    } else if (event->key() == Qt::Key_S){
        modifier_y = 10;
    }

    this->setPos(x() + modifier_x, y() + modifier_y);

    QList<QGraphicsItem*> colliding_items = this->collidingItems();

    if (colliding_items.size() > 0) {
        this->setPos(this->x() - modifier_x, this->y() - modifier_y);
    }
}
