#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <typeinfo>

#include "bug.h"
#include "enemy.h"
#include "player.h"
#include "trap.h"

#include <QDebug>

/**
 * @brief Player::Player    Konstruktor klase
 * @param energy            Energija koju igrac ima u startu
 */
Player::Player(int energy) {
    setPixmap(QPixmap(":/Images/player_stand.png"));// Zadavanje izgleda igraca
    this->energy = energy;                          // Inicijalizacija energije
    this->setPos(405,305);                          // Pocetna pozicija igraca
    this->setTransformOriginPoint(22.5,22.5);       // Zadavanje da se rotira oko centra (45x45 mu je velicina)
}

Player::~Player() {}                                // Destruktor klase


int Player::move(int key) {                         // Pomeranje igraca
    int modifier_x = 0;                             // Na koju stranu se pomeramo po horizontalnoj osi (-1 levo, 0 nigde, 1 desno)
    int modifier_y = 0;                             // Na koju stranu se pomeramo po vertikalnoj osi (-1 gore, 0 nigde, 1 dole)

    if (key == Qt::Key_A){                          // A -> idemo levo
        modifier_x = -1;
        this->setRotation(-90);
    } else if (key == Qt::Key_D){                   // D -> idemo desno
        modifier_x = 1;
        this->setRotation(90);
    } else if (key == Qt::Key_W){                   // W -> idemo gore
        modifier_y = -1;
        this->setRotation(0);
    } else if (key == Qt::Key_S){                   // S -> idemo dole
        modifier_y = 1;
        this->setRotation(180);
    }

    modifier_x *= this->step;                       // Nova koordinata x
    modifier_y *= this->step;                       // Nova koordinata y

    this->setPos(this->x() + modifier_x, this->y() + modifier_y);

    // Proveravamo da li se igrac sudario sa necime
    QList<QGraphicsItem*> colliding_items = this->collidingItems();

    /*
     * PRI KONTAKTU SA BUBOM, POVECAVA MU SE ENERGIJA ZA 50
     * A PRI KONTAKTU SA NEPRIJATELJEM UMIRE
     * PRI KONTAKTU SA ZAMKOM, SMANJUJE MU SE ENERGIJA BRZO
    */

    for (int i=0, n=colliding_items.size();i<n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Bug)) {
            scene()->removeItem(colliding_items[i]);
            energy += energy;
        } else if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            scene()->removeItem(this);
        } else if (typeid(*(colliding_items[i])) == typeid(Trap)) {
            energy -= energy;
        } else {
            this->setPos(this->x() - modifier_x, this->y() - modifier_y);
        }
    }

    //Ako igrac skroz izgubi energiju, nestaje
    if (this->energy <= 0) this->Player::~Player();
    return this->decEnergy(); // Vracamo preostalu energiju nakon kretanja
}

/**
 * @brief Player::decEnergy     Smanjujemo preostalu energiju
 * @return                      Preostala energija
 */
int Player::decEnergy() {
    return --this->energy;
}

/**
 * @brief Player::directionX    Dohvatanje x smera igraca
 * @return                      -1 za levo i 1 za desno
 */
int Player::directionX() {
    int direction = 0;
    if      (this->rotation() ==  90) direction =  1;
    else if (this->rotation() == -90) direction = -1;
    return direction;
}

/**
 * @brief Player::directionY    Dohvatanje y smera igraca
 * @return                      -1 za gore i 1 za dole
 */
int Player::directionY() {
    int direction = 0;
    if      (this->rotation() ==   0) direction = -1;
    else if (this->rotation() == 180) direction =  1;
    return direction;
}
