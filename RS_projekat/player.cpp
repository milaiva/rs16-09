#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QDebug>

#include "player.h"

Player::Player(int x, int y) {
    this->setRect(x,y,5,5);
    energy=10;                   //energija se ovde inicijalizuje, stavio sam 10 da bi lakse videli dal radi
}

Player::~Player() {
}


void Player::keyPressEvent(QKeyEvent *event){
    int modifier_x = 0;
    int modifier_y = 0;

    if (event->key() == Qt::Key_A){
        modifier_x = -10;
        energy=energy-1;                          //energija se smanjuje svakim pokretom igraca
    } else if (event->key() == Qt::Key_D){
        modifier_x = 10;
        energy=energy-1;
    } else if (event->key() == Qt::Key_W){
        modifier_y = -10;
        energy=energy-1;
    } else if (event->key() == Qt::Key_S){
        modifier_y = 10;
        energy=energy-1;
    }

    if(energy<=0)   //Ako igrac skroz izgubi energiju, nestaje
        this->Player::~Player();

    this->setPos(x() + modifier_x, y() + modifier_y);

    QList<QGraphicsItem*> colliding_items = this->collidingItems();

    if (colliding_items.size() > 0) {
        this->setPos(this->x() - modifier_x, this->y() - modifier_y);
    }
}
