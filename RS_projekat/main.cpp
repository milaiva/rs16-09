#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include "board.h"
//#include "path.h"
#include "player.h"
//#include "wall.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);


    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 780, 580);

    Board* b = new Board(40, 30, scene);
    b->move(0, 0);

    Player * player = new Player();
//    Path *path = new Path(800, 600);

//ISCRTAVA OKVIR LAVIRINTA*************************************************************

//    int horizontalna_velicina=80;   //odredjuje koliko ce kockica zida biti sirok lavirint, 80 jer je svaka kockica 10 piksela siroka
//    int vertikalna_velicina=60;     //odredjuje koliko ce kockica zida biti visok lavirint, 60 jer je svaka kockica 10 piksela visoka

//    for(int i=0;i<horizontalna_velicina;i++)
//    {
//        Wall *wall = new Wall(i*10,0);
//        scene->addItem(wall);
//    }
//    for(int i=0;i<vertikalna_velicina;i++)
//    {
//        Wall *wall = new Wall(790,i*10);
//        scene->addItem(wall);
//    }
//    for(int i=0;i<horizontalna_velicina;i++)
//    {
//        Wall *wall = new Wall(i*10,590);
//        scene->addItem(wall);
//    }
//    for(int i=0;i<vertikalna_velicina;i++)
//    {
//        Wall *wall = new Wall(0,i*10);
//        scene->addItem(wall);
//    }
//***************************************************************************************

    scene->addItem(player);
//    scene->addItem(path);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setFixedSize(800,600);
    view->show();


    return a.exec();
}
