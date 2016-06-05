#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "cell.h"
#include <QGraphicsScene>

/**
 * @brief The Board class   Tabla za igru, prazan lavirint
 */
class Board {
    private:
        QGraphicsScene *scene;                                  // Scena na kojoj se lavirint nalazi
        std::vector<Cell*> cells;                               // Celije u okviru table
        std::vector<int> cell_stack;                            // Mrvice za putanju kojom se krecemo

        int width;                                              // Sirina table u broju celija
        int height;                                             // Visina table u broju celija
        int scale = 50;                                         // Skala table (koliko piksela je jedna celija siroka/visoka)
    public:
        Board(int width, int height, QGraphicsScene* scene);    // Konstruktor klase
        Cell* getCell(int x, int y);                            // Dohvatanje zeljene celije
        std::vector<Cell*> getNeighbors(int x, int y);          // Dohvatanje suseda zadate celije
        void move(int x, int y);                                // Kretanje kroz tablu i formiranje lavirinta
};

#endif // BOARD_H
