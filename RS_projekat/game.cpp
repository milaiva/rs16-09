#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <stdlib.h> // rand()

#include "board.h"
#include "bullet.h"
#include "enemy.h"
#include "trap.h"
#include "bug.h"
#include "game.h"
#include "player.h"

/**
 * @brief Game::Game Konstruktor klase, inicijalizacija kompletne igre
 */
Game::Game() {
    // Scena za igru
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, this->scene_width, this->scene_height);

    // Tabla na kojoj se igra odvija
    new Board(40, 30, scene);

    // Pocetna vrednost energije igraca
    int energy = 150;

//    int trap_count =  5;
//    for (int i = 0; i < trap_count; i++) {
//        Trap *trap = new Trap();
//        int pos_x = 50 + (rand() % 14) * 50 + 5;
//        int pos_y = 50 + (rand() % 10) * 50 + 5;

//        trap->setPos(pos_x, pos_y);
//        scene->addItem(trap);
//    }

    this->player = new Player(energy);
    scene->addItem(this->player);

    // Dodavanje natpisa za preostalu energiju
    this->energy = new Energy(energy);
    scene->addItem(this->energy);

    // Dodavanje protivnika
    int enemy_count =  5;
    for (int i = 0; i < enemy_count; i++) {
        Enemy *enemy = new Enemy();
        int pos_x = 50 + (rand() % 14) * 50 + 5;
        int pos_y = 50 + (rand() % 10) * 50 + 5;

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

    // Prikaz same scene igre
    this->setScene(scene);
    this->setFixedSize(800,600);
    this->show();
}

/**
 * @brief Game::keyPressEvent Osluskivac pritiska na taster;
 * U odnosu na to koje je dugme pritisnuto, reagujemo na odgovarajuci nacin
 * @param event
 */
void Game::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    int energy_left = 0;

    if (key == Qt::Key_W || key == Qt::Key_A || key == Qt::Key_S || key == Qt::Key_D) { // WASD pomera igraca
        energy_left = this->player->move(key);
        this->energy->update(energy_left);
    } else if (key == Qt::Key_Space) { // Kada se pritisne Space, ispaljujemo metak
        Bullet *bullet = new Bullet(this->player->directionX(), this->player->directionY(), this->player->x(), this->player->y());
        this->scene()->addItem(bullet);
        energy_left = this->player->decEnergy();
        this->energy->update(energy_left);
    }

    if (this->player->x() < 0 || this->player->x() > this->scene_width || this->player->y() < 0 || this->player->y() > this->scene_height) {
        QGraphicsTextItem *natpis = new QGraphicsTextItem("Pobeda");
        this->scene()->addItem(natpis);
        natpis->setPos(this->scene_width / 2 - 50, this->scene_height / 2 - 30);
        natpis->setTextWidth(500);
    }

    qDebug() << energy_left;

    if (energy_left <= 0) {
        QGraphicsTextItem *natpis = new QGraphicsTextItem("Game over");
        this->scene()->addItem(natpis);
        natpis->setPos(this->scene_width / 2 - 50, this->scene_height / 2 - 30);
        natpis->setTextWidth(500);
    }
}
