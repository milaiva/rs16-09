#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem{
    private:
        int energy;  //promenljiva koja pokazuje koliko igrac ima energije, kada padne na 0 , on umire
    public:
        Player();
        void keyPressEvent(QKeyEvent * event);
        ~Player();
};

#endif // PLAYER_H
