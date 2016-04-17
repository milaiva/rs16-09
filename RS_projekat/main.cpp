#include <QApplication>
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
/*
Tutorial Topics:
-events (keyPressEvent() and QKeyEvent)
-event propogation system
-QDebug
*/

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Player * player = new Player();

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // show the view
    view->show();

    qDebug() << "Radii!";

    return a.exec();
}
