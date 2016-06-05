#include "energy.h"

/**
 * @brief Energy::Energy        Kontruktor klase
 * @param amount                Pocetna kolicina energije
 */
Energy::Energy(int amount) {
    this->amount = amount;
    this->update(amount);
}

/**
 * @brief Energy::update        Promena energije
 * @param amount                Broj koji cemo prikazati kao preostalu energiju
 */
void Energy::update(int amount) {
    QString text = "Energija: " + QString::number( amount );

    this->setPlainText(text);
}
