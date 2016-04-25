#include <QVector>
#include <QPointF>
#include <cstdlib>
#include <QPen>

#include <QDebug>

#include "path.h"

Path::Path(int width, int height, int start_x, int start_y, bool branching) {

//    QVector<QPointF> points;
//    points << QPoint(0, 0);

//    qDebug() << "AA" << branching;

//    int x = start_x;
//    int y = start_y;

//    if (branching == true)  this->setPen(QPen(Qt::green));
//    else                    this->setPen(QPen(Qt::red));

//    while (true) {

//        int rx = rand() % 3 - 1;
//        int ry = rand() % 3 - 1;

//        x += ry == 0 ? rx * 50 : 0;
//        y += rx == 0 ? ry * 50 : 0;

//        points << QPoint(x, y);

//        if (branching == true) new Path(width, height, x, y, false);

//        if (x >= width / 2 || y >= height / 2 || x <= - width / 2 || y <= -height / 2) break;
//    }

//    this->setPolygon(QPolygonF(points));
}
