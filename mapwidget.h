#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include "tile.h"

class MapWidget : public QWidget
{
    Q_OBJECT

    int currentX, currentY;
    int x() const { return currentX; }
    int y() const { return currentY; }
public:
    MapWidget(QWidget *parent = 0, Tile **map = 0);

public slots:
    void setPosition(int x, int y);

signals:
    void positionChanged(int newX, int newY);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAPWIDGET_H
