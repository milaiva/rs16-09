#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

#include "energy.h"
#include "player.h"

/**
 * @brief The Game class    Sama igra, manipulacija svim objektima i scenama koji su u upotrebi
 */
class Game: public QGraphicsView {
    public:
        Game();                                     // Konstruktor klase
        void keyPressEvent(QKeyEvent * event);      // Reagovanje na pritisak dugmeta
    private:
        Player* player;                             // Igrac
        Energy* energy;                             // Prikaz igraceve energije
        int scene_width = 780;
        int scene_height = 580;
};

#endif // GAME_H
