#ifndef PLATEAUWIDGET_H
#define PLATEAUWIDGET_H

#include <QWidget>
#include "map.h"

class plateauWidget : public QWidget
{
    Q_OBJECT

public:
    plateauWidget(QWidget *parent = 0, Tile** map = nullptr);

    //int angle() const { return currentAngle; }

public slots:
    //void setAngle(int angle);

signals:
    //void angleChanged(int newAngle);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Tile** tmap;
    std::map<std::string,int> dico;
};

#endif
