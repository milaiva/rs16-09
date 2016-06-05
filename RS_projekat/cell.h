#ifndef CELL_H
#define CELL_H

/**
 * @brief The Cell class    Pojedinacna celija u okviru table
 */
class Cell {
    private:
        bool visited = false;   // Da li je celija vec posecena ili ne
    public:
        Cell();                 // Default konstruktor klase
        Cell(bool visited);     // Konstruktor klase gde zadajemo u startu da li je posecena
        bool isVisited();       // Provera da li je celija posecena
        void visit();           // Posecivanje celije
};

#endif // CELL_H
