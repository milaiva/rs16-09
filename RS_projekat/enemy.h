#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

/**
 * @brief The Enemy class   Protivnik
 */
class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT            // Jer se samostalno krece
public:
    Enemy();            // Konstruktor klase
public slots:
    void move();        // Pomeranje protivnika
private:
    int trail_x = 0;    // Prethodna pozicija x
    int trail_y = 0;    // Prethodna pozicija y
};

#endif // ENEMY_H
