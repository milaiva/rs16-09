#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <stdlib.h> // rand() -> really large int

#include "board.h"
#include "bullet.h"
#include "enemy.h"
#include "trap.h"
#include "bug.h"
#include "game.h"
#include "player.h"

Game::Game() {
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 780, 580);

    new Board(40, 30, scene);

    int energy = 150;

    //MORAO SAM DA STAVIM OVDE, DA BI IGRAC BIO GRAFICKI IZNAD A NE ISPOD ZAMKI. ZAMKE ZBOG TOGA MORAJU DA SE DODAJU NA SCENU PRE NJEGA
    //VEROVATNO POSTOJI NACIN DA IM SE PROMENI DUBINA(DEPTH), AL OVO JE PRIVREMENO RESENJE
    int trap_count =  5;
    for (int i = 0; i < trap_count; i++) {
        Trap *trap = new Trap();
        int pos_x = 50 + (rand() % 14) * 50 + 5;
        int pos_y = 50 + (rand() % 10) * 50 + 5;

        trap->setPos(pos_x, pos_y);
        scene->addItem(trap);
    }
    //*******************************************************

    this->player = new Player(energy);
    scene->addItem(this->player);

    this->energy = new Energy(energy);
    scene->addItem(this->energy);

    int enemy_count =  5;
    for (int i = 0; i < enemy_count; i++) {
        Enemy *enemy = new Enemy();
        int pos_x = 50 + (rand() % 14) * 50 + 5;
        int pos_y = 50 + (rand() % 10) * 50 + 5;

        qDebug() << QString::number(pos_x) << ";" << QString::number(pos_y);

        enemy->setPos(pos_x, pos_y);
        scene->addItem(enemy);
    }


    int bug_count =  5;
    for (int i = 0; i < bug_count; i++) {
        Bug *bug = new Bug();
        int pos_x = 50 + (rand() % 14) * 50 + 5;
        int pos_y = 50 + (rand() % 10) * 50 + 5;

        bug->setPos(pos_x, pos_y);
        scene->addItem(bug);
    }

    this->setScene(scene);
    this->setFixedSize(800,600);
    this->show();
}

void Game::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    int energy_left = 0;

    if (key == Qt::Key_W || key == Qt::Key_A || key == Qt::Key_S || key == Qt::Key_D) {
        energy_left = this->player->move(key);
        this->energy->update(energy_left);
    } else if (key == Qt::Key_Space) {
        Bullet *bullet = new Bullet(this->player->directionX(), this->player->directionY(), this->player->x(), this->player->y());
        this->scene()->addItem(bullet);
    }

//    qDebug() << "Left:" << energy_left;
}
