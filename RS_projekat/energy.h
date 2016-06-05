#ifndef ENERGY_H
#define ENERGY_H

#include <QGraphicsTextItem>

/**
 * @brief The Energy class  Prikaz preostale energije igraca
 */
class Energy : public QGraphicsTextItem {
    private:
        int amount;             // Kolicina preostale energije
    public:
        Energy(int);            // Kontruktor klase
        void update(int);       // Promena energije
};

#endif // ENERGY_H
