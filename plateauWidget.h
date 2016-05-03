#ifndef PLATEAUWIDGET_H
#define PLATEAUWIDGET_H

#include <QWidget>
#include "map.h"

class plateauWidget : public QWidget
{
    Q_OBJECT

public:
    plateauWidget(QWidget *parent = 0, Tile** map = nullptr);


public slots:

signals:

protected:
    void changeCase(std::vector<int> list);
    void paintEvent(QPaintEvent *event);

private:
    Tile** tmap;
    std::map<std::string,int> dico;
};

#endif
