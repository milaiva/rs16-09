#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "path.h"
#include "player.h"
#include "wall.h"

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
    scene->setSceneRect(-180, -90, 360, 180);

    // create an item to add to the scene
    Player * player = new Player();
    Wall *wall = new Wall();
    Path *path = new Path(800, 600);

    // add the item to the scene
    scene->addItem(player);
    scene->addItem(wall);
    scene->addItem(path);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // show the view
    view->setFixedSize(800,600);
    view->show();

    return a.exec();
}
