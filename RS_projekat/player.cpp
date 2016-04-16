#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>

#include <QDebug>

Player::Player() {
    this->setRect(0,0,20,20); // change the rect from 0x0 (default) to 100x100 pixels
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_A){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_D){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_W){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_S){
        setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
    }
}
