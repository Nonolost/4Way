#ifndef PLATEAUWIDGET_H
#define PLATEAUWIDGET_H

#include <QWidget>
#include "map.h"
#include "position.h"

class plateauWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief plateauWidget::plateauWidget
     * @param parent
     * @param map plateau pour le joueur i
     * @param i
     * @param cp position du joueur
     */
    plateauWidget(QWidget *parent = 0, Tile** map = nullptr,int i=0, CartesianPosition cp=CartesianPosition());

    void changePos(CartesianPosition pos);
public slots:
    /**
     * @brief plateauWidget::movePlayer
     * actualise la position du joueur
     */
    void movePlayer();

signals:

protected:
    /**
     * @brief plateauWidget::changeCase
     * @param list liste des coord' des cases a changer
     * actualise les cases de la liste
     */
    void changeCase(std::vector<int> list);
    /**
     * @brief plateauWidget::paintEvent
     * peind l'ensemble du tableau + le joueur
     */
    void paintEvent(QPaintEvent *event);

private:
    void paintPlayer();
    /**
     * @brief plateauWidget::playerRect
     * @return la zone du joueur
     */
    QRect playerRect();

    int player;
    CartesianPosition pos;
    Tile** tmap;
    std::map<std::string,int> dico;
};

#endif
