#ifndef PATH_H
#define PATH_H

#include <QGraphicsPolygonItem>
#include <vector>

class Path : public QGraphicsPolygonItem {
    private:
    public:
        Path(int width, int height, int start_x = 0, int start_y = 0, bool branching = true);
    };

#endif // PATH_H
