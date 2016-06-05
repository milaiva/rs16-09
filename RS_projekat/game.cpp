#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <stdlib.h> // rand()

#include "board.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "player.h"

/**
 * @brief Game::Game Konstruktor klase, inicijalizacija kompletne igre
 */
Game::Game() {
    // Scena za igru
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 780, 580);

    // Tabla na kojoj se igra odvija
    new Board(40, 30, scene);

    // Pocetna vrednost energije igraca
    int energy = 150;

    // Dodavanje igraca
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
    }
}
