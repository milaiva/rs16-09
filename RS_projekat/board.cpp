#include "board.h"
#include "cell.h"
#include <vector>

#include <QDebug>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>

/**
 * @brief Board::Board  Konstruktor klase
 * @param width         Sirina table za igranje
 * @param height        Visina table za igranje
 * @param scene         Scena na kojoj cemo tablu prikazati
 */
Board::Board(int width, int height, QGraphicsScene *scene) {
    int size        = width*height;
    this->width     = width;
    this->height    = height;
    this->scene     = scene;

    // Tabla se sastoji iz kvadratnih celija
    // Informacije o celijama cuvamo u vektoru
    // Iako imamo 2 dimenzije, mozemo koristiti jednodimenzioni vektor, duzine sirina*visina
    for (int i = 0; i < size; i++) {
        this->cells.push_back(new Cell());
    }

    // Formiranje table
    this->move(0, 0);
}

/**
 * @brief Board::getCell    Formiranje table pronalazenjem jednog puta kroz lavirint
 *                          i formiranjem zidova okolo
 * @param x                 x koordinata celije
 * @param y                 y koordinata celije
 * @return                  celija na datoj koordinati
 */
Cell* Board::getCell(int x, int y) {
    int i = y* this->width + x;

    return this->cells[i];
}

/**
 * @brief Board::move       Pomeramo se na datu koordinatu i formiramo tablu tu
 * @param x                 x koordinata celije
 * @param y                 y koordinata celije
 */
void Board::move(int x, int y) {
    // Dohvatamo susedne celije, da bismo videli gde mozemo dalje
    std::vector<Cell*> neg = this->getNeighbors(x, y);

    // Na koju koordinatu cemo sledece preci
    int x_new, y_new;

    // Da li je moguce uopste ici napred, ili se moramo vratiti nazad i probati drugi put
    bool free_cells = false;
    for (unsigned int i = 0; i < neg.size(); i++) {
        if (neg[i]->isVisited() == false) free_cells = true;
    }

    // Dohvatamo celiju na lokaciji i obelezavamo je kao posecenu
    Cell* cell = this->getCell(x, y);
    cell->visit();


    if (free_cells) { // Ukoliko mozemo napred da idemo
        // Pamtimo odakle smo dosli, za slucaj da moramo da se vracamo
        this->cell_stack.push_back(y * this->width + x);

        // Biramo nasumicni smer kretanja medju dostupnim (da celija nije vec posecena)
        int n = rand() % neg.size();
        while (neg[n]->isVisited() == true) {
            n = rand() % neg.size();
        }

        if (n == 0) { // Gore
            x_new = x;
            y_new = y - 1;
        } else if (n == 1) { // Desno
            x_new = x + 1;
            y_new = y;
        } else if (n == 2) { // Dole
            x_new = x;
            y_new = y + 1;
        } else { // Levo
            x_new = x - 1;
            y_new = y;
        }

        // Crtamo liniju izmedju trenutne i prethodne pozicije (tako formiramo zidove lavirinta)
        QGraphicsLineItem *line = new QGraphicsLineItem(x*this->scale, y*this->scale, x_new*this->scale, y_new*this->scale);
        this->scene->addItem(line);

        // I pomeramo se na novu poziciju
        this->move(x_new, y_new);
    } else if (this->cell_stack.size() > 0) { // Ukoliko ne mozemo napred da idemo
        // Dohvatamo prethodnu poziciju, i vracamo se nazad
        int pos = this->cell_stack.back();
        this->cell_stack.pop_back();
        int x_new = pos % this->width;
        int y_new = pos / this->width;
        this->move(x_new, y_new);
    }
}

/**
 * @brief Board::getNeighbors   Dohvatanje susednih celija
 * @param x                     x koordinata celije cije komsije dohvatamo
 * @param y                     y koordinata celije cije komsije dohvatamo
 * @return                      vektor duzine 4, gde je
 *                              0. element sused iznad,
 *                              1. element sused desno,
 *                              2. element sused dole
 *                              3. element sused levo
 */
std::vector<Cell*> Board::getNeighbors(int x, int y) {
    std::vector<Cell*> neighbors;

    // Dohvatamo sve susede, i pri dohvatanju proveravamo oda li je uopste moguce posetiti ga
    // (ako smo, na primer, na poziciji 0, 0, ne mozemo gore i levo, nego samo dole i desno)
    Cell* up        = y > 0 ? this->getCell(x, y-1) : new Cell(true);
    Cell* right     = x < this->width - 1 ? this->getCell(x+1, y) : new Cell(true);
    Cell* bottom    = y < this->height - 1 ? this->getCell(x, y+1) : new Cell(true);
    Cell* left      = x > 0 ? this->getCell(x-1, y) : new Cell(true);

    neighbors.push_back(up);
    neighbors.push_back(right);
    neighbors.push_back(bottom);
    neighbors.push_back(left);

    return neighbors;
}
