#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QDebug>
#include "player.h"

Player::Player(int energy) {
    setPixmap(QPixmap(":/Images/player.png"));
    this->energy = energy;
    this->setPos(405,305);                //ovde se postavlja pocetna pozicija igraca
    this->setTransformOriginPoint(22.5,22.5);  //ovim postavljam da se rotira oko centra
}

Player::~Player() {
}


int Player::move(int key) {
    int modifier_x = 0;
    int modifier_y = 0;

    if (key == Qt::Key_A){
        modifier_x = -1;                                 //malo sam smanjio brzinu kretanja
        this->setRotation(-90);
    } else if (key == Qt::Key_D){
        modifier_x = 1;
        this->setRotation(90);
    } else if (key == Qt::Key_W){
        modifier_y = -1;
        this->setRotation(0);
    } else if (key == Qt::Key_S){
        modifier_y = 1;
        this->setRotation(180);
    }

    modifier_x *= this->step;
    modifier_y *= this->step;

    this->setPos(this->x() + modifier_x, this->y() + modifier_y);

    QList<QGraphicsItem*> colliding_items = this->collidingItems();

    if (colliding_items.size() > 0) {
        this->setPos(this->x() - modifier_x, this->y() - modifier_y);
    }

    //Ako igrac skroz izgubi energiju, nestaje
    if (this->energy <= 0) this->Player::~Player();
    return this->decEnergy();
}

int Player::decEnergy() {
    return --this->energy;
}

int Player::directionX() {
    int direction = 0;
    if (this->rotation() == 90) direction = 1;
    else if (this->rotation() == -90) direction = -1;
    return direction;
}

int Player::directionY() {
    int direction = 0;
    if (this->rotation() == 0) direction = -1;
    else if (this->rotation() == 180) direction = 1;
    return direction;
}
