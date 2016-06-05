#include <QDebug>
#include <QTimer>

#include <stdlib.h> // rand() -> really large int
#include <typeinfo>

#include "bug.h"
#include "enemy.h"
#include "player.h"

Enemy::Enemy(): QObject(), QGraphicsPixmapItem() {
    this->setPixmap(QPixmap(":/Images/player.png"));
    this->setTransformOriginPoint(22.5,22.5);       // Zadavanje da se rotira oko centra (45x45 mu je velicina)

    this->turn();

    // Pomeranje igraca na svakih 100ms
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}

void Enemy::turn() {
    int dir = rand() % 4;

    if (dir == 1)       { this->trail_x = 1; this->setRotation(90); }
    else if (dir == 3)  { this->trail_x = -1; this->setRotation(-90); }
    else                this->trail_x = 0;

    if (dir == 0)       { this->trail_y = -1; this->setRotation(0); }
    else if (dir == 2)  { this->trail_y = 1; this->setRotation(180); }
    else                this->trail_y = 0;
}

/**
 * @brief Enemy::move       Pomeranje protivnika
 */
void Enemy::move(){
    int modifier_x = this->trail_x * this->step;
    int modifier_y = this->trail_y * this->step;

    if (this->isVisible() == false) qDebug() << "NESTAO";

    this->setPos(this->x() + modifier_x, this->y() + modifier_y);

    // Ukoliko udaramo u nesto, brisemo protivnika
    QList<QGraphicsItem*> colliding_items = this->collidingItems();
    if (colliding_items.size() > 0) {
        for (int i=0, n=colliding_items.size();i<n; ++i) {
            if (typeid(*(colliding_items[i])) != typeid(Bug) && typeid(*(colliding_items[i])) != typeid(Enemy)) {
                this->setPos(this->x() - modifier_x, this->y() - modifier_y);
                this->turn();
            } else if (typeid(*(colliding_items[i])) == typeid(Player)) {

            }

        }
    }
}
