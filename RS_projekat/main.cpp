#include <QApplication>
#include "game.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    new Game();

    return a.exec();
}
