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

        int decEnergy();        // Smanjujemo preostalu energiju
    public:
        Player(int);            // Konstruktor klase
        ~Player();              // Destruktor klase

        int move(int);          // Pomeranje igraca
        int directionX();       // Dohvatanje x smera igraca
        int directionY();       // Dohvatanje y smera igraca
};

#endif // PLAYER_H
