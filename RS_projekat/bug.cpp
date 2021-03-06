#include <QDebug>
#include <QTimer>

#include <stdlib.h>
#include <typeinfo>

#include "bug.h"
#include "enemy.h"

Bug::Bug()
{
    this->setPixmap(QPixmap(":/Images/bug.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000);                                        //povecao sam tajmer da bi se realnije kretale
}

void Bug::move(){
    int direction = rand() % 2;

    int modifier_x = direction == 0 ? (rand() % 3 - 1) * 10 : 0;
    int modifier_y = direction == 1 ? (rand() % 3 - 1) * 10 : 0;

    if      (direction == 0 && modifier_x + this->trail_x == 0) this->move();
    else if (direction == 1 && modifier_y + this->trail_y == 0) this->move();

    this->trail_x += modifier_x;
    this->trail_y += modifier_y;


    this->setPos(this->x() + modifier_x, this->y() + modifier_y);

    QList<QGraphicsItem*> colliding_items = this->collidingItems();

    if (colliding_items.size() > 0) {
        for(int i=0, n=colliding_items.size();i<n; ++i){
            if(typeid(*(colliding_items[i]))!=typeid(Bug) && typeid(*(colliding_items[i]))!=typeid(Enemy)){
                this->setPos(this->x() - modifier_x, this->y() - modifier_y);
            }

        }

    }
}
