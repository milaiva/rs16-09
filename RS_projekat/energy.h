#ifndef ENERGY_H
#define ENERGY_H

#include <QGraphicsTextItem>

class Energy : public QGraphicsTextItem {
    private:
        int amount;
    public:
        Energy(int);
        void update(int);
};

#endif // ENERGY_H
