#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class Player: public QGraphicsRectItem{
    private:
        int energy;  //promenljiva koja pokazuje koliko igrac ima energije, kada padne na 0 , on umire
    public:
        Player(int x, int y);
        void keyPressEvent(QKeyEvent * event);
        ~Player();
};

#endif // PLAYER_H
