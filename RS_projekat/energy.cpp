#include "energy.h"

Energy::Energy(int amount) {
    this->amount = amount;
    this->update(amount);
}

void Energy::update(int amount) {
    QString text = "Energija: " + QString::number( amount );

    this->setPlainText(text);
}
