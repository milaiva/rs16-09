#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

#include "energy.h"
#include "player.h"

class Game: public QGraphicsView {
    public:
        Game();
        void keyPressEvent(QKeyEvent * event);
    private:
        Player* player;
        Energy* energy;
};

#endif // GAME_H
