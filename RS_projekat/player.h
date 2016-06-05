#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

/**
 * @brief The Player class      // Igrac
 */
class Player: public QGraphicsPixmapItem{
    private:
        int energy;             // Koliko igrac ima preostale energije, kada padne na 0, on umire
        int step = 5;           // Koliko px ce se pomeriti u svakom koraku

    public:
        Player(int);            // Konstruktor klase
        ~Player();              // Destruktor klase

        int move(int);          // Pomeranje igraca
        int directionX();       // Dohvatanje x smera igraca
        int directionY();       // Dohvatanje y smera igraca
        int decEnergy();        // Smanjujemo preostalu energiju
};

#endif // PLAYER_H
