#include <QDebug>
#include <QTimer>

#include <stdlib.h> // rand() -> really large int

#include "enemy.h"

Enemy::Enemy(): QObject(), QGraphicsPixmapItem() {
    this->setPixmap(QPixmap(":/Images/player.png"));

    // Pomeranje igraca na svakih 100ms
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

/**
 * @brief Enemy::move       Pomeranje protivnika
 */
void Enemy::move(){
    int direction = rand() % 2; // Nasumicno biramo osu po kojoj ce ici

    // U odnosu na odabranu osu, biramo na koju stranu cemo se pomeriti
    int modifier_x = direction == 0 ? (rand() % 3 - 1) * 10 : 0;
    int modifier_y = direction == 1 ? (rand() % 3 - 1) * 10 : 0;

    // Ako smo odatle dosli, probamo ponovo, da ne bi protivnik isao stalno tamo-vamo
    if      (direction == 0 && modifier_x + this->trail_x == 0) this->move();
    else if (direction == 1 && modifier_y + this->trail_y == 0) this->move();

    this->trail_x += modifier_x;
    this->trail_y += modifier_y;

    this->setPos(this->x() + modifier_x, this->y() + modifier_y);

    // Ukoliko udaramo u nesto, brisemo protivnika
    QList<QGraphicsItem*> colliding_items = this->collidingItems();
    if (colliding_items.size() > 0) {
        this->setPos(this->x() - modifier_x, this->y() - modifier_y);
    }
}
