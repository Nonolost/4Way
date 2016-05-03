#ifndef PLATEAUWIDGET_H
#define PLATEAUWIDGET_H

#include <QWidget>
#include "map.h"
#include "position.h"

class plateauWidget : public QWidget
{
    Q_OBJECT

public:
    plateauWidget(QWidget *parent = 0, Tile** map = nullptr,int i=0);


public slots:
    void movePlayer();

signals:

protected:
    void changeCase(std::vector<int> list);
    void paintEvent(QPaintEvent *event);

private:
    void paintPlayer();
    QRect playerRect();

    int player;
    CartesianPosition pos;
    Tile** tmap;
    std::map<std::string,int> dico;
};

#endif
