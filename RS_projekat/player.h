#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem{
    private:
        int energy;  //promenljiva koja pokazuje koliko igrac ima energije, kada padne na 0 , on umire
        int step = 5; // Koliko px ce se pomeriti u svakom koraku

        int decEnergy();
    public:
        Player(int);
        ~Player();

        int move(int);
        int directionX();
        int directionY();
};

#endif // PLAYER_H
