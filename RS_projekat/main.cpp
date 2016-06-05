#include <QApplication>
#include "game.h"

/**
 * @brief main  Pocetna tacka za izvrsavanje igre
 * @param argc  Broj argumenata sa komandne linije
 * @param argv  Argumenti sa komandne linije
 * @return
 */
int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    new Game(); // Pokretanje igre

    return a.exec();
}
