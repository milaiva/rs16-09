#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

#include "board.h"
#include "game.h"
#include "player.h"

Game::Game() {
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 780, 580);

    new Board(40, 30, scene);

    int energy = 150;

    this->player = new Player(energy);
    scene->addItem(this->player);

    this->energy = new Energy(energy);
    scene->addItem(this->energy);

    this->setScene(scene);
    this->setFixedSize(800,600);
    this->show();
}

void Game::keyPressEvent(QKeyEvent *event){
    int energy_left = this->player->move(event->key());
    this->energy->update(energy_left);
    qDebug() << "Left:" << energy_left;
}
