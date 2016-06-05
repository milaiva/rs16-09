#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

/**
 * @brief The Bullet class  Metak koji igrac moze da ispali na protivnike
 */
class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT                // Jer klasa poseduje tajmer, metak se sam krece nakon ispaljivanja
    private:
        int direction_x;    // horizontalni    smer kretanja metka (-1 levo, 0 nigde, 1 desno)
        int direction_y;    // Vertikalni      smer kretanja metka (-1 gore, 0 nigde, 1 dole)
    public:
        Bullet(int direction_x, int direction_y, int position_x, int position_y); // Konstruktor
        ~Bullet();          // Destruktor
    public slots:
        void move();        // Pomeranje metka
};

#endif // BULLET_H
