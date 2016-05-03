#include "mapwidget.h"

#include <QPainter>
#include <iostream>
#include <chrono>

MapWidget::MapWidget(QWidget *parent, Tile **map) : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
/*
    for (int i = 0; i < 100; i++)
        std::cout << map[i]->getCouleur() << " " << std::endl;
*/
}

void MapWidget::setPosition(int x, int y)
{
    update();
    emit positionChanged(x, y);
}

void MapWidget::paintEvent(QPaintEvent *)
{
    std::cout << "je vais bien là " << std::endl;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::blue);
    painter.translate(0, rect().height());
    painter.drawPie(QRect(-35, -35, 70, 70), 0, 90 * 16);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    std::cout << "temps : " << duration << std::endl;
}
